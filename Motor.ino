// Motor A connections
int enA = 0;
int in1 = 1;
int in2 = 2;
// Motor B connections
int enB = 3;
int in3 = 4;
int in4 = 13;

void setup() {
	// Set all the motor control pins to outputs
	pinMode(enA, OUTPUT);
	pinMode(enB, OUTPUT);
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	pinMode(in3, OUTPUT);
	pinMode(in4, OUTPUT);
	
	// Turn off motors - Initial state
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);
}

void loop() {
  //directionControl();
	//speedControl();
	//delay(1000);
  left();
  delay(600);
  turnOff();
  delay(2000);
}

/*
in1 = left motor ground
in2 = left motor v
in3 = right motor v
in4 = right motor ground

*/

// This function lets you control spinning direction of motors
void directionControl() {
	// Set motors to maximum speed
	// For PWM maximum possible values are 0 to 255
	analogWrite(enA, 255);
	analogWrite(enB, 255);

	// Turn on motor A & B
	digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
	digitalWrite(in3, HIGH);
	digitalWrite(in4, LOW);
	delay(2000);
	
	// Now change motor directions
	digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
	digitalWrite(in3, LOW);
	digitalWrite(in4, HIGH);
	delay(2000);
	
	// Turn off motors
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);
}

void forward() {
  digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
	digitalWrite(in3, LOW);
	digitalWrite(in4, HIGH);
}

void backward() {
  digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
	digitalWrite(in3, HIGH);
	digitalWrite(in4, LOW);
}

void right() {
  digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, HIGH);
}

void left() {

  analogWrite(enA, 255);
	analogWrite(enB, 255);

  digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
	digitalWrite(in3, HIGH);
	digitalWrite(in4, LOW);
}

void turnOff() {
  // Turn off motors - Initial state
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);
}


// This function lets you control speed of the motors
// void speedControl() {
// 	// Turn on motors
// 	digitalWrite(in1, LOW);
// 	digitalWrite(in2, HIGH);
// 	digitalWrite(in3, LOW);
// 	digitalWrite(in4, HIGH);
	
	// Accelerate from zero to maximum speed
	// for (int i = 0; i < 256; i++) {
	// 	analogWrite(enA, i);
	// 	analogWrite(enB, i);
	// 	delay(20);
	// }
	
	// // Decelerate from maximum speed to zero
	// for (int i = 255; i >= 0; --i) {
	// 	analogWrite(enA, i);
	// 	analogWrite(enB, i);
	// 	delay(20);
	// }
	
	// // Now turn off motors
	// digitalWrite(in1, LOW);
	// digitalWrite(in2, LOW);
	// digitalWrite(in3, LOW);
	// digitalWrite(in4, LOW);
//}