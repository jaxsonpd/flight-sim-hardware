/** 
 * @file event.hpp
 * @author Jack Duignan (JackpDuignan@gmail.com)
 * @date 2024-12-01
 * @brief Implementation for the module to comunicate events from firmware
 * to the host device driver.
 */


#ifndef EVENT_HPP
#define EVENT_HPP


#include <stdint.h>
#include <stdbool.h>

typedef enum {
    EMPTY,
    RADIO_1_SWAP_ACTIVE
} eventID_t;

/** 
 * @brief Add an event to the transmit queue
 * @param eventID the ID of the event to send
 * 
 * @return 0 if successful
 */
int event_add(eventID_t eventID);


#endif // EVENT_HPP