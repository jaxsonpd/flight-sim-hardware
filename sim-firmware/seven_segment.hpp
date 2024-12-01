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


#endif // SEGMENT_HPP
