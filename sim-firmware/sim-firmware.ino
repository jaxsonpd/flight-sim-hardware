#include "event.hpp"
#include "seven_segment.hpp"

#include <Arduino.h>

SevenSegment display(8, 9);
MultiSevenSegmentConfig multiDisplayConfig = {
    .serialPin = 8,
    .serialClockPin = 9,
    .digit1Pin = 2,
    .digit2Pin = 3,
    .digit3Pin = 4,
    .digit4Pin = 6,
};

MultiSevenSegment multiDisplay = MultiSevenSegment(multiDisplayConfig);

void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    Serial.println("Starting ...");
    pinMode(5, INPUT_PULLUP);
}

void counting(void) {
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
    for (size_t i = 0; i < 10; i++)
    {
        multiDisplay.write(i*113);
        
        uint32_t start_time = millis();
        while((millis() - start_time) < 1000) {
            multiDisplay.update();
        }
        delay(100);

    }


}

