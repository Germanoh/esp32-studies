/* Turns on the built-in LED on gpio25 from the module esp32 wifi lora v2 from heltec */

#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"

#define BLINK_LED GPIO_NUM_25

void app_main(void)
{
    // Sets the BLINK_LED pin to gpio
    gpio_pad_select_gpio(BLINK_LED);

    // puts the BLINK_LED to output
    gpio_set_direction(BLINK_LED, GPIO_MODE_OUTPUT);

    // turns the BLINK_LED ON
    gpio_set_level(BLINK_LED, 1);
}
