#include <Arduino.h>

// constants won't change:
const int LED_PIN = LED_BUILTIN;     // the number of the LED pin
const int BUTTON_PIN = 7;  // the number of the button pin

const long BLINK_INTERVAL = 1000;   // interval at which to blink LED (milliseconds)

// Variables will change:
int ledState = LOW;   // ledState used to set the LED

int previousButtonState = LOW; // will store last time button was updated

unsigned long previousMillis = 0;   // will store last time LED was updated

void setup() {
  Serial.begin(115200);

  // set the digital pin as output:
  pinMode(LED_PIN, OUTPUT);
  
  // set the digital pin as an input:
  pinMode(BUTTON_PIN, INPUT);
}

void loop() {
  // check to see if it's time to blink the LED; that is, if the difference
  // between the current time and last time you blinked the LED is bigger than
  // the interval at which you want to blink the LED.
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= BLINK_INTERVAL) {
    // if the LED is off turn it on and vice-versa:
    ledState = (ledState == LOW) ? HIGH : LOW;

    // set the LED with the ledState of the variable:
    digitalWrite(LED_PIN, ledState);
    //
    Serial.println("Henrik");

    // save the last time you blinked the LED
    previousMillis = currentMillis;
  }

  // check button state's change
  int currentButtonState = digitalRead(BUTTON_PIN);

  if(currentButtonState != previousButtonState) {
    // print out the state of the button:
    Serial.println(currentButtonState);

    // save the last state of button
    previousButtonState = currentButtonState;
  }

  // DO OTHER WORKS HERE
}