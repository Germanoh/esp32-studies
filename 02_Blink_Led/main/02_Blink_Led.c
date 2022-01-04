#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define BLINK_LED GPIO_NUM_25

void app_main(void)
{
    // sets up the gpio25 as a gpio
    gpio_pad_select_gpio(BLINK_LED);

    // sets gpio25 as output 
    gpio_set_direction(BLINK_LED, GPIO_MODE_OUTPUT);

    while(true)
    {
        // turns on the BLINK_LED for 1 second
        gpio_set_level(BLINK_LED, 1);
        vTaskDelay(1000 / portTICK_PERIOD_MS);

        // turns off the BLINK_LED for 1 second
        gpio_set_level(BLINK_LED, 0);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }

}
