/*
 * main.c
 *
 *  Created on: Apr 17, 2022
 *      Author: Basel Ashraf
 */



//extern int dio_app(void);
//extern void control_led(void);
//extern int timer0_app(void);
//extern void potentiometer_app(void);
//extern int lcd_test_app(void);
//extern int keypad_lcd_app_test(void);
extern int uart_app_test(void);
int main(void)
{

	uart_app_test();

	return 0;
}
