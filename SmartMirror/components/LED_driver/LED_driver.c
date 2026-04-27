#include <stdio.h>
#include "LED_driver.h"


Status_t LED_driver_init (gpio_num_t pin_number)
{
    if (pin_number > GPIO_NUM_MAX || pin_number < GPIO_NUM_NC)
    {
        return STATUS_ERROR;
    }

    gpio_config_t LED_pin_configs = 
    {
        .intr_type      = GPIO_INTR_DISABLE,
        .mode           = GPIO_MODE_OUTPUT,
        .pin_bit_mask   = (1ULL << pin_number),
        .pull_down_en   = GPIO_PULLDOWN_DISABLE,
        .pull_up_en     = GPIO_PULLUP_DISABLE
    };

    if (gpio_config(&LED_pin_configs) != ESP_OK)
    {
        return STATUS_ERROR;
    }

    return STATUS_OK;
}

Status_t LED_driver_turn_on (gpio_num_t pin_number)
{
    if (gpio_set_level(pin_number, 1) != STATUS_OK)
    {
        return STATUS_ERROR;
    }

    return STATUS_OK;
}

Status_t LED_driver_turn_off    (gpio_num_t pin_number)
{
    if (gpio_set_level(pin_number, 0) != STATUS_OK)
    {
        return STATUS_ERROR;
    }

    return STATUS_OK;
}

Status_t LED_driver_toggle      (gpio_num_t pin_number)
{
    if (gpio_set_level(pin_number, !gpio_get_level(pin_number)) != STATUS_OK)
    {
        return STATUS_ERROR;
    }

    return STATUS_OK;
}

bool LED_driver_get_state   (gpio_num_t pin_number)
{
    return (bool) gpio_get_level(pin_number);
}