#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int analogInPin = A0;
int analogValue = 0;
float tension = 0.0;
float temaperature = 0.0;

void setup() {
  pinMode(analogInPin, INPUT);
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Temperature");
  
  Serial.begin(9600);
}

void loop() {
  analogValue = analogRead(analogInPin);
  tension = (analogValue * 5.0) / 1023;
  temaperature = analogValue / 2.056;
  
  lcd.setCursor(0,1);
  lcd.print(temaperature);
  
  Serial.print("Capteur=");
  Serial.print(analogValue);
  Serial.print(" | Tesion=");
  Serial.print(tension);
  Serial.print(" | Temperatue=");
  Serial.print(temaperature);
  Serial.println(" Celsium");
  
  delay(500);
}