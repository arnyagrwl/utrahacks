#include <Servo.h>
  const int echoPin = 6;
  const int trigPin = 7;
  const int servoPin = 5;
  Servo myServo;
  int val;
  bool run = false;
  

void setup() {
  myServo.attach(servoPin);

  //ultrasonic
  Serial.begin(9600);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  Serial.println("Ultrasonic sensor:");

}

float readSensorData() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  float distance = pulseIn(echoPin, HIGH) / 58.00;  //Equivalent to (340m/s*1us)/2
  return distance;
}

void loop() {
  //servo
  if (run == false) {
    myServo.write(120);
    delay (1000);
    open();
    delay(1000);
    run = false;
  }

  //ultrasonic
  float distance = readSensorData();
  Serial.print(distance);
  Serial.println(" cm");
  delay(100);
}

void open() {
  myServo.write(0);
}


