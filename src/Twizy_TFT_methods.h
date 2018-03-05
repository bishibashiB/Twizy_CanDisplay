#ifndef _Twizy_TFT_methods_h
#define _Twizy_TFT_methods_h



#ifdef SHOW_MS_PER_FRAME
byte blinky;
#endif

void printmsgBW(const char *msg, unsigned int col)
{
    tft.setTextColor(col, BLACK);
    tft.print(msg);
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
  int k;

#ifdef SHOW_MS_PER_FRAME
  tstart = millis();
#endif

  if (dataOnDis.pCurr.value >= 0.0) {
    dataOnDis.pCurr.disCol = WHITE;
  }else {
    dataOnDis.pCurr.disCol = GREEN;
  }
  
  for(k=0; k<(sizeof(dataOnDis)/sizeof(disEl_t)); k++) {
      reDrawEl( &((disEl_t*)&dataOnDis)[k] );
  }

  
#ifdef SHOW_MS_PER_FRAME
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
#endif
}

#endif //_Twizy_TFT_methods_h
