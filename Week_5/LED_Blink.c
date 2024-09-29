/* LED BLINK EXAMPLE*/

#include <stdio.h>              // Standard I/O header
#include <wiringPi.h>           // wiringPi header

#define LED 18                  // LED pin number 18

int main(void)
{
	printf("BLINK\n");			// print BLINK on terminal
	wiringPiSetupGpio();		// Setup & initialize GPIO
	pinMode(LED, OUTPUT);		// Set GPIO18 as output
	
	while(1)				    // start of while
	{
		digitalWrite(LED, HIGH);// LED ON
		delay(2000);		    // wait for 2s (1000ms = 1s)
		digitalWrite(LED, LOW);	// LED OFF
		delay(2000);
	} 				            // end of while
	return 0;
}
