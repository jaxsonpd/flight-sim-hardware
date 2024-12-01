/**
 * @file seven_segment.cpp
 * @author Jack Duignan (JackpDuignan@gmail.com)
 * @date 2024-12-01
 * @brief Seven SevenSegment display driver
 */


#include <stdint.h>
#include <stdbool.h>

#include <Arduino.h>
#include "seven_segment.hpp"

uint8_t digits[10] = {
    0b11111100,
    0b01100000,
    0b11011010,
    0b11110010,
    0b01100110,
    0b10110110,
    0b10111110,
    0b11100000,
    0b11111110,
    0b11100110,
};

void SevenSegment::blank(void) {
    for (uint32_t i = 0; i < 9; i++) {
        digitalWrite(_serialClockPin, LOW);
        digitalWrite(_serialPin, LOW);
        digitalWrite(_serialClockPin, HIGH);
    }
}

void SevenSegment::write(uint8_t number) {
    if (number < 10) {
        _shiftReg = digits[number] |= _point;
    }
}

SevenSegment::SevenSegment(uint8_t serialPin, uint8_t serialClockPin) {
    SevenSegment::_serialPin = serialPin;
    SevenSegment::_serialClockPin = serialClockPin;

    pinMode(serialPin, OUTPUT);
    pinMode(serialClockPin, OUTPUT);

    blank();

}

void SevenSegment::update(void) {
    for (uint32_t i = 0; i < 9; i++) {
        digitalWrite(_serialClockPin, LOW);

        int val = _shiftReg & (1 << i);
        digitalWrite(_serialPin, val);
        
        digitalWrite(_serialClockPin, HIGH);
    }
}

SevenSegment::~SevenSegment() {
}

void SevenSegment::point(bool enable) {
    _point = enable;

    if (enable) {
        _shiftReg |= 1;
    } else {
        _shiftReg &= ~(1);
    }
}

MultiSevenSegment::MultiSevenSegment(MultiSevenSegmentConfig config) {
    _serialPin = config.serialPin;
    _serialClockPin = config.serialClockPin;
    _digit1Pin = config.digit1Pin;
    _digit2Pin = config.digit2Pin;
    _digit3Pin = config.digit3Pin;
    _digit4Pin = config.digit4Pin;

    _digits[0] = new SevenSegment(_serialPin, _serialClockPin);
    _digits[1] = new SevenSegment(_serialPin, _serialClockPin);
    _digits[2] = new SevenSegment(_serialPin, _serialClockPin);
    _digits[3] = new SevenSegment(_serialPin, _serialClockPin);
}

MultiSevenSegment::~MultiSevenSegment() {

}

void MultiSevenSegment::write(uint16_t number) {
    (*_digits[0]).write(number & (0xF000));
    (*_digits[1]).write(number & (0x0F00));
    (*_digits[2]).write(number & (0x00F0));
    (*_digits[3]).write(number & (0x000F));
}

void MultiSevenSegment::update(void) {
    digitalWrite(_digit1Pin, HIGH);
    (*_digits[0]).update();
    digitalWrite(_digit1Pin, LOW);
    digitalWrite(_digit2Pin, HIGH);
    (*_digits[1]).update();
    digitalWrite(_digit2Pin, LOW);
    digitalWrite(_digit3Pin, HIGH);
    (*_digits[2]).update();
    digitalWrite(_digit3Pin, LOW);
    digitalWrite(_digit4Pin, HIGH);
    (*_digits[3]).update();
    digitalWrite(_digit4Pin, LOW);
    
}
