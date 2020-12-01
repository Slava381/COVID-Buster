int oldValue1 = 0;
int pirValue1 = 0;
int ch = 0;
int oldValue2 = 0;
int pirValue2 = 0;
int pinPir1 = 28;
int pinPir2 = 26;

void setup_inf() {
  pinMode(pinPir1, INPUT);
  pinMode(pinPir2, INPUT);
}
boolean inf_people_test() {
  oldValue1 = digitalRead(pinPir1);
  oldValue2 = digitalRead(pinPir2);
  pirValue1 = 0;
  pirValue2 = 0;
  ch = 0;
  while (ch != 5 ) {
    pirValue1 = digitalRead(pinPir1);
    pirValue2 = digitalRead(pinPir2);
    if (oldValue1 == pirValue1 && oldValue2 == pirValue2)
      ch++;
    else
      ch = 0;
    oldValue1 = pirValue1;
    oldValue2 = pirValue2;
    delay(100);
    Serial.print(pirValue1);
    Serial.print(" | ");
    Serial.println(pirValue2);
    Serial.println();
    Serial.println();
  }
  if (pirValue1 || pirValue2) {
    pick();
    return true;
  }
  else return false;
}
