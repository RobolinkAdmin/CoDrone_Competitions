#include <SmartInventor.h>

#define trigPin 28
#define echoPin 27
#define trigPin2 30
#define echoPin2 29

void setup() {
  Serial.begin (9600);

  SmartInventor.DCMotorUse();

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

  for (int i = 11; i <= 18; i++)
    pinMode(i, INPUT);
}

void loop() {
  long dist = getDist(trigPin, echoPin);
  long dist2 = getDist(trigPin2, echoPin2);
  Serial.println(dist);

  if (analogRead(20) < 150)
  {
    for (int i = 11; i <= 18; i++)
      pinMode(i, OUTPUT);

    for (int i = 11; i <= 18; i += 2)
      digitalWrite(i, HIGH);
    for (int i = 12; i <= 18; i += 2)
      digitalWrite(i, LOW);

    while (analogRead(20) < 150)
    {}

    for (int i = 11; i <= 18; i++)
      pinMode(i, INPUT);
  }


  while ((dist > 50 && dist2 > 50) && analogRead(20) > 150)
  {
    dist = getDist(trigPin, echoPin);
    dist2 = getDist(trigPin2, echoPin2);
    Serial.print(dist);
    Serial.print("  ");
    Serial.print(dist2);
    Serial.print("  ");
    Serial.println(analogRead(20));
  }


  SmartInventor.DCMotor(M1, CCW, 100);
  SmartInventor.DCMotor(M2, CW, 100);
  delay(333);

  while ((digitalRead(11) || digitalRead(18)) && analogRead(20) > 150)
  {
    if ((digitalRead(13) && !digitalRead(16)))
    {
      SmartInventor.DCMotor(M1, CCW, 120);
      SmartInventor.DCMotor(M2, LOOSE, 0);
    }
    else if ((digitalRead(12) && !digitalRead(17)))
    {
      SmartInventor.DCMotor(M1, CCW, 127);
      SmartInventor.DCMotor(M2, CCW, 20);
    }
    else if ((!digitalRead(13) && digitalRead(16)))
    {
      SmartInventor.DCMotor(M1, LOOSE, 0);
      SmartInventor.DCMotor(M2, CW, 120);
    }
    else if ((!digitalRead(12) && digitalRead(17)))
    {
      SmartInventor.DCMotor(M1, CW, 20);
      SmartInventor.DCMotor(M2, CW, 127);
    }
    else
    {
      SmartInventor.DCMotor(M1, CCW, 100);
      SmartInventor.DCMotor(M2, CW, 100);
    }
  }

  SmartInventor.DCMotor(M1, STOP, 0);
  SmartInventor.DCMotor(M2, STOP, 0);
}

long getDist(int trig, int echo)
{
  long duration, distance;
  digitalWrite(trig, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trig, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = (duration / 2) / 29.1;
  return distance;
}

