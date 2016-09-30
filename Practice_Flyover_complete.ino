#include <SmartInventor.h>
#include <Servo.h>
Servo servo1;
Servo servo2;
Servo myservo;
#define trigPin1 22
#define echoPin1 30
#define trigPin2 23
#define echoPin2 31
#define trigPin3 24
#define echoPin3 26
long dist1, dist2, dist3;
int flag1, flag2, flag3;


void setup() {
  Serial.begin (9600);

  myservo.attach(27);  // attaches the servo on pin 9 to the servo object
  servo1.attach(28);
  servo2.attach(29);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  myservo.write(90);
  servo1.write(90);
  servo2.write(90);
}

void loop() {
  if (flag1 == 0) {
    dist1 = getDist(trigPin1, echoPin1);
  }
  if (flag2 == 0) {
    dist2 = getDist(trigPin2, echoPin2);
  }
  if (flag3 == 0) {
    dist3 = getDist(trigPin3, echoPin3);
  }
  Serial.print(dist1);
  Serial.print("  ");
  Serial.print(dist2);
  Serial.print("  ");
  Serial.println(dist3);

  if (dist1 < 100 && flag1 == 0) {
    myservo.write(0);
    flag1 = 1;
  }
  if (dist2 < 100 && flag2 == 0) {
    servo1.write(0);
    flag2 = 1;
  }

  if (dist3 < 100 && flag3 == 0) {
    servo2.write(0);
    flag3 = 1;
  }

}

long getDist(int trig, int echo)
{
  long duration, distance;
  digitalWrite(trig, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trig, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH, 9000);
  distance = (duration / 2) / 29.1;
  return distance;
}

