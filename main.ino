#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
// библиотека для работы I²C
#include <Wire.h>
// библиотека для работы с часами реального времени
#include <TroykaRTC.h>
boolean can_start = false;
boolean people_was_in = false;
boolean people_in = false;

String timeStr;
String dateStr;
String weekDayStr;

String s_timeStr;
String s_dateStr;
String s_weekDayStr;


int pinClock = 51;
RTC clock;


void setup() {
  Serial.begin (9600);
  lcd.begin(20, 4);
  setup_ult_sound();
  setup_inf();
  setup_dyn();
  setup_dis_val();

  clock.begin();
  clock.set(__TIMESTAMP__);

  clock.read();
  clock.getTimeStamp(s_timeStr, s_dateStr, s_weekDayStr);
  clock.getTimeStamp(timeStr, dateStr, weekDayStr);

  delay(500);
}

void loop() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("\xA8\x6F\x63\xBB\x65\xE3\xBD"); //последняя обработка
  lcd.print("\xC7\xC7\x20\x6F\xB2\x70\x61");
  lcd.print("\xB2\x6F\xBF\xBA\x61\x3A");
  lcd.setCursor(6, 2);
  lcd.print(s_timeStr);
  Serial.print(s_timeStr);
  Serial.print(" | ");
  Serial.print(s_dateStr);
  Serial.println();
  Serial.println();
  lcd.setCursor(5, 3);
  lcd.print(s_dateStr);

  if (!inf_people_test() && !test_ult_sound()) {
    people_in = false;
    clock.read();
    clock.getTimeStamp(timeStr, dateStr, weekDayStr);
    if (s_weekDayStr != weekDayStr) can_start = true;
    else if (s_dateStr[0] != dateStr[0] || s_dateStr[1] != dateStr[1]) can_start = true;
    else if (s_timeStr[0] != timeStr[0]) can_start = true;
    else if (s_timeStr[1] != timeStr[1]) can_start = true;
    else if (s_timeStr[4] != timeStr[4]) can_start = true;
    if (can_start)
      if (can_start && people_was_in) {
        delay(1000);
        start_dis();

        lcd.clear();
        lcd.setCursor(1, 0);
        lcd.print("\x42\x65\xE3\xB5\xBF\x63");
        lcd.print("\xC7\x20\x6F\xB2\x70\x61\xB2\x6F\xBF\xBA\x61");
        float procts = 0;
        /*lcd.setCursor(0, 4);
          lcd.print("\xEF\xEF\xEF\xEF\xEF\xEF\xEF\xEF\xEF\xEF\xEF\xEF\xEF\xEF\xEF\xEF\xEF\xEF\xEF\xEF");*/
        for (int i = 0; i < 21; i++) {
          lcd.setCursor(i, 4);
          //lcd.print("\xEE");
          lcd.print("\xFF");
          /*if (i > 0) {
            lcd.setCursor(i - 1, 4);
            lcd.print("\x20");
            };*/
          lcd.setCursor(7, 2);
          if (procts < 100)procts += 5, 26;
          lcd.print(procts);
          lcd.print("\x25");
          delay(450);
        }

        end_dis();

        lcd.clear();
        lcd.setCursor(5, 1);
        lcd.print("\xE0\x65\xB7\xB8\xBD\xE4\x65\xBA\xE5\xB8\xC7");
        lcd.setCursor(6, 2);
        lcd.print("\xB7\x61\xB3\x65\x70\xC1\x65\xBD\x61\x11");
        clock.read();
        clock.getTimeStamp(s_timeStr, s_dateStr, s_weekDayStr);
        people_was_in = false;
        people_in = true;
        //delay(2000);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("\xA8\x6F\x63\xBB\x65\xE3\xBD"); //последняя обработка
        lcd.print("\xC7\xC7\x20\x6F\xB2\x70\x61");
        lcd.print("\xB2\x6F\xBF\xBA\x61\x3A");
        lcd.setCursor(6, 2);
        lcd.print(s_timeStr);
        lcd.setCursor(5, 3);
        lcd.print(s_dateStr);

      }
    can_start = false;
  }
  else {
    people_in = true;
    people_was_in = true;
  }
}
