/* Using the freertos to blink a LED on gpio25 for 1 second ON and 1 second OFF */

#include <stdio.h>
#include "freertos/Freertos.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define BLINK_LED GPIO_NUM_25

void blink_1 (void *pvParams)
// blinks ON and OFF a led by 1 second
{    
    for (;;)
    // task loop, prints ON and OFF and then changes the signal of gpio25.
    // should run forever
    {
        printf("Led ON...\n");
        gpio_set_level(BLINK_LED, 1);
        vTaskDelay(1000 / portTICK_PERIOD_MS);

        printf("Led OFF...\n");
        gpio_set_level(BLINK_LED, 0);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }

    // if the previous loop is exited by any reason the vTaskDelete function 
    // destroys the actual task.
    vTaskDelete(NULL);
}

void app_main(void)
{
    gpio_pad_select_gpio(BLINK_LED);                            // sets gpio25 as an gpio pin
    gpio_set_direction(BLINK_LED, GPIO_MODE_OUTPUT);            // sets gpio25 to output

    xTaskCreate(blink_1, "Blink 1", 1024 * 2, NULL, 1, NULL);   // creates a task called blink_1
    printf("Executing task1...\n");
}
