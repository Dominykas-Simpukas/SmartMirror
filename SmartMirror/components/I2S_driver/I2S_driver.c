#include <stdio.h>
#include <string.h>
#include "I2S_driver.h"


/*
@brief: I2S driver config fnction to initialise and enable i2S\
@param: 
@return: Status_t state
*/
Status_t I2S_driver_init (i2s_chan_handle_t *i2s_handler, i2s_config_t i2s_params)
{
    static i2s_std_config_t i2s_config = {0};

    //Init I2S channel 
        i2s_chan_config_t chan_cfg = I2S_CHANNEL_DEFAULT_CONFIG(I2S_NUM_AUTO, I2S_ROLE_MASTER);
        i2s_new_channel(&chan_cfg, i2s_handler, NULL);

    //assign i2s_params to config struct
        /*Clk params*/
        i2s_config.clk_cfg.clk_src          = i2s_params.clock_source;
        i2s_config.clk_cfg.mclk_multiple    = i2s_params.MCLK_multiply;
        i2s_config.clk_cfg.sample_rate_hz   = i2s_params.i2s_sample_rate_hz;
        /*GPIO params*/
        i2s_config.gpio_cfg.bclk            = i2s_params.BCLK;
        i2s_config.gpio_cfg.din             = i2s_params.Din;
        i2s_config.gpio_cfg.dout            = i2s_params.Dout;
        memcpy(&i2s_config.gpio_cfg.invert_flags, &i2s_params.gpio_invert_flags, sizeof(invert_flags));
        i2s_config.gpio_cfg.mclk            = i2s_params.MCLK;
        i2s_config.gpio_cfg.ws              = i2s_params.WS;
        /*slot params*/
        i2s_config.slot_cfg.bit_shift       = i2s_params.bit_shift_enable_flag;
        i2s_config.slot_cfg.data_bit_width  = i2s_params.data_bit_width;
        i2s_config.slot_cfg.msb_right       = i2s_params.msb_right_ch_flag;
        i2s_config.slot_cfg.slot_bit_width  = i2s_params.slot_bit_width;
        i2s_config.slot_cfg.slot_mask       = i2s_params.slot_mask;
        i2s_config.slot_cfg.slot_mode       = i2s_params.slot_mode;
        i2s_config.slot_cfg.ws_pol          = i2s_params.WS_polarity;
        i2s_config.slot_cfg.ws_width        = i2s_params.WS_width;



    //init i2s peripheral
        if (i2s_channel_init_std_mode(*i2s_handler, &i2s_config) != ESP_OK)
        {
            return STATUS_ERROR;
        }

    //enable I2S channel
        if (i2s_channel_enable(*i2s_handler) != ESP_OK)
        {
            return STATUS_ERROR;
        }

        return STATUS_OK;
}