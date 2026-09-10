/*
 * Natural Disaster Detection & Alert System
 * ------------------------------------------
 * Platform : Arduino Uno
 * Sensors  : HC-SR04 Ultrasonic Sensor
 *            PIR Motion Sensor
 * Outputs  : Buzzer + LED
 *
 * The system monitors abnormal environmental conditions
 * using sensor readings and activates an alert when
 * predefined thresholds are exceeded.
 */

// Pin definitions
const int TRIG_PIN = 9;
const int ECHO_PIN = 10;

const int PIR_PIN = 7;
const int BUZZER_PIN = 6;
const int LED_PIN = 5;

// Distance threshold in centimeters
const int DISTANCE_THRESHOLD = 20;


// ---------------------------------------------------------
// Measure distance using HC-SR04
// ---------------------------------------------------------
long getDistance()
{
  long duration;
  long distance;

  // Send ultrasonic pulse
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  // Read echo response
  duration = pulseIn(ECHO_PIN, HIGH, 30000);

  // Convert time to distance
  distance = duration * 0.034 / 2;

  return distance;
}


// ---------------------------------------------------------
// Setup
// ---------------------------------------------------------
void setup()
{
  Serial.begin(9600);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(PIR_PIN, INPUT);

  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  digitalWrite(BUZZER_PIN, LOW);
  digitalWrite(LED_PIN, LOW);

  Serial.println("Natural Disaster Detection System");
  Serial.println("----------------------------------");
  Serial.println("System Started...");
}


// ---------------------------------------------------------
// Main loop
// ---------------------------------------------------------
void loop()
{
  long distance = getDistance();

  int motionDetected = digitalRead(PIR_PIN);

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (motionDetected == HIGH)
  {
    Serial.println("Motion detected!");
  }
  else
  {
    Serial.println("No motion detected.");
  }


  // -------------------------------------------------------
  // Alert condition
  // -------------------------------------------------------
  if (distance > 0 &&
      distance < DISTANCE_THRESHOLD &&
      motionDetected == HIGH)
  {
    Serial.println("!!! ABNORMAL CONDITION DETECTED !!!");

    digitalWrite(LED_PIN, HIGH);

    digitalWrite(BUZZER_PIN, HIGH);
    delay(500);

    digitalWrite(BUZZER_PIN, LOW);
    delay(500);
  }
  else
  {
    digitalWrite(LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);
  }

  Serial.println("----------------------------------");

  delay(500);
}
