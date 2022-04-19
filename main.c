/*
 * main.c
 *
 *  Created on: Apr 17, 2022
 *      Author: Basel Ashraf
 */



//extern int dio_app(void);
//extern void control_led(void);
//extern int timer0_app(void);
extern void potentiometer_app(void);
int main(void)
{

	potentiometer_app();

	return 0;
}
