const int analogInPin = A0;
const int analogOutLedPIn = 9;

int sensorValue = 0;

int outLedValue = 0;

void setup() {
  pinMode(analogInPin, INPUT);
  pinMode(analogOutLedPIn, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(analogInPin);
  //outLedValue = (sensorValue * 255) / 1024;
  outLedValue = map(sensorValue, 0, 1023, 0, 255);

  analogWrite(analogOutLedPIn, outLedValue);

  Serial.print("La valeur du capteur = ");
  Serial.print(sensorValue);
  Serial.print("\t La sortie = ");
  Serial.println(outLedValue);
}