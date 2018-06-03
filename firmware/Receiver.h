#ifndef RECEIVER_H
#define RECEIVER_H


#include <stdint.h>
#include "ReceiverSpiDriver.h"


class Receiver {
    public:
        void init(
            uint8_t spiClockPin,
            uint8_t spiDataPin,
            uint8_t spiSelectPin,
            uint8_t rssiPin,
            uint16_t rssiMin,
            uint16_t rssiMax
        );

        void updateRssi();
        void setRssiMin(uint16_t rssi);
        void setRssiMax(uint16_t rssi);
        void setFrequency(uint16_t frequency);

        uint16_t rssiRaw;
        uint8_t rssi;

    private:
        ReceiverSpiDriver driver;
        uint8_t rssiPin;

        uint16_t rssiMin;
        uint16_t rssiMax;
};


#endif
