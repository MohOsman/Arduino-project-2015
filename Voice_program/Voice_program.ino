//Coded By: Naresh Lal
//Voice Activated Arduino (Bluetooth + Android)
//Feel free to modify it but remember to give credit
#include <SoftwareSerial.h>
SoftwareSerial mySerial(1, 0); // RX, TX
String voice;
int LED_1 = 12; //Default LED  To Pin #04






//----------------------------------------------------------//  
void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  pinMode(LED_1, OUTPUT); 
  
 }
//-----------------------------------------------------------------------//  
void loop() {

  while (mySerial.available()){  //Check if there is an available byte to read
  delay(10); //Delay added to make thing stable 
  char c = mySerial.read(); //Conduct a serial read
  if (c == '#') {break;} //Exit the loop when the # is detected after the word
  voice += c; //Shorthand for voice = voice + c
  }  
  if (voice.length() > 0) {
    Serial.println(voice); 
//-----------------------------------------------------------------------//    
  //----------Control Multiple Pins/ LEDs----------//  
       if(voice == "*lamp on") {digitalWrite(LED_1, HIGH);}  
  else if(voice == "*lamp off"){digitalWrite(LED_1, LOW); }  
  
//-----------------------------------------------------------------------//  
voice="";}} //Reset the variable after initiating
