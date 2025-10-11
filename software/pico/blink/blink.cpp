// Actually not blink. Only turns on default LED on Raspbery Pi Pico W. Made change in CMakeLists.txt to enable log output over USB.
#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"




int main()
{
    stdio_init_all();

    // Initialise the Wi-Fi chip
    if (cyw43_arch_init()) {
        printf("Wi-Fi init failed\n");
        return -1;
    }

    // Example to turn on the Pico W LED
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);

    while (true) {
        printf("Hello, world!\n");
        sleep_ms(1000);
    }
}
