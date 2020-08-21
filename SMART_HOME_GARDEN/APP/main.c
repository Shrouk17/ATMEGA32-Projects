
#include <avr/io.h>
#include "../HAL/light.h"
#include "../HAL/rf.h"
#include "../MCAL/pwm_v_2.h"
#include "../HAL/ultra2.h"
#include "../HAL/LCD.h"
#include <stdio.h>
#include <util/delay.h>





int distance ;
int light ;




void led_on (void)
{
	PORTC |= (1<<0)|(1<<1)|(1<<5);
}
void led_off (void)
{
	PORTC &=~( (1<<0)|(1<<1)|(1<<5));
}


int main(void)
{
	DDRC = (1<<0)|(1<<1)|(1<<5)|(1<<6); // leds and buzzer direction output
	DDRD |=(1<<2); // relay deriction output

	systick_lcd_Init();
	systick_lcd_clear_screen();

	pwm_init();
	Pwm_setcallback_comparematch(led_off);
	Pwm_setcallback_overflow(led_on);

	light_init();
	rf_init();


	while (1)
	{
		_delay_ms(600);
		systick_lcd_clear_screen();

		distance = get_ultra_distance();  // garage
		char arr[15];
		sprintf(arr,"distance = %d", distance);
		systick_lcd_print_string(arr);

		if (distance < 20)
		{
			PORTD |=(1<<2);   //relay on
			_delay_ms(2000);
			PORTD &=~(1<<2);  // relay off
		}

		light = light_read();  // getting light reading
		if (light < 400)
		{
			pwm_SetDutyCycle(255); // making led brighter

		}
		else if (light> 400)
		{
			pwm_SetDutyCycle(5); //making leds less bright
		}


	}
	return 0 ;
}
