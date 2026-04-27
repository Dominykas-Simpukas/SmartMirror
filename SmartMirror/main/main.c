#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
 #include "freertos/task.h"

void app_main(void)
{
    printf("Main is running on %d core\n\r", xPortGetCoreID());

    while(1)
    {
     printf("Hello world!\n");
        vTaskDelay(pdMS_TO_TICKS(1000));  // 1 second
    }
}
