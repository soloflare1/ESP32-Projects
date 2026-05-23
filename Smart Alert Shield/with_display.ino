// Project Name: Smart Alert Shield

// Define the ESP32 pin connections
const int irPin = 13;       // IR Sensor OUT pin
const int redLed = 14;      // Red LED
const int greenLed = 27;    // Green LED
const int buzzerPin = 26;   // Buzzer

void setup() {

  Serial.begin(115200);

  pinMode(irPin, INPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  digitalWrite(redLed, LOW);
  digitalWrite(greenLed, LOW);
  noTone(buzzerPin);

  Serial.println("Smart Alert Shield Activated!");
}

void loop() {

  int sensorState = digitalRead(irPin);

  if (sensorState == LOW) {

    Serial.println("ALERT! Obstacle Detected!");

    digitalWrite(greenLed, LOW);
    digitalWrite(redLed, HIGH);

    tone(buzzerPin, 1000);
    delay(100);
    noTone(buzzerPin);
    delay(100);

  } else {

    Serial.println("Path is Clear.");

    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);

    noTone(buzzerPin);

    delay(200);
  }
}
