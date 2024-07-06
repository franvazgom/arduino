#include <Wire.h>  
#include <LiquidCrystal_I2C.h> // Using version 1.2.1
//NewliquidCrystal_i2c.zip 
//https://naylampmechatronics.com/blog/35_tutorial-lcd-con-i2c-controla-un-lcd-con-solo-dos-pines.html 
//https://www.instructables.com/Soil-Moisture-Measurement-With-Arduino/
// Lectura analog en A0 
// Digital desconectada 
 
// The LCD constructor - address shown is 0x27 - may or may not be correct for yours
LiquidCrystal_I2C lcd(0x3f, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  

void setup()
{
  lcd.begin(16,2); // sixteen characters across - 2 lines
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Inicia.."); 
  lcd.print("-------");
  Serial.println("Inicia");
  Serial.begin(9600);
  pinMode(A0, INPUT); // Humedad 
}
 
void loop()
{ 
  lcd.clear(); 
  lcd.setCursor(0, 0);
  Serial.println("Lectura...");
  lcd.print("Obteniendo lectura"); 
  
  int mois = analogRead(A0);
  Serial.print(mois);
  Serial.print(" - ");
  lcd.setCursor(1, 1);
  lcd.print(mois); 
  lcd.setCursor(0, 0);
  if(mois >= 1000) {
    Serial.println("Sensor is not in the Soil or DISCONNECTED");
    lcd.print("Sensor en suelo :( ");
  }

  if(mois < 1000 && mois >= 600) { 
    Serial.println("Soil is DRY");
    lcd.print("Sensor bajo ");
  }

  if(mois < 600 && mois >= 370) {
    Serial.println("Soil is HUMID");
    lcd.print("Sensor humedo "); 
  }

  if(mois < 370) {
    Serial.println("Sensor in WATER");
    lcd.print("Sensor en agua");
  }                                          

  delay(1500);
}

