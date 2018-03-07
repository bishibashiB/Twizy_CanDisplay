
#ifndef _Twizy_TFT_layout_h
#define _Twizy_TFT_layout_h


void drawStatics(void)
{
  char msgString[20], conv1[8];                        // Array to store serial string
  const byte line1yPos = 50;
  const byte line2yPos = 113;
  const byte line3yPos = 240;
  const byte lineThick = 3;
 
  /*************** the lines **************/
  tft.fillRect(0, line1yPos,           240, lineThick, WHITE); 
  tft.fillRect(0, line1yPos+lineThick, 240, lineThick, GRAY); 

  tft.fillRect(0, line2yPos,           240, lineThick, WHITE); 
  tft.fillRect(0, line2yPos+lineThick, 240, lineThick, GRAY); 

  tft.fillRect(0, line3yPos,           240, lineThick, WHITE); 
  tft.fillRect(0, line3yPos+lineThick, 240, lineThick, GRAY); 

  tft.fillRect(80, line2yPos+lineThick, lineThick, (line3yPos-line2yPos-lineThick), GRAY);

  //tft.setFont(&FreeMonoBold18pt7b);
  tft.setRotation(3); 
  tft.setCursor(line1yPos +15 ,228);
  printmsgBW(  "Limits", WHITE );
  tft.setRotation(2); 

  /*************** the elements **************/
  tft.setFont(&FreeMonoBold18pt7b); //this alters the CursorPosition
  tft.setCursor(0,35);  //reset position after that lines drawing
  storePos_setFont(&dataOnDis.vCurr, &FreeMonoBold18pt7b); 
  dataOnDis.vCurr.disCol = WHITE;
  dataOnDis.vCurr.disLen = 4;  dataOnDis.vCurr.disPres = 1;
  printmsgBW(  "--.-V ", WHITE );   
  storePos_setFont(&dataOnDis.iCurr, &FreeMonoBold18pt7b);
  dataOnDis.iCurr.disCol = WHITE;
  dataOnDis.iCurr.disLen = 4;  dataOnDis.iCurr.disPres = 0;
  printmsgBW(  " ---A", WHITE );   
  Serial.print(dataOnDis.vCurr.xPos);Serial.print(" ");Serial.println(dataOnDis.vCurr.yPos);
  Serial.print(dataOnDis.iCurr.xPos);Serial.print(" ");Serial.println(dataOnDis.iCurr.yPos);

  tft.setFont(&FreeMonoBold9pt7b);
  tft.setCursor(20,75);
  printmsgBW( "Max ", CYAN );                             
  storePos_setFont(&dataOnDis.pMaxDrive, &FreeMonoBold9pt7b);
  dataOnDis.pMaxDrive.disCol = CYAN;
  dataOnDis.pMaxDrive.disLen = 4;  dataOnDis.pMaxDrive.disPres = 1;
  printmsgBW( "--.-", CYAN );                           
  
  tft.setCursor(20,95); 
  printmsgBW( "Min ", GREEN );
  storePos_setFont(&dataOnDis.pMaxRecup, &FreeMonoBold9pt7b);
  dataOnDis.pMaxRecup.disCol = GREEN;
  dataOnDis.pMaxRecup.disLen = 4;  dataOnDis.pMaxRecup.disPres = 1;
  printmsgBW( " -.-", GREEN );
  
  tft.setCursor(tft.getCursorX()+10,95);
  storePos_setFont(&dataOnDis.pCurr, &FreeMonoBold18pt7b);
  dataOnDis.pCurr.disCol = WHITE;
  dataOnDis.pCurr.disLen = 4;  dataOnDis.pCurr.disPres = 1;
  tft.setFont(&FreeMonoBold18pt7b);  printmsgBW( "--.-", WHITE );
  tft.setFont(&FreeMonoBold9pt7b);  printmsgBW( "kW ", WHITE );
  tft.println();  tft.println();  tft.println();

  
  printmsgBW( " BATT", WHITE );
  tft.setFont(&FreeMonoBold18pt7b);
  tft.setCursor(100,tft.getCursorY());
  storePos_setFont(&dataOnDis.tBatt, &FreeMonoBold18pt7b);
  dataOnDis.tBatt.disCol = CYAN;
  dataOnDis.tBatt.disLen = 2;  dataOnDis.tBatt.disPres = 0;
  printmsgBW( "--", CYAN );
  tft.setFont(&FreeMonoBold9pt7b);
  printmsgBW( " deg", WHITE );
  tft.println();  tft.println();
    
  printmsgBW( " CHG", WHITE );
  tft.setFont(&FreeMonoBold18pt7b);
  tft.setCursor(100,tft.getCursorY());
  storePos_setFont(&dataOnDis.tChg, &FreeMonoBold18pt7b);
  dataOnDis.tChg.disCol = GREEN;
  dataOnDis.tChg.disLen = 2;  dataOnDis.tChg.disPres = 0;
  printmsgBW( "--", GREEN );
  tft.setFont(&FreeMonoBold9pt7b);
  printmsgBW( " deg", WHITE );
  tft.println();  tft.println();

  printmsgBW( "INV/MOT", WHITE );
  tft.setCursor(100,tft.getCursorY());
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
  tft.println();  tft.println(); tft.println();


  printmsgBW( " SOC ", WHITE );
  storePos_setFont(&dataOnDis.SOC, &FreeMonoBold9pt7b);
  dataOnDis.SOC.disCol = YELLOW; 
  dataOnDis.SOC.disLen = 5;  dataOnDis.SOC.disPres = 2;
  printmsgBW( "--.--", YELLOW );
  tft.setFont(&FreeMonoBold9pt7b);
  printmsgBW( "% ", WHITE );
//  printmsgBW( "SOH ", BLUE );
//  storePos_setFont(&dataOnDis.SOH, &FreeMonoBold9pt7b);
//  dataOnDis.SOH.disCol = BLUE; 
//  dataOnDis.SOH.disLen = 3;  dataOnDis.SOH.disPres = 0;
//  printmsgBW( " --%", BLUE );
}


#endif //_Twizy_TFT_methods_h
