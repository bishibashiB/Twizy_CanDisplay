#ifndef _Twizy_TFT_methods_h
#define _Twizy_TFT_methods_h

#define SetRel2AbsWidth(x)  (((long)x)* (long)tft.width() /100u)
#define SetRel2AbsHeigth(y) (((long)y)* (long)tft.height()/100u)

#ifdef SHOW_MS_PER_FRAME
byte blinky;
#endif

void printmsgBW(const char *msg, unsigned int col)
{
    tft.setTextColor(col, BLACK);
    tft.print(msg);
}

void storePos_setFont(disEl_t* El, const GFXfont *f) {
  //save a little flash by automating this (1%); and yes, there is some overhead in processing
  El->xPos = tft.getCursorX(); 
  El->yPos = tft.getCursorY(); 
  El->font = f; 
  tft.setFont(f);
}

void reDrawEl (disEl_t* El)
{
    if(El->updte == true) {
      char conv1[8];                        // Array to store serial string
      char conv1Formated[8] = "Err";
      
      tft.setFont(El->font);
      dtostrf(El->value, El->disLen, El->disPres, conv1);
      if (El->disLen == 2) {                //need this to get numbers right-alligned w/ fixed length
        sprintf(conv1Formated,"%2s", conv1);      
      } else if (El->disLen == 3) {                
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
  int k;

#ifdef SHOW_MS_PER_FRAME
  unsigned long tstart, tend;
  tstart = millis();
#endif

  //colors oh colors
  if (dataOnDis.pCurr.value >= 0.0) {
    dataOnDis.pCurr.disCol = WHITE;
  }else {
    dataOnDis.pCurr.disCol = GREEN;
  }

  if (dataOnDis.tMot.value >= 100.0) {
    dataOnDis.tMot.disCol = ORANGE;
  }else {
    dataOnDis.tMot.disCol = WHITE;
  }
  if (dataOnDis.tBatt.value < 5.0) {
    dataOnDis.tBatt.disCol = BLUE;
  }else if (dataOnDis.tBatt.value < 15.0) {
    dataOnDis.tBatt.disCol = WHITE;
  }else if (dataOnDis.tBatt.value < 30.0) {
    dataOnDis.tBatt.disCol = GREEN;
  }else {
    dataOnDis.tBatt.disCol = RED;
  }
  if (dataOnDis.tInv.value > 50.0) {
    dataOnDis.tInv.disCol = ORANGE;
  }else {
    dataOnDis.tInv.disCol = WHITE;
  }
  if (dataOnDis.tChg.value > 50.0) {
    dataOnDis.tChg.disCol = ORANGE;
  }else {
    dataOnDis.tChg.disCol = WHITE;
  }

  for(k=0; k<(sizeof(dataOnDis)/sizeof(disEl_t)); k++) {
      reDrawEl( &((disEl_t*)&dataOnDis)[k] );
  }

  
#ifdef SHOW_MS_PER_FRAME
  tend = millis();

  tft.setFont(NULL);
  tft.setCursor( SetRel2AbsWidth(4), SetRel2AbsHeigth(95));
  
  {
    char msgString[40];                        // Array to store serial string

    if(blinky == true) {
      blinky = false;
      sprintf(&msgString[0], " took:%4ums_", tend - tstart);
    } else {
      blinky = true;
      sprintf(&msgString[0], " took:%4ums ", tend - tstart);
    }
    printmsgBW( msgString, WHITE );
  
  }
#endif
}

#endif //_Twizy_TFT_methods_h
