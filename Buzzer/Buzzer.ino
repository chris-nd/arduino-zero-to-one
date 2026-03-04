const int ledPin = 13;
const int lightPin = A2;
const int buzzerPin = 8;

int sensorValue;
int inLedValue;
int inBuzzerValue;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(lightPin, INPUT);
  pinMode(buzzerPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(lightPin);
  inLedValue = map(sensorValue, 0, 1023, 0, 255);
  inBuzzerValue = map(sensorValue, 0, 1023, 50, 30000);

  analogWrite(ledPin, inLedValue);
  tone(buzzerPin, inBuzzerValue);

  Serial.print("La valeur du capteur = ");
  Serial.print(sensorValue);
  Serial.print(" | [LED] = ");
  Serial.print(inLedValue);
  Serial.print(" | [BUZZER] = ");
  Serial.println(inBuzzerValue);
}
