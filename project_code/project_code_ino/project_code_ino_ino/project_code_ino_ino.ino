#define RELAY1  7

int waterPump = A0; 
String voice;
  int sensorValue;
 
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
   pinMode(waterPump, OUTPUT);
   digitalWrite(waterPump,  LOW);  
   pinMode(RELAY1, OUTPUT);   
  
}
 // the loop routine runs over and over again forever:
void loop() {
 
  sensorValue = analogRead(A4);
  
  while (Serial.available()){  //Check if there is an available byte to read
  delay(10); //Delay added to make thing stable
  char c = Serial.read(); //Conduct a serial read
  if (c == '#') {break;} //Exit the loop when the # is detected after the word
  voice += c; //Shorthand for voice = voice + c
   sensorValue = analogRead(A4);
  
  Serial.println(sensorValue);
  delay(100);        // delay in between reads for stability
     }
  
  Serial.println(sensorValue);
  delay(100);
  if(sensorValue >200){
    digitalWrite(waterPump, LOW);
     digitalWrite(RELAY1, 1);      
  }
   
if (voice.length() > 0) {
    Serial.println(voice);
 
  if(voice == "*start")
  {
    digitalWrite(waterPump, HIGH);
  }
   
   else if(voice == "*trigga")
   {
     digitalWrite(RELAY1, 1);
   }
   else  if(voice == "*avbryt")
   {
     digitalWrite(RELAY1, 0);
   digitalWrite(waterPump,LOW);
   }
  
 
voice="";}} //Reset the variable after initiating

         
         
  




  
 


