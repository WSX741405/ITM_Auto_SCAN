int data;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if(Serial.available() >= 1)
  {
    data = Serial.read();
    Serial.write(data);
  }
}
