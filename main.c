/* MAIN.C file
 * 
 * Copyright (c) 2002-2005 STMicroelectronics
 */


#include "stm8s.h"
#include "stm8s_conf.h"
#include "lcd_i2c.h"

int testValue = 0;
void lcd_count(void);

main()
{
	//spi max7219
	SPI_Clock_Config();
	SPI_GPIO_setup();
	SPI_setup();
	MAX7219_init();
	//----------------------

	//GPIO_Init(GPIOA, GPIO_PIN_3, GPIO_MODE_OUT_PP_LOW_FAST); //toggle gpio test pin
	
	//MX_TIM4_Init();  //enable tim4 init and interrupt

	//I2C_Clock_Config();  //enable i2c feature
	//lcd_setup();

/* gpio ket interrupt
	GPIO_Init(GPIOC, GPIO_PIN_3, GPIO_MODE_IN_PU_IT);
	GPIO_Init(GPIOB, GPIO_PIN_5, GPIO_MODE_OUT_PP_LOW_FAST);
	EXTI_SetExtIntSensitivity(EXTI_PORT_GPIOC,EXTI_SENSITIVITY_FALL_LOW);
*/
	rim();    //enable interrupt

	display_clear(); //Clearing the display
	delay_ms(1000);

	while (1) {
	//Delay_ms_int(100);    //toggle gpio delay
	//GPIO_WriteReverse(GPIOA, GPIO_PIN_3);   //toggle gpio

	//lcd_count();

	SPI_print();
	}

}

void lcd_count(void)
{
	LCD_Set_Cursor(2,8);
	LCD_Print_Integer(testValue);
	delay_ms(100);
	testValue++;
}
