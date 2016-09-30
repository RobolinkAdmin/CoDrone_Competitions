int Prev;
int Current;

void setup() {
  Serial.begin(9600);
  pinMode(24, INPUT);
  pinMode(11, OUTPUT);
  pinMode(23, OUTPUT);
  pinMode(22, OUTPUT);
  digitalWrite(22, HIGH);
  digitalWrite(23, HIGH);
}

void loop() {

  Current = analogRead(24);
  Serial.println(Current);

  if (abs(Current - Prev) > 5) {
    digitalWrite(22, LOW);
    digitalWrite(23, LOW);
    delay(2000);
    digitalWrite(22, HIGH);
    digitalWrite(23, HIGH);
  }
  Prev = Current;

}
