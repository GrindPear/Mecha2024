/* Hardware PWM EXAMPLE*/

#include <stdio.h>				
#include <wiringPi.h>			

#define LED 18				

int main(void)
{
    wiringPiSetupGpio();

    pinMode(LED, PWM_OUTPUT);   // Set GPIO18 as pwm output

    while(1)
    {
        for (int cnt=0; cnt<1024; cnt++)
        {
            pwmWrite(LED, cnt);  
            delay(1);           // 1ms = 0.001s
        }
    }
    return 0;
}
