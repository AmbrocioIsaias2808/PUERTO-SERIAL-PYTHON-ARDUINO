
void setup() {

  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps 8N1
  pinMode(13, OUTPUT);

}

String palabra="";
void loop() {
 

   if(Serial.available()) {
    	  char c = Serial.read();
       if(c=='1'){
          digitalWrite(13, HIGH);
       }else{
        digitalWrite(13,LOW);
       }
  }

       
  
}
