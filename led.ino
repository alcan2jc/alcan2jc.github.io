#include <SoftwareSerial.h>
int passOn = 69;   // Password to turn on LED
int passOff = 420; // Password to turn off LED

int LED_RED = 13; // Pin 12 is connected to LED
int LED_YELLOW = 12;
int LED_GREEN = 8;

String msg;

void setup()
{
  pinMode(LED_RED, OUTPUT);  // Initialize pin 12 as an output
  digitalWrite(LED_RED, LOW);// Turns off LED to begin
  pinMode(LED_YELLOW, OUTPUT);  // Initialize pin 12 as an output
  digitalWrite(LED_YELLOW, LOW);// Turns off LED to begin
  pinMode(LED_GREEN, OUTPUT);  // Initialize pin 12 as an output
  digitalWrite(LED_GREEN, LOW);// Turns off LED to begin
  Serial.begin(9600);
}
void loop()
{
  msg = Serial.readString();
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_YELLOW, LOW);
  digitalWrite(LED_GREEN, LOW);
  if (msg == "Inverter") {
    digitalWrite(LED_RED, HIGH);
  } if (msg == "Charge Controller") {
    digitalWrite(LED_YELLOW, HIGH);
  } if (msg == "Battery") {
    digitalWrite(LED_GREEN, HIGH);
  }
  delay(1000);
}