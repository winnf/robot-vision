#include <Servo.h>
#include <NewPing.h>

#define TRIGGER_PIN  12
#define ECHO_PIN     11
#define SERVO_PIN    9
#define MAX_DISTANCE 200

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
Servo myservo;

int num_samples = 10; // Collected sample per degree angle

void setup() {
  myservo.attach(SERVO_PIN);
  Serial.begin(9600);
  delay(3000);
}

void loop() {
  int theta = 0; // angle
  int num_sample = 0;
  int distance = 0;

  for (theta = 0; theta < 180; theta ++)
  {
    unsigned int uS = sonar.ping();
    myservo.write(theta);
    delay(20);
    for (num_sample = 0; num_sample < num_samples; num_sample++)
    {
      uS = sonar.ping();
      distance = uS/US_ROUNDTRIP_CM + distance;
      delay(30);
    }

    distance = distance / (num_samples-1); // Average between the samples
    Serial.println(distance);

    distance = 0;
    num_sample = 0;
  }

}

