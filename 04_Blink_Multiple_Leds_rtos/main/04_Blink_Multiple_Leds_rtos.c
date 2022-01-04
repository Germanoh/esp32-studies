#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define BLINK_LED_1 GPIO_NUM_32
#define BLINK_LED_2 GPIO_NUM_33

// functions definitions
void config_gpio_pins(void);
void blink1 (void *pvParams);
void blink2 (void *pvParams);

void config_gpio_pins(void)
// sets up all the pin configurations
/* On this particular case, gpio32 (pin 12) and gpio33 (pin 13) are both set 
// to output mode, pull-up and pull-down disabled and no interrupts actives. */
{
    gpio_config_t gpioConfig;
    gpioConfig.pin_bit_mask = (1ULL << BLINK_LED_1) | (1ULL << BLINK_LED_2);
    gpioConfig.mode = GPIO_MODE_OUTPUT;
    gpioConfig.pull_up_en = GPIO_PULLUP_DISABLE;
    gpioConfig.pull_down_en = GPIO_PULLUP_DISABLE;
    gpioConfig.intr_type = GPIO_INTR_DISABLE;
    gpio_config(&gpioConfig);

    // return gpioConfig;
}

void blink1 (void *pvParams)
{
    for (;;)
    {
        printf("Blink LED 1...\n");
        
        gpio_set_level(BLINK_LED_1, 1);
        vTaskDelay(1000 / portTICK_PERIOD_MS);

        gpio_set_level(BLINK_LED_1, 0);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void blink2 (void *pvParams)
{
    for (;;)
    {
        printf("Blink LED 2...\n");
        
        gpio_set_level(BLINK_LED_2, 1);
        vTaskDelay(500 / portTICK_PERIOD_MS);

        gpio_set_level(BLINK_LED_2, 0);
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}

void app_main(void)
{
    // gpio_config_t gpioConfig = config_pins();
    config_gpio_pins();

    printf("Starting task 1...\n");
    printf("Starting task 2...\n");
    xTaskCreate(blink1, "Blink 1", 1024 * 2, NULL, 1, NULL);
    xTaskCreate(blink2, "Blink 2", 1024 * 2, NULL, 1, NULL);
}
