#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#include "hardware/gpio.h"
#include <sys/types.h>

int main() {
    stdio_init_all();

    const uint Led_pin1 = 2;
    const uint Led_pin2 = 3;

    gpio_init(Led_pin1);
    gpio_init(Led_pin2);
    gpio_set_dir(Led_pin1, GPIO_OUT);
    gpio_set_dir(Led_pin2, GPIO_OUT);

    if (cyw43_arch_init()) {
        printf("Wi-Fi init failed\n");
        return -1;
    }

    // Initialize UART once
    setup_default_uart();

    while (true) {
        // Onboard Wi-Fi LED ON
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);

        // External LEDs toggle
        gpio_put(Led_pin1, 1);
        gpio_put(Led_pin2, 0);
        sleep_ms(100);

        gpio_put(Led_pin1, 0);
        gpio_put(Led_pin2, 1);

        // Onboard Wi-Fi LED OFF
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
        sleep_ms(100);

        // Print once per loop
        printf("Hello, world!\n");
    }
}