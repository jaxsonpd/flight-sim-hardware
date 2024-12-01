/**
 * @file seven_segment.hpp
 * @author Jack Duignan (JackpDuignan@gmail.com)
 * @date 2024-12-01
 * @brief Declaration for a seven SevenSegment display
 */


#ifndef SEGMENT_HPP
#define SEGMENT_HPP

#include <stdint.h>
#include <stdbool.h>


class SevenSegment {
private:
    uint8_t _shiftReg; // The shift register value to output
    uint8_t _serialPin; // The pin for the serial input of the shift register
    uint8_t _serialClockPin; // The pin for the clock of the shift register
    bool _point; // Wether the decimal point is enabled.
public:
    /** 
     * @brief Initialise the seven segment display
     * @param serialPin the pin to the data input of the shift register
     * @param serialClockPin the pin to the clock of the shift register
     */
    SevenSegment(uint8_t serialPin, uint8_t serialClockPin);
    
    /** 
     * @brief Blank the seven segment display
     * 
     */
    void blank(void);
    
    /** 
     * @brief Write a value to the seven segment display
     * @param number the number to write
     */
    void write(uint8_t number);
    
    /** 
     * @brief Display the current number on the display
     * 
     */
    void update(void);
    
    /** 
     * @brief Enabled or disable the decimal point
     * @param enable true if the point should be enabled
     * 
     */
    void point(bool enable);
    
    ~SevenSegment();
};

struct MultiSevenSegmentConfig
{
    uint8_t serialPin;
    uint8_t serialClockPin;
    uint8_t digit1Pin;
    uint8_t digit2Pin;
    uint8_t digit3Pin;
    uint8_t digit4Pin;
};


class MultiSevenSegment
{
private:
    SevenSegment* _digits[4];
    uint8_t _serialPin;
    uint8_t _serialClockPin;
    uint8_t _digit1Pin;
    uint8_t _digit2Pin;
    uint8_t _digit3Pin;
    uint8_t _digit4Pin;
public:
    MultiSevenSegment(MultiSevenSegmentConfig config);
    ~MultiSevenSegment();

    /** 
     * @brief Write a number to the 4 digits
     * @param number the number to write
     *
     */
    void write(uint16_t number);

    /** 
     * @brief Update the display
     * 
     */
    void update(void);
};

#endif // SEGMENT_HPP
