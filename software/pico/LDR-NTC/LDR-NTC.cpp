// LDR-NTC.cpp - Analog Input example - 2025-10-11-noharm
// Tested on Raspberry Pi Pico W
// [+3V3]---[=LDR or NTC_10K=]---[GPIO 26 (ADC0)]---[=10k=]---[GND]
#include <stdio.h>
#include "hardware/adc.h"
#include "pico/stdlib.h"

// The Pico Analog-to-Digital Converter (ADC) has 12 bit resolution.
// Each measurement results in a number from 0 to 4095.
// The Pico maps this to a range from 0 Volts to 3.3 Volts.
static constexpr uint LDR_PIN = 26;   // GPIO26 = ADC0
static constexpr uint LDR_CH   = 0;    // ADC channel 0
static constexpr uint VREF_MV  = 3300; // 3.3 V reference in millivolts

int main()
{
    stdio_init_all();
    adc_init();
    
    adc_gpio_init(LDR_PIN);
    adc_select_input(LDR_CH);

    while (true) {
        uint16_t raw = adc_read();  // 12-bit raw value [0–4095]
        // Convert to millivolts (integer math)
        uint32_t mv = (static_cast<uint32_t>(raw) * VREF_MV) / 4095;

        printf("ADC raw=%u, ~%lumV\n", raw, mv);
        sleep_ms(500);
    }
}
//EOF