
#ifndef _Twizy_TFT_layout_h
#define _Twizy_TFT_layout_h

void drawStatics(void)
{
  char msgString[20], conv1[8];                        // Array to store serial string
  const long line1yPos = SetRel2AbsHeigth(18);
  const long line2yPos = SetRel2AbsHeigth(33);
  const long line3yPos = SetRel2AbsHeigth(75);
  const long lineThickPxl = 3;
 
  /*************** the lines **************/
  tft.fillRect(0, line1yPos,              tft.width(), lineThickPxl, WHITE); 
  tft.fillRect(0, line1yPos+lineThickPxl, tft.width(), lineThickPxl, GRAY); 

  tft.fillRect(0, line2yPos,              tft.width(), lineThickPxl, WHITE); 
  tft.fillRect(0, line2yPos+lineThickPxl, tft.width(), lineThickPxl, GRAY); 

  tft.fillRect(0, line3yPos,              tft.width(), lineThickPxl, WHITE); 
  tft.fillRect(0, line3yPos+lineThickPxl, tft.width(), lineThickPxl, GRAY); 

  tft.fillRect(SetRel2AbsWidth(27), line2yPos+lineThickPxl, lineThickPxl, (line3yPos-line2yPos-lineThickPxl), GRAY);

  /*************** the elements **************/
  tft.setCursor(SetRel2AbsWidth(4),SetRel2AbsHeigth(13));  //reset position after that lines drawing
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


  tft.setCursor(SetRel2AbsHeigth(8),SetRel2AbsHeigth(24));
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
  tft.setCursor(0,tft.getCursorY() + SetRel2AbsHeigth(15));

  
  printmsgBW( " BATT", WHITE );
  tft.setFont(&FreeMonoBold18pt7b);
  tft.setCursor(SetRel2AbsWidth(31),tft.getCursorY());
  dataOnDis.tBatt.xPos = tft.getCursorX();
  dataOnDis.tBatt.yPos = tft.getCursorY();
  dataOnDis.tBatt.disCol = CYAN;
  dataOnDis.tBatt.font = &FreeMonoBold18pt7b; 
  dataOnDis.tBatt.disLen = 3;  dataOnDis.tBatt.disPres = 0;
  printmsgBW( "---", CYAN );
  tft.setFont(&FreeMonoBold9pt7b);
  printmsgBW( "deg", WHITE );
  tft.setCursor(0,tft.getCursorY() + SetRel2AbsHeigth(10));
    
  printmsgBW( " CHG", WHITE );
  tft.setFont(&FreeMonoBold18pt7b);
  tft.setCursor(SetRel2AbsWidth(31),tft.getCursorY());
  dataOnDis.tChg.xPos = tft.getCursorX();
  dataOnDis.tChg.yPos = tft.getCursorY();
  dataOnDis.tChg.disCol = GREEN;
  dataOnDis.tChg.font = &FreeMonoBold18pt7b; 
  dataOnDis.tChg.disLen = 3;  dataOnDis.tChg.disPres = 0;
  printmsgBW( "---", GREEN );
  tft.setFont(&FreeMonoBold9pt7b);
  printmsgBW( "deg", WHITE );
  tft.setCursor(0,tft.getCursorY() + SetRel2AbsHeigth(10));

  printmsgBW( " INV", WHITE );
  tft.setCursor(SetRel2AbsWidth(31),tft.getCursorY());
  tft.setFont(&FreeMonoBold18pt7b);
  dataOnDis.tInv.xPos = tft.getCursorX();
  dataOnDis.tInv.yPos = tft.getCursorY();
  dataOnDis.tInv.disCol = ORANGE;
  dataOnDis.tInv.font = &FreeMonoBold18pt7b; 
  dataOnDis.tInv.disLen = 3;  dataOnDis.tInv.disPres = 0;
  printmsgBW( "---", ORANGE );
  tft.setFont(&FreeMonoBold9pt7b);
  printmsgBW( "deg", WHITE );
  tft.setCursor(0,tft.getCursorY() + SetRel2AbsHeigth(20));


  printmsgBW( " SOC ", WHITE );
  //tft.setCursor(SetRel2AbsWidth(31),tft.getCursorY());
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


#endif //_Twizy_TFT_methods_h
