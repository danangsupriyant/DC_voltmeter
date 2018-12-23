#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("arducoding.com");
  delay(1000);
  lcd.clear();
}

void loop() {
  // read the input on analog pin 0:
  double sensorValue = analogRead(A0);

  //mapping hasil baca sensor menjadi 0-5V
  sensorValue = mapf(sensorValue, 0, 1023, 0, 5);  
  lcd.setCursor(0,0); // Line 1
  lcd.print("V= "); 
  lcd.print(sensorValue);
  lcd.print(" Volt");
  lcd.setCursor(0,1);  // Line 2
  lcd.print("Active= ");
  lcd.print(millis()/1000);
}

//fungsi mapping untuk tipe data double (dua digit belakang koma)
double mapf(double val, double in_min, double in_max, double out_min, double out_max) {
    return (val - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
