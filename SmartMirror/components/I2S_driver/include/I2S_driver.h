#ifndef I2S_DRIVER_H
#define I2S_DRIVER_H


#include <stdbool.h>
#include "driver/i2s_std.h"
#include "driver/i2s_pdm.h"
#include "SYSTEM_types.h"

typedef struct invert_flags{
    uint32_t   mclk_inv: 1;    /*!< Set 1 to invert the MCLK input/output */
    uint32_t   bclk_inv: 1;    /*!< Set 1 to invert the BCLK input/output */
    uint32_t   ws_inv: 1;      /*!< Set 1 to invert the WS input/output */
} invert_flags;   

typedef struct i2s_config_t
{
    uint32_t                    i2s_sample_rate_hz;
    i2s_clock_src_t             clock_source;
    i2s_mclk_multiple_t         MCLK_multiply;
    i2s_std_slot_mask_t         slot_mask;
    uint32_t                    WS_width;
    bool                        WS_polarity;
    bool                        bit_shift_enable_flag;
    bool                        msb_right_ch_flag;
    i2s_data_bit_width_t        data_bit_width;
    i2s_slot_bit_width_t        slot_bit_width;
    i2s_slot_mode_t             slot_mode;
    gpio_num_t                  MCLK;          
    gpio_num_t                  BCLK;           
    gpio_num_t                  WS;
    gpio_num_t                  Dout;
    gpio_num_t                  Din;
    invert_flags                gpio_invert_flags;
} i2s_config_t;



Status_t I2S_driver_init            (i2s_chan_handle_t *i2s_handler, i2s_config_t i2s_params);

#endif