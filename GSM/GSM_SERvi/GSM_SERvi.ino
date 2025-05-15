#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial SIM900(7, 8);
Servo myservo;

void setup() {
  myservo.attach(9);
  SIM900.begin(19200);
  Serial.begin(19200);
}

void loop() {
  if (SIM900.available() > 0) {
    String incomingMessage = "";
    incomingMessage = SIM900.readString();
    if (incomingMessage.indexOf("s") > 0) {
      myservo.write(180);
      delay(1000);
      myservo.write(0);
      delay(1000);
    }
  }
}
