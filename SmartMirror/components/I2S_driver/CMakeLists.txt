idf_component_register(SRCS "I2S_driver.c"
                    REQUIRES esp_driver_i2s
                    REQUIRES System_files
                    INCLUDE_DIRS "include")
