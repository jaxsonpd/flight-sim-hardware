#include "event.hpp"

void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    Serial.println("Starting ...");
}

void loop() {
    // put your main code here, to run repeatedly:
    delay(1000);
    event_add(EVENT_RADIO_1_SWAP_ACTIVE);
    delay(500);
    event_transmit();
}
