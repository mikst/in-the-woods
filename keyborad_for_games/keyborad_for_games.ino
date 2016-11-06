/*
  State change detection (edge detection)

 ***********************************************************************
 **                                                                   **
 **  The "Bounce" library offers a much easier way to detect changes  **
 **                                                                   **
 ***********************************************************************
 	
 Often, you don't need to know the state of a digital input all the time,
 but you just need to know when the input changes from one state to another.
 For example, you want to know when a button goes from OFF to ON.  This is called
 state change detection, or edge detection.
 
 This example shows how to detect when a button or button changes from off to on
 and on to off.
 	
 The circuit:
 * pushbutton attached to pin 2 from +5V
 * 10K resistor attached to pin 2 from ground
 * LED attached from pin 13 to ground (or use the built-in LED on
   most Arduino boards)
 
 created  27 Sep 2005
 modified 30 Aug 2011
 by Tom Igoe

This example code is in the public domain.
 	
 http://arduino.cc/en/Tutorial/ButtonStateChange
 
 */

// this constant won't change:
const int  buttonPin[] = {6,7,8,9};    // the pin that the pushbutton is attached to


// Variables will change:
int buttonState[4];         // current state of the button
int lastButtonState[4];     // previous state of the button

void setup() {
  for(int i=0; i<4; i++){
  // initialize the button pin as a input:
  pinMode(buttonPin[i], INPUT_PULLUP);
  }
  // initialize serial communication:
  Serial.begin(9600);
}


void loop() {
  // read the pushbutton input pin:
  for(int i=0; i<4; i++){
  buttonState[i] = digitalRead(buttonPin[i]);


  // compare the buttonState to its previous state
  if (buttonState[i] != lastButtonState[i]) {
    // if the state has changed, increment the counter
    if (buttonState[i] == LOW) {
      // if the current state is HIGH then the button
      // wend from off to on:
      if (i==0){
        Keyboard.press(KEY_RIGHT);
        Keyboard.release(KEY_RIGHT);
      }
      if (i==1){
        Keyboard.press(KEY_LEFT);
        Keyboard.release(KEY_LEFT);
      }
      if (i==2){
        Keyboard.press(KEY_UP);
        Keyboard.release(KEY_UP);
      }
      if (i==3){
        Keyboard.press(KEY_DOWN);
        Keyboard.release(KEY_DOWN);
      }
        
    } 
    else {
    }
  }
  // save the current state as the last state, 
  //for next time through the loop
  lastButtonState[i] = buttonState[i];

  }

  delay(10);
}









