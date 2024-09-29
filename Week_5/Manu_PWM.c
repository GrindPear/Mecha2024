/* Manual PWM EXAMPLE*/

#include <stdio.h>				
#include <wiringPi.h>			

#define LED 18
#define DelayTime1 1000
#define DelayTime2 500
 				
int main(void)
{		
	wiringPiSetupGpio();		
	pinMode(LED, OUTPUT);		
	
	while(1)				
	{
		digitalWrite(LED, HIGH);	
		delay(DelayTime1);		
		digitalWrite(LED, LOW);	
		delay(DelayTime2);
	} 				
	return 0;
}