/*
 * main.c
 *
 *  Created on: Apr 17, 2022
 *      Author: Basel Ashraf
 */



//extern int dio_app(void);
//extern void control_led(void);
extern int timer0_app(void);
int main(void)
{

	timer0_app();

	return 0;
}
