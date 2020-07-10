
 
#include <SoftwareSerial.h>

SoftwareSerial sw_serial (3, 2); // RX, TX

void setup() {
  // initialize both serial ports:
  Serial.begin(9600);
  sw_serial.begin(57600);
}

void loop() {
  // read from port 1, send to port 0:
  if (sw_serial.available()) {
    int inByte = sw_serial.read();
    Serial.write(inByte);
  }

  // read from port 0, send to port 1:
  if (Serial.available()) {
    int inByte = Serial.read();
    sw_serial.write(inByte);
  }
}
