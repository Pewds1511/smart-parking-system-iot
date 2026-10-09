#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int trig1 = 2;
const int echo1 = 3;
const int trig2 = 4;
const int echo2 = 5;

const int greenLED = 6;
const int redLED = 7;

const int threshold = 10;

long getDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000);

  if (duration == 0) {
    return 999;
  }

  return duration * 0.0343 / 2;
}

void setup() {
  pinMode(trig1, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(trig2, OUTPUT);
  pinMode(echo2, INPUT);

  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Smart Parking");
  lcd.setCursor(0, 1);
  lcd.print("System Ready");
  delay(2000);
  lcd.clear();
}

void loop() {
  long distance1 = getDistance(trig1, echo1);
  delay(50); 
  long distance2 = getDistance(trig2, echo2);

  bool slot1Occupied = distance1 < threshold;
  bool slot2Occupied = distance2 < threshold;

  int occupied = slot1Occupied + slot2Occupied;
  int available = 2 - occupied;

  lcd.setCursor(0, 0);
  lcd.print("Slot1:");
  lcd.print(slot1Occupied ? "FULL " : "FREE ");
  lcd.print("       ");

  lcd.setCursor(0, 1);
  lcd.print("Slot2:");
  lcd.print(slot2Occupied ? "FULL " : "FREE ");
  lcd.print("       ");

  if (available > 0) {
    digitalWrite(greenLED, HIGH);
    digitalWrite(redLED, LOW);
  } else {
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, HIGH);
  }

  delay(500);
}
