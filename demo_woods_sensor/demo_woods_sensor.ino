#include <SoftwareSerial.h>

int sensorValue;
SoftwareSerial mySerial(0, 1); // RX, TX

bool stateOn;
bool lastState;

// the setup routine runs once when you press reset:
void setup() {
  mySerial.begin(57600);
  pinMode(3, INPUT_PULLUP);
  pinMode(2, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  sensorValue = analogRead(A3);
//mySerial.println(sensorValue);


  if (sensorValue < 300) {
    stateOn = true;
  } else {
    stateOn = false;
  }

  if (stateOn != lastState) {
    if (stateOn) {
      mySerial.write(2);
      digitalWrite(2, HIGH);
    }
    else {
      digitalWrite(2, LOW);
      mySerial.write(1);
    }
  }


  delay(10);        // delay in between reads for stability
}
