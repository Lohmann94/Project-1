#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int fucks = 0;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);

  lcd.print("hello, world!");
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0,1);
  
  lcd.print(millis() / 1000);

  delay(1000);

  lcd.setCursor(0,1);

  lcd.print("Number fucks " + fucks);
  fucks++;

  delay(1000);

  lcd.setCursor(0,1);

  lcd.print("Hey         ");

  delay(1000);
}
