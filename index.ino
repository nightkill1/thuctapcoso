// Date and time functions using a DS1307 RTC connected via I2C and Wire lib
//A5 <--> SCL DS1307
//A4 <--> SDA DS1307
//RS = 7 Arduino
//E = 6 Arduino
//RW = 0 for Write Data 
//D4 = 5 Arduino
//D5 = 4 Arduino
//D6 = 3 Arduino
//D7 = 2 Arduino
#include <Wire.h>
#include <LiquidCrystal.h>
#include "RTClib.h"

#define A 0
#define B 1
#define C 2
#define D 3
#define BIphutdonvi 8  //10    --- 7
#define RBIphutdonvi 9  //11  ---6
#define BIphutchuc 10    //12  ---9
#define RBIphutchuc 11   //13  ---8
#define BIdonvi 5    //7 ---10
#define RBIdonvi 4   //6 ---11
#define BIchuc 7     //9 ---12
#define RBIchuc 6    //8 ---13

RTC_DS1307 rtc;
LiquidCrystal lcd(10, 11, 12, 13, 0, 1); // (rs, e, d4, d5, d6, d7)

char daysOfTheWeek[7][12] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

void setup () 
{
  //Serial.begin(9600);
  lcd.begin(16, 2);
  for(int i=0;i<=13;i++)
  {
    pinMode(i,OUTPUT);
  }
  if (! rtc.begin()) 
  {
    lcd.print("Couldn't find RTC");
    Serial.print("Couldn't find RTC");
    while (1);
  }

  if (! rtc.isrunning()) 
  {
    lcd.print("RTC is NOT running!");
    Serial.print("RTC is NOT running!");
  }
  
   rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));//auto update from computer time
    //rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));// to set the time manualy 
  
}

void sodonvigiay(int x)
{
  switch(x)
    {
      case 0:
        digitalWrite(A,0);
        digitalWrite(B,0);
        digitalWrite(C,0);
        digitalWrite(D,0);
        break;
      case 1:
        digitalWrite(A,1);
        digitalWrite(B,0);
        digitalWrite(C,0);
        digitalWrite(D,0);
        break;
      case 2:
        digitalWrite(A,0);
        digitalWrite(B,1);
        digitalWrite(C,0);
        digitalWrite(D,0);
        break;
      case 3:
        digitalWrite(A,1);
        digitalWrite(B,1);
        digitalWrite(C,0);
        digitalWrite(D,0);
        break;
      case 4:
        digitalWrite(A,0);
        digitalWrite(B,0);
        digitalWrite(C,1);
        digitalWrite(D,0);
        break;
      case 5:
        digitalWrite(A,1);
        digitalWrite(B,0);
        digitalWrite(C,1);
        digitalWrite(D,0);
        break;
      case 6:
        digitalWrite(A,0);
        digitalWrite(B,1);
        digitalWrite(C,1);
        digitalWrite(D,0);
        break;
      case 7:
        digitalWrite(A,1);
        digitalWrite(B,1);
        digitalWrite(C,1);
        digitalWrite(D,0);
        break;
      case 8:
        digitalWrite(A,0);
        digitalWrite(B,0);
        digitalWrite(C,0);
        digitalWrite(D,1);
        break;
      case 9:
        digitalWrite(A,1);
        digitalWrite(B,0);
        digitalWrite(C,0);
        digitalWrite(D,1);
        break;
        default:
        digitalWrite(A,1);
        digitalWrite(B,0);
        digitalWrite(C,0);
        digitalWrite(D,1);
        break;
    }
}
/*void sochucgiay(int x)
{
  switch(x)
    {
      case 0:
        digitalWrite(A1,0);
        digitalWrite(B1,0);
        digitalWrite(C1,0);
        digitalWrite(D1,0);
        break;
      case 1:
        digitalWrite(A1,1);
        digitalWrite(B1,0);
        digitalWrite(C1,0);
        digitalWrite(D1,0);
        break;
      case 2:
        digitalWrite(A1,0);
        digitalWrite(B1,1);
        digitalWrite(C1,0);
        digitalWrite(D1,0);
        break;
      case 3:
        digitalWrite(A1,1);
        digitalWrite(B1,1);
        digitalWrite(C1,0);
        digitalWrite(D1,0);
        break;
      case 4:
        digitalWrite(A1,0);
        digitalWrite(B1,0);
        digitalWrite(C1,1);
        digitalWrite(D1,0);
        break;
      case 5:
        digitalWrite(A1,1);
        digitalWrite(B1,0);
        digitalWrite(C1,1);
        digitalWrite(D1,0);
        break;
      case 6:
        digitalWrite(A1,0);
        digitalWrite(B1,1);
        digitalWrite(C1,1);
        digitalWrite(D1,0);
        break;
      case 7:
        digitalWrite(A1,1);
        digitalWrite(B1,1);
        digitalWrite(C1,1);
        digitalWrite(D1,0);
        break;
      case 8:
        digitalWrite(A1,0);
        digitalWrite(B1,0);
        digitalWrite(C1,0);
        digitalWrite(D1,1);
        break;
      case 9:
        digitalWrite(A1,1);
        digitalWrite(B1,0);
        digitalWrite(C1,0);
        digitalWrite(D1,1);
        break;
      default:
        digitalWrite(A1,1);
        digitalWrite(B1,0);
        digitalWrite(C1,0);
        digitalWrite(D1,1);
       // break;
    }
}
*/
void loop () 
{
    
    DateTime now = rtc.now();
    int gio = now.hour();
    int giodonvi = gio%10;
    int giochuc = gio/10;
    int phut = now.minute();
    int phutdonvi = phut%10;
    int phutchuc = phut/10;
    int giay = now.second();
    int giaydonvi = giay%10;
    int giaychuc = giay/10;
    Serial.print(now.second());
    digitalWrite(BIchuc,0);
    digitalWrite(RBIchuc,0);
    sodonvigiay(giaychuc);
    digitalWrite(BIchuc,1);
    digitalWrite(RBIchuc,1);
    digitalWrite(BIdonvi,0);
    digitalWrite(RBIdonvi,0);
    sodonvigiay(giaydonvi);
    digitalWrite(BIdonvi,1);
    digitalWrite(RBIdonvi,1);
    //phut
    digitalWrite(BIphutchuc,0);
    digitalWrite(RBIphutchuc,0);
    sodonvigiay(phutchuc);
    digitalWrite(BIphutchuc,1);
    digitalWrite(RBIphutchuc,1);
    digitalWrite(BIphutdonvi,0);
    digitalWrite(RBIphutdonvi,0);
    sodonvigiay(phutdonvi);
    digitalWrite(BIphutdonvi,1);
    digitalWrite(RBIphutdonvi,1);
    


    
     /* sodonvigiay(giaydonvi);
      digitalWrite(BIdonvi,0);digitalWrite(RBIdonvi,0);
      digitalWrite(BIchuc,1);digitalWrite(RBIchuc,1);
      delay(1);
      sodonvigiay(giaychuc);
      digitalWrite(BIchuc,0);digitalWrite(RBIchuc,0);
      digitalWrite(BIdonvi,1);digitalWrite(RBIdonvi,1);
      delay(1);
      */
      
    
    /*
    lcd.setCursor(0, 1);
    lcd.print(now.hour());
    lcd.print(':');
    lcd.print(now.minute());
    lcd.print(':');
    lcd.print(now.second());
    lcd.print("   ");

    lcd.setCursor(0, 0);
    lcd.print(daysOfTheWeek[now.dayOfTheWeek()]);
    lcd.print(" ,");
    lcd.print(now.day());
    lcd.print('/');
    lcd.print(now.month());
    lcd.print('/');
    lcd.print(now.year());
   */
}
