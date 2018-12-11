
#ifndef _Twizy_TFT_layout_h
#define _Twizy_TFT_layout_h

void drawStatics(void)
{
  char msgString[20], conv1[8];                        // Array to store serial string
  const long line1yPos = SetRel2AbsHeigth(16);
  const long line2yPos = SetRel2AbsHeigth(35);
  const long line3yPos = SetRel2AbsHeigth(75);
  const long lineThickPxl = 3;

  int test;

  /*************** the lines **************/
  tft.fillRect(0, line1yPos,              tft.width(), lineThickPxl, WHITE); 
  tft.fillRect(0, line1yPos+lineThickPxl, tft.width(), lineThickPxl, GRAY); 

  tft.fillRect(0, line2yPos,              tft.width(), lineThickPxl, WHITE); 
  tft.fillRect(0, line2yPos+lineThickPxl, tft.width(), lineThickPxl, GRAY); 

  tft.fillRect(0, line3yPos,              tft.width(), lineThickPxl, WHITE); 
  tft.fillRect(0, line3yPos+lineThickPxl, tft.width(), lineThickPxl, GRAY); 

  tft.fillRect(SetRel2AbsWidth(33), line2yPos+lineThickPxl, lineThickPxl, (line3yPos-line2yPos-lineThickPxl), GRAY);

  tft.setCursor(SetRel2AbsHeigth(23) ,SetRel2AbsWidth(94));
  tft.setRotation(3); 
  printmsgBW(  "Limits", WHITE );
  tft.setRotation(2);

  /*************** the elements **************/
  tft.setFont(&FreeMonoBold18pt7b); //this alters the CursorPosition
  tft.setCursor(SetRel2AbsWidth(4),SetRel2AbsHeigth(11));  //reset position after that lines drawing
  storePos_setFont(&dataOnDis.vCurr, &FreeMonoBold18pt7b); 
  dataOnDis.vCurr.disCol = WHITE;
  dataOnDis.vCurr.disLen = 4;  dataOnDis.vCurr.disPres = 1;
  printmsgBW(  "--.-V ", WHITE );   
  storePos_setFont(&dataOnDis.iCurr, &FreeMonoBold18pt7b);
  dataOnDis.iCurr.disCol = WHITE;
  dataOnDis.iCurr.disLen = 4;  dataOnDis.iCurr.disPres = 0;
  printmsgBW(  " ---A", WHITE );   
 
  tft.setFont(&FreeMonoBold9pt7b);
  tft.setCursor(SetRel2AbsHeigth(6),SetRel2AbsHeigth(24));
  printmsgBW( "Max ", CYAN );                             
  storePos_setFont(&dataOnDis.pMaxDrive, &FreeMonoBold9pt7b);
  dataOnDis.pMaxDrive.disCol = CYAN;
  dataOnDis.pMaxDrive.disLen = 4;  dataOnDis.pMaxDrive.disPres = 1;
  printmsgBW( "--.-", CYAN );                           
  
  tft.setCursor(SetRel2AbsHeigth(6),SetRel2AbsHeigth(30)); 
  printmsgBW( "Min ", GREEN );
  storePos_setFont(&dataOnDis.pMaxRecup, &FreeMonoBold9pt7b);
  dataOnDis.pMaxRecup.disCol = GREEN;
  dataOnDis.pMaxRecup.disLen = 4;  dataOnDis.pMaxRecup.disPres = 1;
  printmsgBW( " -.-", GREEN );
  
  tft.setCursor(tft.getCursorX()+SetRel2AbsHeigth(5),SetRel2AbsHeigth(30));
  storePos_setFont(&dataOnDis.pCurr, &FreeMonoBold18pt7b);
  dataOnDis.pCurr.disCol = WHITE;
  dataOnDis.pCurr.disLen = 4;  dataOnDis.pCurr.disPres = 1;
  tft.setFont(&FreeMonoBold18pt7b);  printmsgBW( "--.-", WHITE );
  tft.setFont(&FreeMonoBold9pt7b);  printmsgBW( "kW ", WHITE );
  tft.setCursor(0,tft.getCursorY() + SetRel2AbsHeigth(15));
  
  printmsgBW( " BATT", WHITE );
  tft.setFont(&FreeMonoBold18pt7b);
  tft.setCursor(SetRel2AbsWidth(42),tft.getCursorY());
  storePos_setFont(&dataOnDis.tBatt, &FreeMonoBold18pt7b);
  dataOnDis.tBatt.disCol = CYAN;
  dataOnDis.tBatt.disLen = 2;  dataOnDis.tBatt.disPres = 0;
  printmsgBW( "--", CYAN );
  tft.setFont(&FreeMonoBold9pt7b);
  printmsgBW( " deg", WHITE );
  tft.setCursor(0,tft.getCursorY() + SetRel2AbsHeigth(10));
    
  printmsgBW( " CHG", WHITE );
  tft.setFont(&FreeMonoBold18pt7b);
  tft.setCursor(SetRel2AbsWidth(42),tft.getCursorY());
  storePos_setFont(&dataOnDis.tChg, &FreeMonoBold18pt7b);
  dataOnDis.tChg.disCol = GREEN;
  dataOnDis.tChg.disLen = 2;  dataOnDis.tChg.disPres = 0;
  printmsgBW( "--", GREEN );
  tft.setFont(&FreeMonoBold9pt7b);
  printmsgBW( " deg", WHITE );
  tft.setCursor(0,tft.getCursorY() + SetRel2AbsHeigth(10));
   
  printmsgBW( "INV/MOT", WHITE );
  tft.setCursor(SetRel2AbsWidth(42),tft.getCursorY());
  storePos_setFont(&dataOnDis.tInv, &FreeMonoBold18pt7b);
  dataOnDis.tInv.disCol = ORANGE;
  dataOnDis.tInv.disLen = 2;  dataOnDis.tInv.disPres = 0;
  printmsgBW( "--", ORANGE );
  printmsgBW( "/", WHITE );
  storePos_setFont(&dataOnDis.tMot, &FreeMonoBold18pt7b);
  dataOnDis.tMot.disCol = ORANGE;
  dataOnDis.tMot.disLen = 3;  dataOnDis.tMot.disPres = 0;
  printmsgBW( "---", ORANGE );
  tft.setFont(&FreeMonoBold9pt7b);
  tft.setCursor(0,tft.getCursorY() + SetRel2AbsHeigth(20));
   

  printmsgBW( " SOC ", WHITE );
  storePos_setFont(&dataOnDis.SOC, &FreeMonoBold18pt7b);
  dataOnDis.SOC.disCol = YELLOW; 
  dataOnDis.SOC.disLen = 5;  dataOnDis.SOC.disPres = 2;
  printmsgBW( "--.--", YELLOW );
  tft.setFont(&FreeMonoBold9pt7b);
  printmsgBW( "%", WHITE );
  tft.setCursor(0,tft.getCursorY() + SetRel2AbsHeigth(6));
  printmsgBW( " SOH", WHITE );
  storePos_setFont(&dataOnDis.SOH, &FreeMonoBold9pt7b);
  dataOnDis.SOH.disCol = BLUE; 
  dataOnDis.SOH.disLen = 3;  dataOnDis.SOH.disPres = 0;
  printmsgBW( " --", BLUE ); 
  printmsgBW( "%", WHITE );
}


#endif //_Twizy_TFT_methods_h
