const int trafficRedLedPin = 2;
const int trafficOrangeLedPin = 3;
const int trafficGreenLedPin = 4;

const int buttonPin = 5;

const int walkRedLedPin = 6;
const int walkGreenLedPin = 7;


int buttonState = 0;

int memory = LOW;


void setup() {
  // put your setup code here, to run once:
  pinMode(trafficRedLedPin, OUTPUT);
  pinMode(trafficOrangeLedPin, OUTPUT);
  pinMode(trafficGreenLedPin, OUTPUT);

  pinMode(buttonPin, INPUT);

  pinMode(walkRedLedPin, OUTPUT);
  pinMode(walkGreenLedPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(walkRedLedPin, HIGH);

  digitalWrite(trafficRedLedPin, HIGH);
  delay(5000);
  digitalWrite(trafficRedLedPin, LOW);

  for(int i = 1; i <= 3; i++) {
    digitalWrite(trafficOrangeLedPin, HIGH);
    delay(500);
    digitalWrite(trafficOrangeLedPin, LOW);
    delay(500);
  }

  digitalWrite(trafficGreenLedPin, HIGH);
  delay(5000);
  digitalWrite(trafficGreenLedPin, LOW);
  
  buttonState = digitalRead(buttonPin);
  
  if(buttonState != memory && buttonState == HIGH) {
    digitalWrite(walkRedLedPin, LOW);
    digitalWrite(walkGreenLedPin, HIGH);
    delay(3000);
    digitalWrite(walkGreenLedPin, LOW);
  }
  
  memory = buttonState;
}
