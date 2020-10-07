/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __74HC595_H
#define __74HC595_H

/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"

/* Exported types ------------------------------------------------------------*/
#define SHCP_GPIO_PORT      GPIOC			              		
#define SHCP_GPIO_PIN	    GPIO_PIN_5		       
 
#define STCP_GPIO_PORT      GPIOA		              		
#define STCP_GPIO_PIN	    GPIO_PIN_3		        
 
#define DS_GPIO_PORT        GPIOC			              		
#define DS_GPIO_PIN	    GPIO_PIN_6

/* Exported constants --------------------------------------------------------*/

/* Exported macros -----------------------------------------------------------*/
#define HC595_SHCP_Low()      GPIO_WriteLow( SHCP_GPIO_PORT, SHCP_GPIO_PIN )
#define HC595_SHCP_High()     GPIO_WriteHigh( SHCP_GPIO_PORT, SHCP_GPIO_PIN )
#define HC595_STCP_Low()      GPIO_WriteLow( STCP_GPIO_PORT, STCP_GPIO_PIN )
#define HC595_STCP_High()     GPIO_WriteHigh( STCP_GPIO_PORT, STCP_GPIO_PIN )
#define HC595_Data_Low()      GPIO_WriteLow( DS_GPIO_PORT, DS_GPIO_PIN )
#define HC595_Data_High()     GPIO_WriteHigh( DS_GPIO_PORT, DS_GPIO_PIN )
/* Private macros ------------------------------------------------------------*/

/* Exported functions ------------------------------------------------------- */

extern void HC595_GPIO_Config(void);  
extern void hc_clk_init(void);
extern void SPI_Config(void);
extern void SendData(u8 byte);
extern void HC595_CS(void);
extern void HC595_Send_Multi_Byte(u8 *data, u16 len);
extern void delay(uint16_t t);
extern void Delay1(void);
extern void LED_ShowOneToOne(void);

#endif /* __74HC595_H */