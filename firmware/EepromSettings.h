#ifndef EEPROMSETTINGS_H
#define EEPROMSETTINGS_H


#include <stdint.h>

#if (defined(__AVR__))
    #include <avr\pgmspace.h>
#else
    #include <pgmspace.h>
#endif

#include "Config.h"


#define EEPROM_MAGIC 0xDEEDBEEF


struct EepromSettings {
    uint32_t magic;

    uint16_t frequency[RECEIVER_COUNT];
    uint16_t rssiMin[RECEIVER_COUNT];
    uint16_t rssiMax[RECEIVER_COUNT];

    bool rawMode;

    void load();
    void save();

    void initDefaults();
};


PROGMEM const struct {
    uint32_t magic = EEPROM_MAGIC;

    uint16_t frequency[RECEIVER_COUNT] = {5658, 5732, 5806, 5880};
    uint16_t rssiMin[RECEIVER_COUNT]   = {1, 1, 1, 1};
    uint16_t rssiMax[RECEIVER_COUNT]   = {1023, 1023, 1023, 1023};

} EepromDefaults;

extern EepromSettings EepromSettings;


#endif
