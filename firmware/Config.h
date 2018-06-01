#ifndef CONFIG_H
#define CONFIG_H

// If board is ESP32, uncomment this
// #define ESP32

// Receivers
// ==============

// Number of receivers on the board. Make sure these are sequentially connected
// to the pins --- no gaps!
#define RECEIVER_COUNT 4

#ifdef ESP32

    #define RECEIVER_PIN_SPI_CLK 18
    #define RECEIVER_PIN_SPI_DATA 19
  
    const int RECEIVER_PINS_SPI_SS[] = {5, 17, 16, 4};
    const int RECEIVER_PINS_RSSI[] = {36, 39, 34, 35};

#else

    #define RECEIVER_PIN_SPI_CLK 2
    #define RECEIVER_PIN_SPI_DATA 3
  
    const int RECEIVER_PINS_SPI_SS[] = {11, 12, 13, 14};
    const int RECEIVER_PINS_RSSI[] = {A0, A1, A2, A3};

#endif


// Temperature Monitoring
// ======================
#ifndef ESP32
    #define TEMP_MONITORING_ENABLED
#endif

#ifdef TEMP_MONITORING_ENABLED
    #define TEMP_MONITORING_PIN A7

    // Multiplier for raw ADC value to get to celcius. Defaults work for the
    // LM35  at 0.01V/C.
    #define TEMP_MONITORING_MULTIPLIER (((1.0f / 1024.0f) * 5.0f) / 0.01f)
#endif


// Voltage Monitoring
// ==================
#ifndef ESP32
    #define VOLTAGE_MONITORING_ENABLED
#endif

#ifdef VOLTAGE_MONITORING_ENABLED
    #define VOLTAGE_MONITORING_PIN A6

    // Multiplier for raw ADC value to get to volts. Defaults work for a 1:11
    // divider.
    #define VOLTAGE_MONITORING_MULTIPLIER (1.0f / 1024.0f * 5.0f * 11.0f)
#endif


// Serial
// ====

#define SERIAL_BAUD 250000

// Delay between RSSI messages. Too fast and the buffer clogs and things get
// weird. 2ms is a good default value.
#ifdef ESP32
    #define RSSI_DELAY_MS 1
#else
    #define RSSI_DELAY_MS 2
#endif // ESP32

// Delay between monitoring messages.
#define MONITORING_DELAY_MS 10000


// Misc
// ====

// Delay to wait for modules to settle, etc.
#define BOOT_DELAY_MS 1000


// =============================================================================

#ifdef ESP32
    #define LED_PIN LED_BUILTIN
#else
    #define LED_PIN 13
#endif


#if defined(VOLTAGE_MONITORING_ENABLED) || defined(TEMP_MONITORING_ENABLED)
    #define MONITORING_ENABLED
#endif


#endif
