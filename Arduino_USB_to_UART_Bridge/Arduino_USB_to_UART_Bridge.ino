/*
  Multple Serial test

 Receives from the main serial port, sends to the others.
 Receives from serial port 1, sends to the main serial (Serial 0).

 This example works only with boards with more than one serial like Arduino Mega, Due, Zero etc

 The circuit:
 * Any serial device attached to Serial port 1
 * Serial monitor open on Serial port 0:

 created 30 Dec. 2008
 modified 20 May 2012
 by Tom Igoe & Jed Roach
 modified 27 Nov 2015
 by Arturo Guadalupi

 This example code is in the public domain.

 */
 
#include <SoftwareSerial.h>

SoftwareSerial Lora (10, 11); // RX, TX

void setup() {
  // initialize both serial ports:
  Serial.begin(9600);
  Lora.begin(57600);
}

void loop() {
  // read from port 1, send to port 0:
  if (Lora.available()) {
    int inByte = Lora.read();
    Serial.write(inByte);
  }

  // read from port 0, send to port 1:
  if (Serial.available()) {
    int inByte = Serial.read();
    Lora.write(inByte);
  }
}
