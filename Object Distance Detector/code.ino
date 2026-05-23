// Define Ultrasonic Sensor Pins
const int trigPin = 5;    // Trigger pin connected to GPIO 5
const int echoPin = 18;   // Echo pin connected to GPIO 18

// Variables for calculation
long duration;
float distanceCm;

void setup() {
  // Start the Serial Monitor
  Serial.begin(115200);
  
  // Configure Ultrasonic Pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  

  duration = pulseIn(echoPin, HIGH);
  
  distanceCm = (duration * 0.0343) / 2;
  
  if (distanceCm > 400 || distanceCm < 2) {
    Serial.println("Distance: Out of Range");
  } else {
    Serial.print("Distance: ");
    Serial.print(distanceCm, 1); 
    Serial.println(" cm");
  }
  
  delay(200);
}
