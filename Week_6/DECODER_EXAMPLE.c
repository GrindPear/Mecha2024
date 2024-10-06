/* DECODER EXAMPLE*/

#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>

#define ENCODERA 17	        // Hall Sensor A
#define ENCODERB 27	        // Hall Sensor B
#define ENC2REDGEAR 216     // 12 Edge x 18:1 Gear ratio

int encA; 
int encB;   
int encoderPosition = 0;    // Position of Encoder
float redGearPosition = 0;  // Position of Motor

void funcEncoderA()
{
    encA = digitalRead(ENCODERA);
    encB = digitalRead(ENCODERB);
    if (encA == HIGH)   // Rising at A
    {
        if (encB == LOW) encoderPosition++;
        else encoderPosition--;
    }
    else                // Falling at A
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
    if (encB == HIGH)   // Rising at B
    {
        if (encA == LOW) encoderPosition--;
        else encoderPosition++;
    }
    else                // Falling at B
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
