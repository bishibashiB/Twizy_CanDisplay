
#ifndef _Twizy_CAN_defs_types_h
#define _Twizy_CAN_defs_types_h

typedef struct 
{
  struct{
    byte chargeCurrentAllowed;
//    word B1_HN :4;
//    word iCurr :12;  //!Endianness!
    byte Byte1;
    byte B2;
    byte phase;
    word SOC;        //!Endianness!
    byte B6;
    byte B7;
  } data;
  byte Id;
  byte DLC;
  byte cycleTime; //10ms/bit
  byte isNew;
} t_Id155;      //sample data 07 97 D0 54 41 A0 00 73
t_Id155 id155 = {{0,0,0,0,0,0,0},0x155, 8, 1, 0};

typedef struct 
{
  struct{
  word B0_1;
  byte actMaxCharge;
  byte actMaxDischarge;
  byte cellTempMin;
  byte accuStat; //SOH
  byte B6;
  byte cellTempMax;
  } data;
  byte Id;
  byte DLC;
  byte cycleTime; //10ms/bit
  byte isNew;
} t_BMS_Id424;  //sample data 11 40 01 23 36 64 00 37
t_BMS_Id424 id424 = {{0,0,0,0,0,0,0},0x424, 8, 10, 0};

typedef struct 
{
  struct{
  byte flags_0x425;
  byte temp_0x425;
  byte B2;
  byte B3;
//  unsigned long B4_2bit    :2;
//  unsigned long AccuV_Copy :15; //!Endianness!
//  unsigned long vCurr      :15;// !Endianness!
  byte B4;
  byte B5;
  byte B6;
  byte B7;
 } data;
  word Id;  
  byte DLC;
  byte cycleTime; //10ms/bit
  byte isNew;
} t_BMS_Id425;    //sample data 2A 3C 44 FF FE 70 01 07
t_BMS_Id425 id425 = {{0,0,0,0,0,0,0,0},0x425, 8, 10, 0};

typedef struct 
{
  struct{
  long B0_3;
//  word engTorque :9; //!Endianness!
//  word B5_bit7   :7;
  byte B4;
  byte B5;
  byte tMot;
  byte B7;
 } data;
  word Id;
  byte DLC;
  byte cycleTime; //10ms/bit
  byte isNew;
} t_BMS_Id196; //sample data 00 FF E7 7F 70 44 0B 00
t_BMS_Id196 id196 = {{0,0,0,0,0},0x196, 8, 10, 0};

typedef struct 
{
  struct{
  long B0_3;
  word B4_5;
  byte B6;
  byte tChg;
 } data;
  word Id;
  byte DLC;
  byte cycleTime; //10ms/bit
  byte isNew;
} t_BMS_Id597;    //sample data 
t_BMS_Id597 id597 = {{0,0,0,0},0x597, 8, 10, 0};

typedef struct 
{
  struct{
  long B0_3;
  byte B4;
  byte tMot;
  byte B6;
  byte B7;
 } data;
  word Id;
  byte DLC;
  byte cycleTime; //10ms/bit
  byte isNew;
} t_BMS_Id59E;  //sample data 00 00 10 FB D4 3D 00 00
t_BMS_Id59E id59E = {{0,0,0,0,0},0x59E, 8, 10, 0};

typedef struct 
{
  struct{
  long B0_3;
  byte B4;
  byte B5;
  byte B6;
  byte B7;
 } data;
  word Id;
  byte DLC;
  byte cycleTime; //10ms/bit
  byte isNew;
} t_BMS_Id55F;  //sample data 00 00 10 FB D4 3D 00 00
t_BMS_Id55F id55F = {{0,0,0,0,0},0x55F, 8, 100, 0};

#endif // _Twizy_CAN_defs_types_h
