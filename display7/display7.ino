// Tutorial - https://www.xanthium.in/Cross-Platform-serial-communication-using-Python-and-PySerial
int leds[7] = { 9,  5,  6,  3,  4,  7,  8};
//              A   B   C   D   E   F   G

void setup()
{
  //An LED is Connected Pin12 
 for(int i=0; i<7; i++){
    pinMode(leds[i],OUTPUT);  //Make Pin12 Output
    digitalWrite(leds[i], LOW);//Make Pin12 OFF
 }

  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps 8N1

}

void loop()
{
  char RxedByte = 0;
 if (Serial.available()) 
    {
      for(int i=0; i<7; i++){
            digitalWrite(leds[i],LOW);//Make Pin12 OFF
      }
      
      RxedByte = Serial.read();    
       
      switch(RxedByte)
      {
        case '0':  
          for(int i=0; i<6; i++){
            digitalWrite(leds[i],HIGH);//Make Pin12 OFF
          }
        break;
        case '1':  
            digitalWrite(leds[1],HIGH);//Make Pin12 OFF
            digitalWrite(leds[2],HIGH);//Make Pin12 OFF
        break;
        case '2':  
            digitalWrite(leds[0],HIGH);//Make Pin12 OFF
            digitalWrite(leds[1],HIGH);//Make Pin12 OFF
            digitalWrite(leds[3],HIGH);//Make Pin12 OFF
            digitalWrite(leds[4],HIGH);//Make Pin12 OFF
            digitalWrite(leds[6],HIGH);//Make Pin12 OFF
        break;
        case '3':  
            digitalWrite(leds[0],HIGH);//Make Pin12 OFF
            digitalWrite(leds[1],HIGH);//Make Pin12 OFF
            digitalWrite(leds[2],HIGH);//Make Pin12 OFF
            digitalWrite(leds[3],HIGH);//Make Pin12 OFF
            digitalWrite(leds[6],HIGH);//Make Pin12 OFF
        break;
        case '4':  
            digitalWrite(leds[1],HIGH);//Make Pin12 OFF
            digitalWrite(leds[2],HIGH);//Make Pin12 OFF
            digitalWrite(leds[6],HIGH);//Make Pin12 OFF
            digitalWrite(leds[5],HIGH);//Make Pin12 OFF
        break;
         case '5':  
            digitalWrite(leds[0],HIGH);//Make Pin12 OFF
            digitalWrite(leds[2],HIGH);//Make Pin12 OFF
            digitalWrite(leds[3],HIGH);//Make Pin12 OFF
            digitalWrite(leds[5],HIGH);//Make Pin12 OFF
            digitalWrite(leds[6],HIGH);//Make Pin12 OFF
        break;
         case '6':  
            digitalWrite(leds[0],HIGH);//Make Pin12 OFF
            digitalWrite(leds[2],HIGH);//Make Pin12 OFF
            digitalWrite(leds[3],HIGH);//Make Pin12 OFF
            digitalWrite(leds[4],HIGH);//Make Pin12 OFF
            digitalWrite(leds[5],HIGH);//Make Pin12 OFF
            digitalWrite(leds[6],HIGH);//Make Pin12 OFF
        break;
         case '7':  
            digitalWrite(leds[0],HIGH);//Make Pin12 OFF
            digitalWrite(leds[1],HIGH);//Make Pin12 OFF
            digitalWrite(leds[2],HIGH);//Make Pin12 OFF
        break;
        case '8':
          for(int i=0; i<7; i++){
            digitalWrite(leds[i],HIGH);//Make Pin12 OFF
          }
        break;
         case '9':
            digitalWrite(leds[0],HIGH);//Make Pin12 OFF
            digitalWrite(leds[1],HIGH);//Make Pin12 OFF
            digitalWrite(leds[2],HIGH);//Make Pin12 OFF
            digitalWrite(leds[3],HIGH);//Make Pin12 OFF
            digitalWrite(leds[5],HIGH);//Make Pin12 OFF
            digitalWrite(leds[6],HIGH);//Make Pin12 OFF
        break;
        default:
            digitalWrite(leds[0],HIGH);//Make Pin12 OFF
            digitalWrite(leds[5],HIGH);//Make Pin12 OFF
            digitalWrite(leds[4],HIGH);//Make Pin12 OFF
            digitalWrite(leds[3],HIGH);//Make Pin12 OFF
            digitalWrite(leds[6],HIGH);//Make Pin12 OFF
          break;
      }//end of switch()
    }//endof if 
}
      

  