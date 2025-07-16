const int trigpin = 9;
const int echopin = 10;
const int ledRed = 11;
const int ledGreen = 7;

long duration;
int distance;

void setup() {
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Clear the trig pin
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  
  // Sends a 10 microsecond pulse
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);

  // Read echo time
  duration = pulseIn(echopin, HIGH);

  // Calculate distance in cm
  distance = duration * 0.034 / 2;

  // Prints the distance
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // LED control based on distance
  if (distance < 20) {
    digitalWrite(ledRed, HIGH);
    digitalWrite(ledGreen, LOW);
  } else {
    digitalWrite(ledRed, LOW);
    digitalWrite(ledGreen, HIGH);
  }

  delay(500); // Small delay for readability dont want the serial monitor to spam
               
}
