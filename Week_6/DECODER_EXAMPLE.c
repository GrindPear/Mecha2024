/* DECODER EXAMPLE*/

#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>

#define ENCODERA 17	// Hall Sensor A
#define ENCODERB 27	// Hall Sensor B
#define ENC2REDGEAR 216

int encA;
int encB;
int encoderPosition = 0;
float redGearPosition = 0;

void funcEncoderA()
{
    encA = digitalRead(ENCODERA);
    encB = digitalRead(ENCODERB);
    if (encA == HIGH)
    {
        if (encB == LOW) encoderPosition++;
        else encoderPosition--;
    }
    else
    {
        if (encB == LOW) encoderPosition--;
        else encoderPosition++;
    }
    redGearPosition = (float)encoderPosition / ENC2REDGEAR;
    printf("funcEncoderA() A: %d B: %d encPos: %d gearPos: %f\n",
        encA, encB, encoderPosition, redGearPosition);
}

void funcEncoderB()
{
    encA = digitalRead(ENCODERA);
    encB = digitalRead(ENCODERB);
    if (encB == HIGH)
    {
        if (encA == LOW) encoderPosition--;
        else encoderPosition++;
    }
    else
    {
        if (encA == LOW) encoderPosition++;
        else encoderPosition--;
    }
    redGearPosition = (float)encoderPosition / ENC2REDGEAR;
    printf("funcEncoderB() A: %d B: %d encPos: %d gearPos: %f\n",
        encA, encB, encoderPosition, redGearPosition);
}

int main(void)
{
    wiringPiSetupGpio();
    pinMode(ENCODERA, INPUT);
    pinMode(ENCODERB, INPUT);

    wiringPiISR(ENCODERA, INT_EDGE_BOTH, funcEncoderA);
    wiringPiISR(ENCODERB, INT_EDGE_BOTH, funcEncoderB);
    while (1)
    {
        // Loop Forever
    }
    return 0;
}
