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

uint32_t frequency = 0;
char receivedNumber[5];  // Buffer to store the received number (max 10 digits)
int currentIndex = 0;     // Index for storing digits in the buffer
    
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

    if (Serial.available() > 0) {
        // Read one byte of data
        char incomingByte = Serial.read();

        // If we receive a semicolon, process the number
        if (incomingByte == ';') {
            receivedNumber[currentIndex] = '\0';  // Null-terminate the string

            int number = atoi(receivedNumber);

            Serial.print("Converted to int: ");
            Serial.println(number);  
            multiDisplay.write(number);

            currentIndex = 0;
        } 
        else {
            // Store the incoming byte in the buffer
            if (currentIndex < 5) {
                receivedNumber[currentIndex] = incomingByte;
                currentIndex++;
            }
        }
    }
        
    multiDisplay.update();

}

