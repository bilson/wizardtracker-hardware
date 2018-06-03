#include <Arduino.h>
#include <stdint.h>
#include "receiver.h"


void Receiver::init(
    uint8_t spiClockPin,
    uint8_t spiDataPin,
    uint8_t spiSelectPin,
    uint8_t rssiPin,
    uint16_t rssiMin,
    uint16_t rssiMax
) {
    this->rssiPin = rssiPin;
    this->rssiMin = rssiMin;
    this->rssiMax = rssiMax;

    this->driver.init(spiClockPin, spiDataPin, spiSelectPin);
}


void Receiver::setFrequency(uint16_t frequency) {
    uint16_t fLo = (frequency - 479) / 2;
    uint16_t regN = fLo / 32;
    uint16_t regA = fLo % 32;
    uint16_t synthRegB = (regN << 7) | regA;

    this->driver.setSynthRegisterB(synthRegB);
}

void Receiver::setRssiMin(uint16_t rssi) {
    this->rssiMin = rssi;
}

void Receiver::setRssiMax(uint16_t rssi) {
    this->rssiMax = rssi;
}

void Receiver::updateRssi() {
    analogRead(this->rssiPin); // Fake read to settle ADC
    this->rssiRaw = analogRead(this->rssiPin);
    this->rssi = constrain(
        map(this->rssiRaw, this->rssiMin, this->rssiMax, 1, 255),
        1,
        255
    );
}
