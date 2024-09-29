/* softPwm.h EXAMPLE*/

#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>			// softPwm header

#define LED 18

int main(void)
{
	wiringPiSetupGpio();
	softPwmCreate(LED, 0, 100); // Create pwm for 0 ~ 100%
	while(1)
	{
		for (int cnt=0; cnt<100; cnt++)
		{
			softPwmWrite(LED, cnt);
			delay(1);
		}
	}
	return 0;
}
