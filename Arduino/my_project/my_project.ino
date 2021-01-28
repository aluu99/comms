const int ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);
  digitalWrite(ledPin, LOW);
  digitalWrite(ledPin, LOW);

  print("Hello World!\n");

}
