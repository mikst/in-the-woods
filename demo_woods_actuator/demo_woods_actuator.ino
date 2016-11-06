#include <SoftwareSerial.h>

int sensorValue;
SoftwareSerial mySerial(0, 1); // RX, TX


// the setup routine runs once when you press reset:
void setup() {
  mySerial.begin(57600);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {

  char buf = mySerial.read();
  byte temp= byte(buf);
  mySerial.println(temp);

  if (temp == 2) {
    digitalWrite(3, HIGH);
  } else {
    digitalWrite(3, LOW);
  }

  delay(10);        // delay in between reads for stability
}
