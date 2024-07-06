#include <Wire.h>  
#include <LiquidCrystal_I2C.h> // Using version 1.2.1
//NewliquidCrystal_i2c.zip 
//https://naylampmechatronics.com/blog/35_tutorial-lcd-con-i2c-controla-un-lcd-con-solo-dos-pines.html 

 
// The LCD constructor - address shown is 0x27 - may or may not be correct for yours
LiquidCrystal_I2C lcd(0x3f, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  

void setup()
{
  lcd.begin(16,2); // sixteen characters across - 2 lines
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Hola Mundito!"); 
  lcd.setCursor(8,1);
  lcd.print("-------");
  Serial.begin(115200);
  Serial.println("Inicia");
}
 
long i = 0; 
void loop()
{  
  Serial.println("Inicia vuelta");
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Trabajando...");
  lcd.setCursor(1, 1);
  lcd.print(i++);
  delay(3000);  
}

