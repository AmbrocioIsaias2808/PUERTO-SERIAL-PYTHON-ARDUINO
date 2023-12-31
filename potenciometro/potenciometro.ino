#include <ArduinoJson.h>

// the setup routine runs once when you press reset:
void setup() {
 
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

float last=0;

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  float voltage= sensorValue * (5.0 / 1023.0);  // 1.2 2.5
  // print out the value you read:
  if(last!=voltage){

  StaticJsonDocument<200> data;
  data["voltage"] = voltage;
  
  if(voltage>4){
    data["alert"]="ALTO VOLTAJE";
    data["color"]="red";
  }else if(voltage <= 4 and voltage>=1.5){
    data["alert"]="VOLTAJE NORMAL";
    data["color"]="green";
  }else{
    data["alert"]="VOLTAGE BAJO";
    data["color"]="orange";
  }


  serializeJson(data, Serial);
  // The above line prints:
  // {"sensor":"gps","time":1351824120,"data":[48.756080,2.302038]}

  // Start a new line
  Serial.println();

  // Generate the prettified JSON and send it to the Serial port.
  //
  //serializeJsonPretty(data, Serial);

  
    
    //Serial.println(voltage);
    last=voltage;
  }
  delay(1000);  // delay in between reads for stability
}
