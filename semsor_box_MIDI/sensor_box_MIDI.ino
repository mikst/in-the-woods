
// These constants won't change.  They're used to give names
// to the pins used:


int sensorValue1 = 0;        // value read from the pot
int sensorValue2 = 0;        // value read from the pot
int sensorValue3 = 0;        // value read from the pot
int sensorValue4 = 0;        // value read from the pot
int sensorValue5 = 0;        // value read from the pot

int note;
int velocity;
int channel=2;

boolean lastOff;

int lastNote;
int lastOn;

int lastVal1;
int lastVal2;
int lastVal3;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(57600);
}

void loop() {
  // read the analog in value:
  sensorValue1 = analogRead(A2); // 100k pressure sensor
  sensorValue2 = analogRead(A3); // 50k tilt
  sensorValue3 = analogRead(A4); // 1M bend/stretch
  sensorValue4 = analogRead(A5); // 10k light
  sensorValue5 = analogRead(A6); // wind

//---tilt sensor midi play--------
int tiltNote = map(sensorValue2, 200, 650, 0,8);
tiltNote= constrain(tiltNote,0,8);

for (int i=0; i<8; i++){
  if (tiltNote==i && lastNote!=tiltNote){ 
  usbMIDI.sendNoteOff(lastOn, 0, channel);  
  usbMIDI.sendNoteOn(48+i, 127, channel);
    lastOn=48+i;
  } 
}
  
if (sensorValue2<100){
  if (!lastOff){
    for (int i=0; i<8; i++){
     usbMIDI.sendNoteOff(48+i, 0, channel);
     lastOff=true;
      }  
    }
  }
  else lastOff=false;
  
lastNote=tiltNote;
//---------------------------------

//------light sensor-------- 
int val=map (sensorValue4, 200,800,0,127);
val= constrain(val,0,127);

if (val!=lastVal1){
    usbMIDI.sendControlChange(25, val, channel);
}

lastVal1=val;
//---------------------------------

//------pressure sensor-------- 
val=map (sensorValue1, 700,950,0,127);
val= constrain(val,0,127);
if (val!=lastVal2){
    usbMIDI.sendControlChange(26, val, channel);
}

lastVal2=val;
//---------------------------------

//------bend sensor-------- 
val=map (sensorValue3, 458,522,0,64);
val= constrain(val,0,64);
if (val!=lastVal3){
    usbMIDI.sendControlChange(27, val, channel);
}

lastVal3=val;
//---------------------------------



  // print the results to the serial monitor:
//  Serial.write(byte(0));
//  Serial.write(byte(1));
//  Serial.print(sensorValue1);
//  Serial.println();
//
//  Serial.write(byte(0));
//  Serial.write(byte(2));
//  Serial.print(sensorValue2);
//  Serial.println();
//
//  Serial.write(byte(0));
//  Serial.write(byte(3));
//  Serial.print(sensorValue3);
//  Serial.println();
//
//  Serial.write(byte(0));
//  Serial.write(byte(4));
//  Serial.print(sensorValue4);
//  Serial.println();
//
//   Serial.write(byte(0));
//  Serial.write(byte(5));
//  Serial.print(sensorValue5);
//  Serial.println();

  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(10);
  
}
