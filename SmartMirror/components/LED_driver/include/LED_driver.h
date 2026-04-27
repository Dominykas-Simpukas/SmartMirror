#ifndef LED_DRIVER_H
#define  LED_DRIVER_H

#include <stdint.h>
#include <stdbool.h>
#include "driver/gpio.h"
#include "SYSTEM_types.h"

Status_t LED_driver_init        (gpio_num_t pin_number);
Status_t LED_driver_turn_on     (gpio_num_t pin_number);
Status_t LED_driver_turn_off    (gpio_num_t pin_number);
Status_t LED_driver_toggle      (gpio_num_t pin_number);
bool     LED_driver_get_state   (gpio_num_t pin_number);

#endif