int msensor = 2;
int led = 9;
void setup() {
 pinMode(msensor, INPUT);
 pinMode(led, OUTPUT);
 Serial.begin(9600);

}

void loop() {
  int sensorvalue = digitalRead(msensor);
  if (sensorvalue == HIGH){
    digitalWrite(led, HIGH);
    Serial.println("Motion Detected");
  }else {
    digitalWrite(led, LOW);
    Serial.println("NO Motion Detected");
  }
delayMicroseconds(200);
}
