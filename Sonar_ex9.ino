#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int trigPin = 9;
const int echoPin = 10;

float duration, distance;

const int led = 6;

void setup() {
  // put your setup code here, to run once:

  lcd.begin(16,2);
  lcd.print("Hello, world");
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  //pinMode(LED, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;

  const int k = 2300/1023;
  
  analogRead(distance);
  int change = map(distance, 0, 2300,0,1023);
  analogWrite(led, change);

  lcd.setCursor(0,1);
  lcd.print("The distance is: ");
  lcd.println(distance);
  
  Serial.print("Distance is: ");
  Serial.println(distance);
  delay(100);
}
