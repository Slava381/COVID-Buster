int dynPin = 7;

void setup_dyn(){
  pinMode(dynPin, OUTPUT);
}
void pick(){
  tone(dynPin, 1000, 120);
  Serial.print("PICK!!!");
}
