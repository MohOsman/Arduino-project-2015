String voice;
int waterpump = A0;







//-----------------------------------------------------------------------// 
void setup() {
  Serial.begin(9600);
  pinMode(waterpump, OUTPUT);

}
//-----------------------------------------------------------------------// 
void loop() {
  while (Serial.available()){  //Check if there is an available byte to read
  delay(10); //Delay added to make thing stable
  char c = Serial.read(); //Conduct a serial read
  if (c == '#') {break;} //Exit the loop when the # is detected after the word
  voice += c; //Shorthand for voice = voice + c
  } 
  if (voice.length() > 0) {
    Serial.println(voice);
//-----------------------------------------------------------------------//   
  //----------Control Multiple Pins/ LEDs----------// 
 
 
  //----------Turn On One-By-One----------//
  if(voice == "*hej") {digitalWrite(waterpump, HIGH);}

  //----------Turn Off One-By-One----------//
   if(voice == "*nej") {digitalWrite(waterpump, LOW);}
 
//-----------------------------------------------------------------------// 
voice="";}} //Reset the variable after initiating

