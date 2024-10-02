/* DECODER EXAMPLE*/

#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>

#define ENCODERA 17     // Hall Sensor A
#define ENCODERB 27     // Hall Sensor B

int encA;
int encB;

void funcEncoderA()     // Hall Sensor A
{
    printf("funcEncoderA()");
    encA = digitalRead(ENCODERA);
    encB = digitalRead(ENCODERB);
    printf("%d %d\n", encA, encB);
}

void funcEncoderB()     // Hall Sensor B
{
    printf("funcEncoderB()");
    encA = digitalRead(ENCODERA);
    encB = digitalRead(ENCODERB);
    printf("%d %d\n", encA, encB);
}

int main(void)
{
    wiringPiSetupGpio();
    pinMode(ENCODERA, INPUT);       // Set ENCODERA as input
    pinMode(ENCODERB, INPUT);       // Set ENCODERB as input

    // ENCODERA: Interrupt occurs for both Rising & Falling
    wiringPiISR(ENCODERA, INT_EDGE_BOTH, funcEncoderA);
    // ENCODERB: Interrupt occurs for both Rising & Falling
    wiringPiISR(ENCODERB, INT_EDGE_BOTH, funcEncoderB);
    while(1)
    {
        // Loop Forever
    } 
    return 0;
}