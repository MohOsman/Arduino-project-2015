#define RELAY1  7

String voice;
int waterPump = A0;
int sensorValue;







//-----------------------------------------------------------------------// 
void setup() {
  Serial.begin(9600);
  pinMode(waterPump, OUTPUT); // for the water 
  pinMode(RELAY1, OUTPUT);

  
 
  

  


}
//----------------------------- VOICE ------------------------------------------// 
void loop() {
  


  ;

  while (Serial.available()){  //Check if there is an available byte to read
  delay(10); //Delay added to make thing stable
  char c = Serial.read(); //Conduct a serial read
  if (c == '#') {break;} //Exit the loop when the # is detected after the word
  voice += c; //Shorthand for voice = voice + c
    sensorValue = analogRead(A4);
  }    
     Serial.println(sensorValue);
     delay(100);
     
  if (voice.length() > 0) {
    Serial.println(voice);
   

//-----------------------------------------------------------------------//   
  //----------Control Multiple Pins/ LEDs----------// 
 
  //


  if(voice == "*hej") {
  }
     
     


   if(voice == "*avbryt") 
   {digitalWrite(RELAY1, 0);
   digitalWrite(waterPump,LOW)
 ;}
 
//-----------------------------------------------------------------------// 
voice="";}} //Reset the variable after initiating

