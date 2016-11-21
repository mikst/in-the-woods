

// These constants won't change.  They're used to give names
// to the pins used:
#include <SoftwareSerial.h>

int sensorValue1 = 0;        // value read from the pot
int sensorValue2 = 0;        // value read from the pot

int indicatorLED= 2;


boolean ding;
boolean dong;

boolean lastDing;
boolean lastDong;


SoftwareSerial mySerial(0, 1); // RX, TX

void setup() {  
  pinMode(indicatorLED, OUTPUT);
  mySerial.begin(57600);
}

void loop() {
  // read the analog in value:
  sensorValue1 = analogRead(A2);
  sensorValue2 = analogRead(A3);


if (sensorValue1< 516){
  ding=true;
}
else {
  ding=false;
}

if (lastDing!= ding){
    if (ding){
    mySerial.write(1);
    delay (10);
    mySerial.write(1);
    delay (10);
    mySerial.write(1);
    delay (10);
    digitalWrite(indicatorLED,HIGH);
  }
  else {
    mySerial.write(3);
    delay (10);
    mySerial.write(3);
    delay (10);
    mySerial.write(3);
    delay (10);
    digitalWrite(indicatorLED,LOW);   
  }
}
  
 lastDing=ding;

 if (sensorValue2< 516){
  dong=true;
}
else {
  dong=false;
}

 if (lastDong!= dong){
    if (dong){
    mySerial.write(2);
    delay (10);
    mySerial.write(2);
    delay (10);
    mySerial.write(2);
    delay (10);
    digitalWrite(indicatorLED,HIGH);
  }
  else {
    mySerial.write(3);
    delay (10);
    mySerial.write(3);
    delay (10);
    mySerial.write(3);
    delay (10);
    digitalWrite(indicatorLED,LOW);   
  }
}
  
 lastDong=dong;



  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(10);
}
