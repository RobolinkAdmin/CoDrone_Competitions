#include <SmartInventor.h>

const int UFO1_rec = 22;
const int UFO1_led = 27;
const int UFO2_rec = 23;
const int UFO2_led = 28;
const int GARAGE_bt1 = 29;
const int GARAGE_bt2 = 30;

int UFOBase[2];

unsigned long startTime;
int lastTime, totalTime;

void setup() {
  Serial.begin(9600);

  UFOBase[0] = analogRead(UFO1_rec);
  UFOBase[1] = analogRead(UFO2_rec);
  
  pinMode(UFO1_led, OUTPUT);
  pinMode(UFO2_led, OUTPUT);
  pinMode(GARAGE_bt1, INPUT_PULLUP);
  pinMode(GARAGE_bt2, INPUT_PULLUP);

  digitalWrite(UFO1_led, HIGH);
  digitalWrite(UFO2_led, HIGH);

  for (int i = 11; i <= 18; i++)
    pinMode(i, OUTPUT);
}

void loop() {
/*  Serial.print("UFO 1: ");
  Serial.print(UFOBase[0] - 25);
  Serial.print(" ");
  Serial.println(analogRead(UFO1_rec));
  Serial.print("UFO 2: ");
  Serial.print(UFOBase[1] - 25);
  Serial.print(" ");
  Serial.println(analogRead(UFO2_rec));
  Serial.println();*/
  
  if (analogRead(UFO1_rec) < UFOBase[0] - 25)
  {
    digitalWrite(UFO1_led, LOW);
  }

  if (analogRead(UFO2_rec) < UFOBase[1] - 25)
  {
    digitalWrite(UFO2_led, LOW);
  }

  if(!digitalRead(GARAGE_bt1) || !digitalRead(GARAGE_bt2))
  {
    for (int pin = 11; pin <= 18; pin++)
        digitalWrite(pin, HIGH);
  }
}
