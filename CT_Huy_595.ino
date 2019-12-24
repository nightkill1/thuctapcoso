int latchPin = 8;
int clockPin = 12;
int dataPin = 11;

int a = 1 ;
int b = 2;
int c = 4;
int d = 8;
int e = 16;
int f = 32;
void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() {
  // 2 LED DAU
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, a);
  digitalWrite(latchPin, HIGH);

  //delay(500);
  // 2 LED 3,4
  /*
       digitalWrite(latchPin, LOW);
       shiftOut(dataPin, clockPin, MSBFIRST, b);
       digitalWrite(latchPin, HIGH);

    delay(500);*/
  // 2 LED 5,6

  /*      digitalWrite(latchPin, LOW);
      // delay(1000);
        shiftOut(dataPin, clockPin, MSBFIRST, c);
        digitalWrite(latchPin, HIGH);
       delay(500);
  */ /*
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, d);
    digitalWrite(latchPin, HIGH);

  delay(1000);*/
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, e);
  digitalWrite(latchPin, HIGH);
  delay(100);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, f);
  digitalWrite(latchPin, HIGH);
  delay(100);
}
