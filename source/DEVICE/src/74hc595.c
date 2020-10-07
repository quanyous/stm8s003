#include "74hc595.h"

//GPIO初始化
void HC595_GPIO_Config()
{

    GPIO_DeInit(GPIOC);          //重置
    GPIO_Init(GPIOC,GPIO_PIN_5|GPIO_PIN_6,GPIO_MODE_OUT_PP_HIGH_SLOW);    //相应端口初始化，推挽输出，高电平，低速（2m/s）

    GPIO_DeInit(GPIOA);          //重置
    GPIO_Init(GPIOA,GPIO_PIN_3,GPIO_MODE_OUT_PP_LOW_FAST);                  //相应端口初始化，推挽输出，低电平，高速（10m/s）
}


//时钟初始化
void hc_clk_init()            
{
    CLK_DeInit();
    CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV8);          //8分频  
}


//spi配置，配置好再使能
void SPI_Config()
{
    CLK_PeripheralClockConfig(CLK_PERIPHERAL_SPI, ENABLE);   //使能spi时钟
    SPI_Init(SPI_FIRSTBIT_LSB,                                //高位先发
              SPI_BAUDRATEPRESCALER_256,                  //波特率
              SPI_MODE_MASTER, SPI_CLOCKPOLARITY_HIGH,    //主机模式，时钟极性为1
              SPI_CLOCKPHASE_2EDGE,                       //时钟相位，The second clock transition is the first data capture edge 
              SPI_DATADIRECTION_2LINES_FULLDUPLEX,        //双向全双工
              SPI_NSS_SOFT, 0x07);   //禁用软件片选， 0x07啥玩意？是CRC多项式寄存器的复位值
    SPI_Cmd(ENABLE);     //使能命令
}

void SendData(u8 byte)
{
        // HC595_SHCP_Low();
		// GPIO_WriteLow(GPIOC,GPIO_PIN_6);
        SPI_SendData(byte);
        // HC595_SHCP_High();
}

//适当延时函数
void delay(uint16_t t)
{
	for (; t != 0; t --);
 
}


//移位寄存器的数据移入存储寄存器
void HC595_CS(void) 
{
	/**  步骤3：STCP产生一个上升沿，移位寄存器的数据移入存储寄存器  **/
	HC595_STCP_Low();   // 将STCP拉低
	delay(1);           // 适当延时
	HC595_STCP_High();  // 再将STCP拉高，STCP即可产生一个上升沿
	delay(1);
}

//多个字节发送
void HC595_Send_Multi_Byte(u8 *data, u16 len)  
{
	u8 i = 0;
	for (i = 0; i < len; i ++ ) // len 个字节
	{
		SendData(data[i]);
	}
	
	HC595_CS(); //先把所有字节发送完，再使能输出
}


//延时
void Delay1() 
{  
        for(char i=0;i<200;i++)
        {
            for(char j=0;j<200;j++);

        }  
}
/*****************************************************    
 *流水灯程序
*******************************************************/
void LED_ShowOneToOne(void)	
{
		// u8 pos = 0; // led位置	
		// u8 Led_Show[3] = {0xFF, 0xFF, 0xFF};
		// //u8 Led_Show[3] = {0xff, 0xff, 0xff}; //存储要发送的指令字节,		Led_Show[0]控制灯6-10；		Led_Show[1]控制灯1-5
		// 	//第X个led亮	：1     2    3      4    5    	
		// u8 Waterfall_Led[24] = {0x01, 0x02, 0x04, 0x08, 0x10,0x20,0x40,0x80,  //控制第一级74HC595	

		// 			            0x00, 0x00, 0x00, 0x00, 0x00, 0x00,0x00, 0x00,  //控制第二级74HC595

		// 			            0x00, 0x00, 0x00, 0x00, 0x00, 0x00,0x00, 0x00};

		// for (pos = 0; pos < 8; pos ++) 				//第pos个灯，实现流水灯效果
		// {					
		// 	Led_Show[2] = Waterfall_Led[pos];			//存放第一级74HC595数据，因为先进先出，所以第一级放在Led_Pos_Buf[1]，而不是Led_Pos_Buf[0]
		// 	Led_Show[1] = Waterfall_Led[pos+8]; 	//存放第二级74HC595的数据	
        //     Led_Show[0]	= Waterfall_Led[pos+16]	;    //第三级		
		// 	 HC595_Send_Multi_Byte(Led_Show,3);		//将当前数据发送到595	 
		// 	 Delay1();		
            

		// }
		SendData(0x01);
		SendData(0x02);
		SendData(0x04);
		HC595_CS();
		delay(100000);

		

			// Led_Show[2] = Waterfall_Led[pos];			//存放第一级74HC595数据，因为先进先出，所以第一级放在Led_Pos_Buf[1]，而不是Led_Pos_Buf[0]
			// Led_Show[1] = Waterfall_Led[pos+8]; 	//存放第二级74HC595的数据	
            // Led_Show[0]	= Waterfall_Led[pos+16]	;    //第三级	

			// SendData(0x01);
			// HC595_Send_Multi_Byte(Led_Show,3);
			// Delay1();
		// for (pos = 8; pos < 16; pos ++) 				//第pos个灯，实现流水灯效果
		// {					
		// 	Led_Show[1] = Waterfall_Led[pos-8];			//存放第一级74HC595数据，因为先进先出，所以第一级放在Led_Pos_Buf[1]，而不是Led_Pos_Buf[0]
		// 	Led_Show[0] = Waterfall_Led[pos]; 	//存放第二级74HC595的数据	
        //     Led_Show[2]	= Waterfall_Led[pos];    //第三级		
		// 	HC595_Send_Multi_Byte(Led_Show,3);		//将当前数据发送到595	 
		// 	Delay1();		
		// }
		// for (pos = 16; pos < 24; pos ++) 				//第pos个灯，实现流水灯效果
		// {					
		// 	Led_Show[0] = Waterfall_Led[pos-16];			//存放第一级74HC595数据，因为先进先出，所以第一级放在Led_Pos_Buf[1]，而不是Led_Pos_Buf[0]
		// 	Led_Show[2] = Waterfall_Led[pos]; 	//存放第二级74HC595的数据	
        //     Led_Show[1]	= Waterfall_Led[pos];    //第三级		
		// 	HC595_Send_Multi_Byte(Led_Show,3);		//将当前数据发送到595	 
		// 	Delay1();		
		// }
}


