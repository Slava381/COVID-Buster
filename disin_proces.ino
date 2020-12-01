int relayPinUVCLamp = 22;
int relayPinValve = 24;

int enA = 31;
int in1 = 33;
int in2 = 35;

void setup_dis_val() {
  pinMode(relayPinUVCLamp, OUTPUT);
  pinMode(relayPinValve, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  analogWrite(enA, 0);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}
void start_dis() {
  analogWrite(enA, 200);
  digitalWrite(in1, LOW );
  digitalWrite(in2, HIGH );
  delay(4000);
  analogWrite(enA, 0);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(relayPinUVCLamp, HIGH);
  digitalWrite(relayPinValve, HIGH);
}
void end_dis() {
  digitalWrite(relayPinUVCLamp, LOW);
  digitalWrite(relayPinValve, LOW);
  delay(1000);
  analogWrite(enA, 200);
  digitalWrite(in1, HIGH  );
  digitalWrite(in2, LOW );
  delay(4000);
  analogWrite(enA, 0);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}
