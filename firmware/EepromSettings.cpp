#include <Arduino.h>
#include <EEPROM.h>

#include "EepromSettings.h"


struct EepromSettings EepromSettings;


void EepromSettings::load() {

#ifdef ESP32
    if (!EEPROM.begin(EEPROM_SIZE))
    {
      Serial.println("failed to initialise EEPROM"); delay(10000);
    }
#endif

    EEPROM.get(0, *this);

    if (this->magic != EEPROM_MAGIC)
        this->initDefaults();
}

void EepromSettings::save() {
    EEPROM.put(0, *this);
#ifdef ESP32
    EEPROM.commit();
#endif
}


void EepromSettings::initDefaults() {
    memcpy_P(this, &EepromDefaults, sizeof(EepromDefaults));
    this->save();
}
