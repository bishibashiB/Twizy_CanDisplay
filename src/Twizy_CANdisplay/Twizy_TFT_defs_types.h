#ifndef _Twizy_TFT_defs_types_h
#define _Twizy_TFT_defs_types_h

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
  disEl_t pMaxRecup;//F:  500W, O:
  disEl_t pCurr;    //F:     -, O:
  disEl_t pMaxDrive;//F:  500W, O:
  disEl_t tBatt;     //F:    1, O:-40
  disEl_t tChg;      //F:    1, O: -40
  disEl_t tInv;      //F:    1, O: -40
  disEl_t tMot;      //F:    1, O: -40
  disEl_t SOC;       //F:0.0025%, O:
  disEl_t SOH;       //F:    1, O: 
} tftData_t;
tftData_t dataOnDis;

void printmsgBW(const char *msg, unsigned int col);

#endif //_Twizy_TFT_defs_types_h
