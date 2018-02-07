int motorId;
int degree;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if(Serial.available() >=2 )
  {
    motorId = Serial.read() - 48;
    degree = Serial.read() - 48;
    Serial.println(motorId);
    Serial.println(degree);
    Serial.write(motorId);
    Serial.write(degree);
  }
}
