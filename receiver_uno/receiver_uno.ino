

// These constants won't change.  They're used to give names
// to the pins used:
//#include <SoftwareSerial.h>


int indicatorLED= 2;

int dingPin=14;
int dongPin=15;

boolean ding;
boolean dong;

boolean lastDing;
boolean lastDong;




//SoftwareSerial mySerial(0, 1); // RX, TX

void setup() {  
  pinMode(indicatorLED, OUTPUT);
  pinMode(dingPin, OUTPUT);
  pinMode(dongPin, OUTPUT);
  
  Serial.begin(57600);
}

void loop() {
  if (Serial.available() > 0) {
  // get the new byte   
    int inVal = Serial.read(); 
    Serial.println(inVal);
    
    if (inVal > -1) {
           if (inVal==1){
            ding=true;
            dong=false;
           }
           if (inVal==2){
            ding=false;
            dong=true;
           }
           if (inVal==3){
            ding=false;
            dong=false;
           }
    }    
  }
   
if (lastDing!= ding){
    if (ding){
      // activate the solenoid
    digitalWrite(dingPin,HIGH);
    delay(100);
    digitalWrite(dingPin,LOW);
    
    digitalWrite(indicatorLED,HIGH);
  }
  else { 
    digitalWrite(indicatorLED,LOW);   
  }
}
  
 lastDing=ding;

 if (lastDong!= dong){
    if (dong){
      // activate the solenoid
    digitalWrite(dongPin,HIGH);
    delay(100);
    digitalWrite(dongPin,LOW);
    
    digitalWrite(indicatorLED,HIGH);
  }
  else {
   
    digitalWrite(indicatorLED,LOW);   
  }
}
  
 lastDong=dong;


  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(10);
}

void serialEvent() {
  while (Serial.available()) {   
    // get the new byte:    
    int inVal = Serial.read();  
    Serial.println(inVal);  
    if (inVal > -1) {
           if (inVal==1){
            ding=true;
            dong=false;
           }
           if (inVal==2){
            ding=false;
            dong=true;
           }
           if (inVal==3){
            ding=false;
            dong=false;
           }
    }    
  }
 
}

