#ifndef _Twizy_TFT_methods_h
#define _Twizy_TFT_methods_h

// Assign human-readable names to some common 16-bit color values: 5/6/5
//colors eg. from https://ee-programming-notepad.blogspot.de/2016/10/16-bit-color-generator-picker.html
#define BLACK   0x0000
#define BLUE    0x001F
#define LIGHTBLUE    0x187F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define PINK    0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
#define ORANGE  0xFE52
#define GRAY    0xC618


void printmsgBW(const char *msg, unsigned int col)
{
    tft.setTextColor(col, BLACK);
    tft.print(msg);
}

void drawStatics(void)
{
  char msgString[20], conv1[8];                        // Array to store serial string
  const byte line1xPos = 67;
  const byte line2xPos = 113;
  const byte line3xPos = 240;
  const byte lineThick = 3;
 
  /*************** the lines **************/
  tft.fillRect(0, line1xPos,           240, lineThick, WHITE); 
  tft.fillRect(0, line1xPos+lineThick, 240, lineThick, GRAY); 

  tft.fillRect(0, line2xPos,           240, lineThick, WHITE); 
  tft.fillRect(0, line2xPos+lineThick, 240, lineThick, GRAY); 

  tft.fillRect(0, line3xPos,           240, lineThick, WHITE); 
  tft.fillRect(0, line3xPos+lineThick, 240, lineThick, GRAY); 

  tft.fillRect(65, line2xPos+lineThick, lineThick, (line3xPos-line2xPos-lineThick), GRAY);

  /*************** the elements **************/
  tft.setCursor(0,fontSizeInc);  //reset position after that lines drawing
  tft.setFont(&FreeMonoBold18pt7b);
  dataOnDis.vCurr.xPos = tft.getCursorX(); 
  dataOnDis.vCurr.yPos = tft.getCursorY(); 
  dataOnDis.vCurr.disCol = WHITE; dataOnDis.vCurr.font = &FreeMonoBold18pt7b; 
  dataOnDis.vCurr.disLen = 4;  dataOnDis.vCurr.disPres = 1;
  printmsgBW(  "--.-V ", WHITE );   
  dataOnDis.iCurr.xPos = tft.getCursorX();
  dataOnDis.iCurr.yPos = tft.getCursorY();
  dataOnDis.iCurr.disCol = WHITE; 
  dataOnDis.iCurr.font = &FreeMonoBold18pt7b; 
  dataOnDis.iCurr.disLen = 4;  dataOnDis.iCurr.disPres = 0;
  printmsgBW(  " ---A", WHITE );   


  tft.println();
  tft.setFont(&FreeMonoBold9pt7b); tft.println();
  dataOnDis.pMaxRecup.xPos = tft.getCursorX();
  dataOnDis.pMaxRecup.yPos = tft.getCursorY();
  dataOnDis.pMaxRecup.disCol = GREEN;
  dataOnDis.pMaxRecup.font = &FreeMonoBold9pt7b; 
  dataOnDis.pMaxRecup.disLen = 4;  dataOnDis.pMaxRecup.disPres = 1;
  printmsgBW( " -.-  ", GREEN );
  dataOnDis.pCurr.xPos = tft.getCursorX();
  dataOnDis.pCurr.yPos = tft.getCursorY();
  dataOnDis.pCurr.disCol = WHITE;
  dataOnDis.pCurr.font = &FreeMonoBold18pt7b; 
  dataOnDis.pCurr.disLen = 4;  dataOnDis.pCurr.disPres = 1;
  tft.setFont(&FreeMonoBold18pt7b);  printmsgBW( "--.-", WHITE );
  tft.setFont(&FreeMonoBold9pt7b);  printmsgBW( "kW ", WHITE );
  dataOnDis.pMaxDrive.xPos = tft.getCursorX();
  dataOnDis.pMaxDrive.yPos = tft.getCursorY();
  dataOnDis.pMaxDrive.disCol = CYAN;
  dataOnDis.pMaxDrive.font = &FreeMonoBold9pt7b; 
  dataOnDis.pMaxDrive.disLen = 4;  dataOnDis.pMaxDrive.disPres = 1;
  printmsgBW( "--.-", CYAN );
  tft.println();  tft.println();  tft.println();

  
  printmsgBW( " BATT", WHITE );
  tft.setFont(&FreeMonoBold18pt7b);
  tft.setCursor(75,tft.getCursorY());
  dataOnDis.tBatt.xPos = tft.getCursorX();
  dataOnDis.tBatt.yPos = tft.getCursorY();
  dataOnDis.tBatt.disCol = CYAN;
  dataOnDis.tBatt.font = &FreeMonoBold18pt7b; 
  dataOnDis.tBatt.disLen = 5;  dataOnDis.tBatt.disPres = 1;
  printmsgBW( "---.-", CYAN );
  tft.setFont(&FreeMonoBold9pt7b);
  printmsgBW( "deg", WHITE );
  tft.println();  tft.println();
    
  printmsgBW( " CHG", WHITE );
  tft.setFont(&FreeMonoBold18pt7b);
  tft.setCursor(75,tft.getCursorY());
  dataOnDis.tChg.xPos = tft.getCursorX();
  dataOnDis.tChg.yPos = tft.getCursorY();
  dataOnDis.tChg.disCol = GREEN;
  dataOnDis.tChg.font = &FreeMonoBold18pt7b; 
  dataOnDis.tChg.disLen = 5;  dataOnDis.tChg.disPres = 1;
  printmsgBW( "---.-", GREEN );
  tft.setFont(&FreeMonoBold9pt7b);
  printmsgBW( "deg", WHITE );
  tft.println();  tft.println();

  printmsgBW( " INV", WHITE );
  tft.setCursor(75,tft.getCursorY());
  tft.setFont(&FreeMonoBold18pt7b);
  dataOnDis.tMot.xPos = tft.getCursorX();
  dataOnDis.tMot.yPos = tft.getCursorY();
  dataOnDis.tMot.disCol = ORANGE;
  dataOnDis.tMot.font = &FreeMonoBold18pt7b; 
  dataOnDis.tMot.disLen = 5;  dataOnDis.tMot.disPres = 1;
  printmsgBW( "---.-", ORANGE );
  tft.setFont(&FreeMonoBold9pt7b);
  printmsgBW( "deg", WHITE );
  tft.println();  tft.println(); tft.println();


  printmsgBW( " SOC ", WHITE );
  //tft.setCursor(75,tft.getCursorY());
  //tft.setFont(&FreeMonoBold18pt7b);
  dataOnDis.SOC.xPos = tft.getCursorX();
  dataOnDis.SOC.yPos = tft.getCursorY();
  dataOnDis.SOC.disCol = YELLOW; 
  dataOnDis.SOC.font = &FreeMonoBold9pt7b; 
  dataOnDis.SOC.disLen = 5;  dataOnDis.SOC.disPres = 2;
  printmsgBW( "--.--", YELLOW );
  tft.setFont(&FreeMonoBold9pt7b);
  printmsgBW( "% ", WHITE );
  printmsgBW( "SOH ", BLUE );
  dataOnDis.SOH.xPos = tft.getCursorX();
  dataOnDis.SOH.yPos = tft.getCursorY();
  dataOnDis.SOH.disCol = BLUE; 
  dataOnDis.SOH.font = &FreeMonoBold9pt7b; 
  dataOnDis.SOH.disLen = 3;  dataOnDis.SOH.disPres = 0;
  printmsgBW( " --%", BLUE );
}

void reDrawEl (disEl_t* El)
{
    if(El->updte == true) {
      char conv1[8];                        // Array to store serial string
      char conv1Formated[8] = "Err";
      
      tft.setFont(El->font);
      dtostrf(El->value, El->disLen, El->disPres, conv1);
      if (El->disLen == 3) {                //need this to get numbers right-alligned w/ fixed length
        sprintf(conv1Formated,"%3s", conv1);      
      } else if (El->disLen == 4) {
        sprintf(conv1Formated,"%4s", conv1);      
      } else if (El->disLen == 5) {
        sprintf(conv1Formated,"%5s", conv1); 
      } 
      tft.setCursor(El->xPos,El->yPos); 
      printmsgBW( conv1Formated, El->disCol );
      El->updte = false;
    }
}

void reDraw(void)
{
  unsigned long tstart, tend;
  char msgString[20], conv1[8];                        // Array to store serial string
  int cx,cy;

  tstart = millis();

  reDrawEl(&dataOnDis.vCurr);
  reDrawEl(&dataOnDis.iCurr);
  reDrawEl(&dataOnDis.pMaxRecup);
  reDrawEl(&dataOnDis.pMaxDrive);
  reDrawEl(&dataOnDis.tBatt);
  reDrawEl(&dataOnDis.tMot);
  reDrawEl(&dataOnDis.tChg);
  reDrawEl(&dataOnDis.SOC);
  reDrawEl(&dataOnDis.SOH);

  if (dataOnDis.pCurr.value >= 0.0) {
    dataOnDis.pCurr.disCol = WHITE;
  }else {
    dataOnDis.pCurr.disCol = GREEN;
  }
  reDrawEl(&dataOnDis.pCurr);

  tend = millis();

  tft.setFont(&FreeMonoBold9pt7b);
  tft.setCursor( 0, 305);

  if(blinky == true) {
    blinky = false;
    sprintf(msgString, " took:%4ums_", tend - tstart);
  } else {
    blinky = true;
    sprintf(msgString, " took:%4ums ", tend - tstart);
  }
  printmsgBW( msgString, WHITE );
}

#endif //_Twizy_TFT_methods_h
