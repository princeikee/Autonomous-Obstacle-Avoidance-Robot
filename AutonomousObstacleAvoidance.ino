/* 
  Autonomous Obstacle-Avoidance Robot
  Using Ultrasonic Sensor and Arduino UNO
  Components: 2 DC Gear Motors, L293D Motor Driver, HC-SR04 Ultrasonic Sensor
*/

// Ultrasonic Sensor Pins
const int trigPin = 3;
const int echoPin = 2;

// Left Motor Pins
const int IN1 = 11;
const int IN2 = 10;
const int EN1 = 9;

// Right Motor Pins
const int IN3 = 5;
const int IN4 = 4;
const int EN2 = 6;

long duration;
long distance;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Initialize motor pins as output
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(EN1, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(EN2, OUTPUT);

  // Initialize ultrasonic sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Random start delay to prevent synchronized robot behavior in group setups
  delay(random(500, 2000));
}

void loop() {
  // Measure distance using ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration / 58.2; // Convert to centimeters

  delay(10);

  // Movement logic
  if (distance > 15) {
    // Move forward
    moveForward();
  } 
  else {
    // Obstacle detected: Stop, Reverse, then Turn Left
    stopMotors();
    delay(500);

    reverseMotors();
    delay(500);

    stopMotors();
    delay(500);

    turnLeft();
    delay(500);
  }
}

// Motor control functions

void moveForward() {
  // Left Motor Forward
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(EN1, 255);

  // Right Motor Forward
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(EN2, 255);
}

void reverseMotors() {
  // Left Motor Reverse
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(EN1, 255);

  // Right Motor Reverse
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(EN2, 255);
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void turnLeft() {
  // Spin left: Left Motor moves forward, Right Motor stops
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(EN1, 255);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
