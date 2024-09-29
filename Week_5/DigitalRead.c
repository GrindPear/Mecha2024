/* DigitalRead EXAMPLE*/

#include <stdio.h>
#include <wiringPi.h>

#define SWITCH 18			// SWITCH pin number 18

int main(void)
{
	wiringPiSetupGpio();
	pinMode(SWITCH, INPUT);	// Set GPIO18 as input

	while(1)
	{
		int input = digitalRead(SWITCH);
		printf("Input Value: %d\n", input);
		delay(100);
	}
	return 0;
}