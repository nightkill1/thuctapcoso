#include <Wire.h>
#include "RTClib.h"
RTC_DS1307 rtc;
int time = 100;
//int LP = 12;//11;
//int CP = 8;//9;
//int DP = 11;//12;
int LP = 12;//chan_11_12
int DP  =  8;//chan_12_8
int CP = 11;//chan_14_11
byte leds = 0;

#define A 0
#define B 1
#define C 2
#define D 3
void updateShiftRegister()
{
  digitalWrite(LP, LOW);
  shiftOut(DP, CP, LSBFIRST, leds);
  digitalWrite(LP, HIGH);
}

void setup()
{
  pinMode(LP, OUTPUT);
  pinMode(DP, OUTPUT);
  pinMode(CP, OUTPUT);
  for (int i = 0; i <= 13; i++)
  {
    pinMode(i, OUTPUT);
  }
  //Serial.begin(9600);

  for (int i = 0; i <= 13; i++)
  {
    pinMode(i, OUTPUT);
  }
  if (! rtc.begin())
  {

    Serial.print("Couldn't find RTC");
    while (1);
  }

  if (! rtc.isrunning())
  {

    Serial.print("RTC is NOT running!");
  }

   //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));//auto update from computer time
  //rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));// to set the time manualy

}
void sodonvigiay(int x)
{
  switch (x)
  {
    case 0:
      digitalWrite(A, 0);
      digitalWrite(B, 0);
      digitalWrite(C, 0);
      digitalWrite(D, 0);
      break;
    case 1:
      digitalWrite(A, 1);
      digitalWrite(B, 0);
      digitalWrite(C, 0);
      digitalWrite(D, 0);
      break;
    case 2:
      digitalWrite(A, 0);
      digitalWrite(B, 1);
      digitalWrite(C, 0);
      digitalWrite(D, 0);
      break;
    case 3:
      digitalWrite(A, 1);
      digitalWrite(B, 1);
      digitalWrite(C, 0);
      digitalWrite(D, 0);
      break;
    case 4:
      digitalWrite(A, 0);
      digitalWrite(B, 0);
      digitalWrite(C, 1);
      digitalWrite(D, 0);
      break;
    case 5:
      digitalWrite(A, 1);
      digitalWrite(B, 0);
      digitalWrite(C, 1);
      digitalWrite(D, 0);
      break;
    case 6:
      digitalWrite(A, 0);
      digitalWrite(B, 1);
      digitalWrite(C, 1);
      digitalWrite(D, 0);
      break;
    case 7:
      digitalWrite(A, 1);
      digitalWrite(B, 1);
      digitalWrite(C, 1);
      digitalWrite(D, 0);
      break;
    case 8:
      digitalWrite(A, 0);
      digitalWrite(B, 0);
      digitalWrite(C, 0);
      digitalWrite(D, 1);
      break;
    case 9:
      digitalWrite(A, 1);
      digitalWrite(B, 0);
      digitalWrite(C, 0);
      digitalWrite(D, 1);
      break;
    default:
      digitalWrite(A, 1);
      digitalWrite(B, 0);
      digitalWrite(C, 0);
      digitalWrite(D, 1);
      break;
  }
}
void loop()
{
  DateTime now = rtc.now();
  int gio = now.hour();
  int giodonvi = gio % 10;
  int giochuc = gio / 10;
  int phut = now.minute();
  int phutdonvi = phut % 10;
  int phutchuc = phut / 10;
  int giay = now.second();
  int giaydonvi = giay % 10;
  int giaychuc = giay / 10;


  //sodonvigiay(phutchuc);
  //sodonvigiay(phutdonvi);
  leds = 0;
  updateShiftRegister();
  //delay(time);
  sodonvigiay(giaydonvi);
  
  
  leds = 0;
  for (int i = 0; i < 8; i++) 
  {
            leds = (leds << 1) | 1;      
            digitalWrite(DP, LOW);     
            //ShiftOut ra IC
            shiftOut(CP, LP, MSBFIRST, leds);  
            digitalWrite(DP, HIGH);  //led sang  
            delay(500);
            sodonvigiay(giaychuc); 
  }

  for (int i = 0;i<8;i++) 
  {
            leds =(leds << 1) | 0;       //Đẩy tất cả các bit qua bên trái 1 bit
            digitalWrite(DP, LOW);
            shiftOut(CP, LP, MSBFIRST, leds);  
            digitalWrite(DP, HIGH);
           delay(500);
           sodonvigiay(giaydonvi);
  }  
  
  /*
  for (int i = 0; i < 3; i++)
  {
    if (i == 1)
    {
      sodonvigiay(giaychuc);
      bitSet(leds, i);
      updateShiftRegister();
      //delay(1000);
    }else if(i==2)
    {
      sodonvigiay(giaydonvi);
      bitSet(leds, i);
      updateShiftRegister();
    }else
    //sodonvigiay(giaydonvi);
      
      {
       bitSet(leds, i);
       updateShiftRegister();
      }
      

    //delay(time);

  }*/
}
