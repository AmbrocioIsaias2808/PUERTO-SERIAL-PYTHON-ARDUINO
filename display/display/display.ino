#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd (0x27,16,2)  ; // si no te sale con esta direccion  puedes usar (0x3f,16,2) || (0x27,16,2)  ||(0x20,16,2) 

void setup() {

  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps 8N1
  // put your setup code here, to run once:
  lcd.init(); //Indico a arduino que trabajare con un modulo LCD
  lcd.backlight(); //Indico que debe tener encendida la luz de fondo
  lcd.clear(); //Y que antes de cualquier cosa debe limpiar la pantalla
  lcd.setCursor(0,0); //Y colocar el cursor en la primer linea en la primer columna
  lcd.print("HOLA MUNDO SENSUAL");
}

String palabra="";
void loop() {
 

   while (Serial.available()) {
    	  char c = Serial.read();
        palabra += c; 
         delay(2);  
    }
        
      if (palabra.length() >0) {
        lcd.clear(); //Y que antes de cualquier cosa debe limpiar la pantalla
        lcd.setCursor(0,0); //Y colocar el cursor en la primer linea en la primer columna
        lcd.print(palabra);
        palabra="";
  }

       
  
}
