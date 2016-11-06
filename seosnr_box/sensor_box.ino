
// These constants won't change.  They're used to give names
// to the pins used:


int sensorValue1 = 0;        // value read from the pot
int sensorValue2 = 0;        // value read from the pot
int sensorValue3 = 0;        // value read from the pot
int sensorValue4 = 0;        // value read from the pot
int sensorValue5 = 0;        // value read from the pot

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(57600);
}

void loop() {
  // read the analog in value:
  sensorValue1 = analogRead(A2);
  sensorValue2 = analogRead(A3);
  sensorValue3 = analogRead(A4);
  sensorValue4 = analogRead(A5);
  sensorValue5 = analogRead(A6);


  // print the results to the serial monitor:
  Serial.write(byte(0));
  Serial.write(byte(1));
  Serial.print(sensorValue1);
  Serial.println();

  Serial.write(byte(0));
  Serial.write(byte(2));
  Serial.print(sensorValue2);
  Serial.println();

  Serial.write(byte(0));
  Serial.write(byte(3));
  Serial.print(sensorValue3);
  Serial.println();

  Serial.write(byte(0));
  Serial.write(byte(4));
  Serial.print(sensorValue4);
  Serial.println();

   Serial.write(byte(0));
  Serial.write(byte(5));
  Serial.print(sensorValue5);
  Serial.println();

  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(10);
  
  usbMIDI.sendNoteOn(note, velocity, channel)
  usbMIDI.sendNoteOff(note, velocity, channel)
  usbMIDI.sendControlChange(control, value, channel)
}
