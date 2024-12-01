/**
 * @file event.cpp
 * @author Jack Duignan (JackpDuignan@gmail.com)
 * @date 2024-12-01
 * @brief Handle the communication of events from the hardware to the
 * device driver
 */


#include <stdint.h>
#include <stdbool.h>
#include <Arduino.h>

#include "event.hpp"

#define EVENT_QUEUE_SIZE 100


char* eventMsgs[EVENT_COUNT] = { "EMPTY", "EVENT_RADIO_1_SWAP_ACTIVE" };

eventID_t eventQueue[EVENT_QUEUE_SIZE] = { EVENT_EMPTY };

int event_add(eventID_t eventID) {
    uint32_t i = 0;
    while (i < EVENT_QUEUE_SIZE) {
        if (eventQueue[i] == EVENT_EMPTY) {
            eventQueue[i] = eventID;
            break;
        }
        i++;
    }

    if (i == EVENT_QUEUE_SIZE) {
        return 1;
    } else {
        return 0;
    }
}


int event_transmit(void) {
    for (uint32_t i = 0; i < EVENT_QUEUE_SIZE; i++) {
        if (eventQueue[i] == EVENT_EMPTY) {
            break;
        } else {
            Serial.println(eventMsgs[eventQueue[i]]);
            eventQueue[i] = EVENT_EMPTY;
        }
    }

    return 0;
}