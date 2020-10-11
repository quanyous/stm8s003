#include "stm8s.h"

#include "74hc595.h"
void main()
{

    hc_clk_init();//时钟初始化
    HC595_GPIO_Config();//spi gpio初始化
    SPI_Config();

    while(1)
    {
        LED_ShowOneToOne();	

    }


}
