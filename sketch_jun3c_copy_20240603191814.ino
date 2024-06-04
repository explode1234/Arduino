//Raghav Haravu
//AP Physics C Q4, Ms. Hester
const int enablePin = 3;
const int motorPin1 = 4;
const int motorPin2 = 5;

const int Pin = A0;
//  This will define the connections for the motor driver and joystick.

void setup() {
  
  pinMode(enablePin, OUTPUT);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  
  //This will set the motor pins as outputs so it can begin the communication.
  
  Serial.begin(9600);
}

void loop() {
  
  int Value = analogRead(Pin);
  Serial.println(Value); // This will print the joystick value, I did this so I could debug the correct value that I needed.

  
  int motorSpeed = map(Value, 0, 1023, 0, 255);
  
  // Determine motor direction based on joystick value
  if (Value < 256) {
    // This will rotate the motor in one direction
    write(motorPin1, HIGH);
    write(motorPin2, LOW);
  } else if (Value > 256) {
    // This will rotate the motor in the opposite direction
    write(motorPin1, LOW);
    write(motorPin2, HIGH);
  } else {
    // This stops the motor
    write(motorPin1, LOW);
    write(motorPin2, LOW);
  }
  
  // This sets the motor speed
  analogWrite(enablePin, motorSpeed);

  delay(100); /
}
