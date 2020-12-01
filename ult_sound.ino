int trigPin = 44; //front, right
int echoPin = 42;
int trigPin2 = 40; //front, left
int echoPin2 = 38;
int trigPin3 = 50; //not_front, right
int echoPin3 = 46;
int trigPin4 = 52; //not_front, left
int echoPin4 = 48;

int ObjDistErrCount = 30;

long duration, cmFrontLeft, cmFrontRight, cmRearLeft, cmRearRight;

void setup_ult_sound() {
  pinMode(trigPin, OUTPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(trigPin4, OUTPUT);
  pinMode(echoPin4, INPUT);
  pinMode(echoPin3, INPUT);
}
boolean test_ult_sound() {
  /*digitalWrite(trigPin2, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin2, HIGH);

  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration = pulseIn(echoPin2, HIGH);
  cmFrontLeft = (duration / 2) / 29.1;
  duration = 0;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);

  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  cmFrontRight = (duration / 2) / 29.1;
  duration = 0;*/

  digitalWrite(trigPin4, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin4, HIGH);

  delayMicroseconds(10);
  digitalWrite(trigPin4, LOW);
  duration = pulseIn(echoPin4, HIGH);
  cmRearLeft = (duration / 2) / 29.1;
  duration = 0;

  digitalWrite(trigPin3, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin3, HIGH);

  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);
  duration = pulseIn(echoPin3, HIGH);
  cmRearRight = (duration / 2) / 29.1;
  duration = 0;

  Serial.print(cmFrontLeft);
  Serial.print("|");
  Serial.print(cmFrontRight);
  Serial.print("|");
  Serial.print(cmRearLeft);
  Serial.print("|");
  Serial.print(cmRearRight);
  Serial.println();
  delay(550);

  if (cmRearLeft < ObjDistErrCount || cmRearRight < ObjDistErrCount) {
    pick();
    return true;
  }
  else return false;
}
