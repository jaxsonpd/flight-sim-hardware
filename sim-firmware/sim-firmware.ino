#include "event.hpp"

void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    Serial.println("Starting ...");
    pinMode(5, INPUT_PULLUP);
}

void loop() {
    // put your main code here, to run repeatedly:
    delay(200);
    if (digitalRead(5) == 0) {
       event_add(EVENT_RADIO_1_SWAP_ACTIVE);
    }
    event_transmit();
}
