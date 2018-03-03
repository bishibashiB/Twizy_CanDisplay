
 /**
 * ==========================================================================
 * Twizy CAN display: working version
 * ==========================================================================
 * 
 * - The attached sources shall give you an example of reading CAN data from Twizy CAN 
 *   (or any ceh can) and display this on a display. 
 *  Please note that there are separations intended in future updates to differ a 
 *  TFT display layout code parts from the CAN data acquisition. 
 *  To the time being this separation is not given.
 *  However if a separation is working, several display layouts can be exchange AND a maintained 
 *  core functionality can be ensured over different layouts.
 * Author: Bernd Eickhoff <b.eickhoff@gmx.de>
 * 
 * Thanks to the Twizy Forum and everyone supporting to Twizy! 
 * I know there are a lot to mention but allow me to only pick this up: special Thanks to 
 * Michael Balzer for his outstanding contribution to making the Twizy a sooo nice toy ;P !
 * Twizy CAN object dictionary:
 * https://docs.google.com/spreadsheets/d/1gOrG9rnGR9YuMGakAbl4s97a6irHF6UNFV1TS5Ll7MY/edit#gid=0
 * (Maintainer: Michael Balzer <dexter@dexters-web.de>)
 * 
 * Libraries used:
 *  - MCP_CAN: https://github.com/coryjfowler/MCP_CAN_lib
 *  - TimerOne: https://github.com/PaulStoffregen/TimerOne
 *  - MCUFRIEND_kbv: https://github.com/prenticedavid/MCUFRIEND_kbv
 *  - _custom version_ of Adafruit-GFX-Library https://github.com/adafruit/Adafruit-GFX-Library
 *        (-> custom font _incl._ background colour, exact reference follows)
 * Licenses:
 *  This is free software and information under the following licenses:
 *  - Source code: GNU Lesser General Public License (LGPL)
 *    https://www.gnu.org/licenses/lgpl.html
 *  - Documentation: GNU Free Documentation License (FDL)
 *    https://www.gnu.org/licenses/fdl.html
 */

#include <mcp_can.h>
#include "Twizy_CAN_defs_types.h"
#include <SPI.h>

//TFT stuff
#define LCD_CS A3 // Chip Select 
#define LCD_CD A2 // Command/Data
#define LCD_WR A1 // LCD Write 
#define LCD_RD A0 // LCD Read 
#define LCD_RESET A4 // Can alternately just connect to Arduino's reset pin

#include <SPI.h>          // f.k. for Arduino-1.5.2
#include "Adafruit_GFX.h"// Hardware-specific library
#include <MCUFRIEND_kbv.h>
#include <Fonts\FreeMonoBold9pt7b.h>
//#include <Fonts\FreeMonoBold12pt7b.h>
#include <Fonts\FreeMonoBold18pt7b.h>

#include <TimerOne.h>
// draw update 1s
#define TFT_UPDATE_US        1000000

MCUFRIEND_kbv tft;
//#include <Adafruit_TFTLCD.h>
//Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);


//colors eg. from https://ee-programming-notepad.blogspot.de/2016/10/16-bit-color-generator-picker.html


#ifndef min
#define min(a, b) (((a) < (b)) ? (a) : (b))
#endif


#define CAN0_INT 2                              // Set INT to pin 2
MCP_CAN CAN_Instance(10);                       // Set CS to pin 10

unsigned long lastLoopMillis = 0;
byte tftClockRang = true;
const byte fontSizeInc = 42;
byte blinky;

typedef struct
{
  float value;
  byte updte;
  //from here only init values
  byte disLen;  //string conversion rules
  byte disPres; //string conversion rules
  byte offset;  //twizyCAN TODO
  float factor; //twizyCAN TODO
  word xPos;
  word yPos;
  const GFXfont* font;
  word disCol;    
} disEl_t;

typedef struct 
{
  disEl_t vCurr;    //F:  0.2V, O:
  disEl_t iCurr;    //F: 0.25A, O:-500
  disEl_t pMaxRecup;//F: 500W, O:
  disEl_t pCurr;    //F:    -, O:
  disEl_t pMaxDrive;//F: 500W, O:
  disEl_t tBatt;     //F:   1, O:-40
  disEl_t tChg;      //F:   1, O: -40
  disEl_t tMot;      //F:   1, O: -40
  disEl_t SOC;       //F:0.0025%, O:
  disEl_t SOH;       //F:    1, O: 
} tftData_t;
tftData_t dataOnDis;

//few defines used, so include is 'late'
#include "Twizy_TFT_methods.h"


void printmsgBW(const char *msg, unsigned int col);
void reDraw(void);

void tftClockISR() {
  tftClockRang = true;
}

void checkTftRedraws(void)
{
  int cellTempAvg;
  word endianHelpi;
  
  /*********** ID425 ******************/
  //this voltage is not the prefered one
//  endianHelpi = ((id425.data.B6 & 0x3F) <<8) + id425.data.B7;
//  if (dataOnDis.vCurr.value != (endianHelpi/5.0f) )  {
//     dataOnDis.vCurr.value = (endianHelpi/5.0f);
//     dataOnDis.vCurr.updte = true;
//     dataOnDis.pCurr.value = (dataOnDis.vCurr.value * dataOnDis.iCurr.value)/1000;
//     dataOnDis.pCurr.updte = true;
//  }
  
  /*********** ID424 ******************/
  if (dataOnDis.pMaxRecup.value != (id424.data.actMaxCharge/2.0f) )  {
     dataOnDis.pMaxRecup.value = (id424.data.actMaxCharge/2.0f);
     dataOnDis.pMaxRecup.updte = true;
  }
  if (dataOnDis.pMaxDrive.value != (id424.data.actMaxDischarge/2.0f) )  {
     dataOnDis.pMaxDrive.value = (id424.data.actMaxDischarge/2.0f);
     dataOnDis.pMaxDrive.updte = true;
  }
  cellTempAvg = (id424.data.cellTempMin + id424.data.cellTempMax )/2 -40;
  if (dataOnDis.tBatt.value != cellTempAvg )  {
     dataOnDis.tBatt.value = cellTempAvg;
     dataOnDis.tBatt.updte = true;
  }
    if (dataOnDis.SOH.value != (id424.data.accuStat) )  {
     dataOnDis.SOH.value = id424.data.accuStat;
     dataOnDis.SOH.updte = true;
  }

  /*********** ID155 ******************/
  endianHelpi = ((id155.data.Byte1 & 0xF) <<8) + id155.data.B2; 
  if (dataOnDis.iCurr.value != (endianHelpi/-4.0f+500.0) )  {
     dataOnDis.iCurr.value = (endianHelpi/-4.0f+500.0);
     dataOnDis.iCurr.updte = true;
     dataOnDis.pCurr.value = (dataOnDis.vCurr.value * dataOnDis.iCurr.value)/1000;
     dataOnDis.pCurr.updte = true;
  }
  endianHelpi = ((id155.data.SOC & 0xFF) <<8) + ((id155.data.SOC & 0xFF00) >>8); 
  if (dataOnDis.SOC.value != (endianHelpi/400.0f) )  {
     dataOnDis.SOC.value = (endianHelpi/400.0f);
     dataOnDis.SOC.updte = true;
  }

  /*********** ID597 ******************/
  if (dataOnDis.tChg.value != (id597.data.tChg -40) )  {
     dataOnDis.tChg.value = (id597.data.tChg -40);
     dataOnDis.tChg.updte = true;
  }
  /*********** ID59E ******************/
  if (dataOnDis.tMot.value != (id59E.data.tMot -40) )  {
     dataOnDis.tMot.value = (id59E.data.tMot -40);
     dataOnDis.tMot.updte = true;
  }
  /*********** ID55F ******************/
  endianHelpi = ((id55F.data.B6 & 0xF) <<8) + id55F.data.B7; 
  if (dataOnDis.vCurr.value != (endianHelpi/10.0f) )  {
     dataOnDis.vCurr.value = (endianHelpi/10.0f);
     dataOnDis.vCurr.updte = true;
     dataOnDis.pCurr.value = (dataOnDis.vCurr.value * dataOnDis.iCurr.value)/1000;
     dataOnDis.pCurr.updte = true;
  }

}
  
void setup()
{
  Serial.begin(9600);
  
  // Initialize MCP2515 running at 16MHz with a baudrate of 500kb/s and the masks and filters disabled.
  if(CAN_Instance.begin(MCP_ANY, CAN_500KBPS, MCP_16MHZ) == CAN_OK)
    Serial.println("MCP2515 Initialized Successfully!");
  else
    Serial.println("Error Initializing MCP2515...");
  
  CAN_Instance.setMode(MCP_NORMAL);                     // Set operation mode to normal so the MCP2515 sends acks to received data.

  pinMode(CAN0_INT, INPUT);                            // Configuring pin for /INT input


  /************** TFT stuff *************/
  Timer1.initialize(TFT_UPDATE_US);
  Timer1.attachInterrupt(tftClockISR);

  uint16_t ID = tft.readID(); 
  tft.begin(ID);
  //tft.invertDisplay(true); this is pixel base
  tft.setRotation(2); //0-3
  tft.fillScreen(BLACK);

  //init values (formulas with offset)
  dataOnDis.tBatt.value = -40;
  dataOnDis.tChg.value = -40;
  dataOnDis.tMot.value = -40;
  dataOnDis.iCurr.value = 500;
 
  drawStatics();
}

void loop()
{

  if(!digitalRead(CAN0_INT))                         // If CAN0_INT pin is low, read receive buffer
  {
    long unsigned int rxId;
    unsigned char len = 0;
    unsigned char rxBuf[8];

    CAN_Instance.readMsgBuf(&rxId, &len, rxBuf);      // Read data: len = data length, buf = data byte(s)

    //sprintf(msgString, "Standard ID: 0x%.3lX       DLC: %1d  Data:", rxId, len);
    //Serial.print(msgString);

    if(rxId == 0x424){
      //sprintf(msgString, " 0x%.2X", rxBuf[i]);
      //Serial.print(msgString);
      for(byte i = 0; i<len; i++){
        ((char*)&id424.data)[i] = rxBuf[i];
      }
      id424.DLC = len;
      id424.isNew = true;
    }
    if(rxId == 0x425){
      for(byte i = 0; i<len; i++){
        ((char*)&id425.data)[i] = rxBuf[i];
      }
      id425.DLC = len;
      id425.isNew = true;
    }
    if(rxId == 0x155){
      for(byte i = 0; i<len; i++){
        ((char*)&id155.data)[i] = rxBuf[i];
      }
      id155.DLC = len;
      id155.isNew = true;
    }
    if(rxId == 0x196){
    for(byte i = 0; i<len; i++){
      ((char*)&id196.data)[i] = rxBuf[i];
    }
      id196.DLC = len;
      id196.isNew = true;
    }
    if(rxId == 0x597){
    for(byte i = 0; i<len; i++){
      ((char*)&id597.data)[i] = rxBuf[i];
    }
      id597.DLC = len;
      id597.isNew = true;
    }
    if(rxId == 0x59E){
    for(byte i = 0; i<len; i++){
      ((char*)&id59E.data)[i] = rxBuf[i];
    }
      id59E.DLC = len;
      id59E.isNew = true;
    }
    if(rxId == 0x55F){
    for(byte i = 0; i<len; i++){
      ((char*)&id55F.data)[i] = rxBuf[i];
    }
      id55F.DLC = len;
      id55F.isNew = true;
    }
  }
  
  if(tftClockRang)
  { 
    tftClockRang = false;
    checkTftRedraws();
    reDraw();
  }
}



