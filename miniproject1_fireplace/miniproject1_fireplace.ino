
// Mini Group Project 1 
// Members: Kyungchan Lim, Lu Liu

/*
  Ultrasonic Sensor HC-SR04 and Arduino Tutorial

  by Dejan Nedelkovski,
  www.HowToMechatronics.com

*/
// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
// defines variables
long duration;
int distance;
void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
  pinMode(A3,OUTPUT); // Sets the pin for 8x8 LED matrix
  pinMode(A4,OUTPUT);
  pinMode(A5,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
}

// turn off all the lights in the matrix
void lightNone() {
  digitalWrite(A3, LOW);
  digitalWrite(A4, LOW);
  digitalWrite(A5, LOW);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
}

// turn on all lights in the matrix (to test if the light works)
void lightAll() {
  digitalWrite(A3, HIGH);
  digitalWrite(A4, HIGH);
  digitalWrite(A5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
}

// define row 1
void row1() {
  digitalWrite(A3, HIGH);
}

// define row 2
void row2() {
  digitalWrite(A4, HIGH);
}

// define row 3
void row3() {
  digitalWrite(A5, HIGH);
}

// define row 4
void row4() {
  digitalWrite(2, HIGH);
}

// define row 5
void row5(){
  digitalWrite(3, HIGH);
}

// define row 6
void row6(){
  digitalWrite(4, HIGH);
}

// define row 7
void row7(){
  digitalWrite(5, HIGH);
}

// define row 8
void row8(){
  digitalWrite(6, HIGH);
}

// start the loop
void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);

  // with the if statement, we calculate distance and display rows of lights. physical connection of the row is different than logical row.
  if (0 < distance && distance <= 3) {
    row3();
    // row1
  }
  else if (3 < distance && distance <= 5) {
    row8();
    // row2
  }
  else if (5 < distance && distance <= 7) {
    row2();
    // row3
  }
  else if (7 < distance && distance <= 9) {
    row1();
    // row4
  }
  else if (9 < distance && distance <= 11) {
    row5();
    // row5
  }
  else if (11 < distance && distance <= 14) {
    row4();
    // row6
  }
  else if (14 < distance && distance <= 17) {
    row6();
    // row7
  }
  else if (17 < distance && distance <= 20) {
    row7();
    // row8
  }

  else if (20 < distance) {
    lightNone();
  }
}