#include "event.hpp"
#include "seven_segment.hpp"

#include <Arduino.h>

SevenSegment display(8, 9);

void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    Serial.println("Starting ...");
    pinMode(5, INPUT_PULLUP);
}

void loop() {
    // // put your main code here, to run repeatedly:
    // delay(1000);
    // display.blank();

    // if (digitalRead(5) == 0) {
    //     event_add(EVENT_RADIO_1_SWAP_ACTIVE);
    // }
    // event_transmit();
    // delay(1000);
    // display.update();
    display.blank();
    delay(1000);
    for (size_t i = 0; i < 10; i++) {
        display.write(i);
        display.point(true);
        display.update();
        delay(1000);
        display.point(false);
        display.update();
        delay(1000);
    }

}

