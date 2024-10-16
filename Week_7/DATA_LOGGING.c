/* DATA_LOGGING */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <wiringPi.h>
#include <softPwm.h>

#define LOOPTIME 5  // Sampling Time
#define ENCODERA 17 // Hall Sensor A
#define ENCODERB 27 // Hall Sensor B
#define ENC2REDGEAR 216

#define MOTOR1 19   // Motor DI 1
#define MOTOR2 26   // Motor DI 2
#define PGAIN 10

#define NUM_ROWS 3000   // Size of array (row)
#define NUM_COLUMNS 2   // Size of array (col)
#define DAQ_TIME 10000  // Data logging for 10s

int encA; 
int encB;   
int encoderPosition = 0;    // Position of Encoder
float redGearPosition = 0;  // Position of Motor

float referencePosition = 10;
float errorPosition = 0;

unsigned int checkTime;
unsigned int checkTimeBefore;
unsigned int startTime;

int dataIndex = 0;
float dataArray[NUM_ROWS][NUM_COLUMNS]; // 2D array (rows x cols)
FILE* file;

void handle_sigint(int sig) {
    printf("\nEXIT PROGRAM\n");
    softPwmWrite(MOTOR1, 0);
    softPwmWrite(MOTOR2, 0);

    for (int i = 0; i < dataIndex; i++)
    {
        fprintf(file, "%.3f,%.3f\n", dataArray[i][0], dataArray[i][1]);
    }
    fclose(file);
    exit(0);
}

void updateDataArray()
{
    dataArray[dataIndex][0] = (float)(checkTime - startTime)/1000.0;
    dataArray[dataIndex][1] = redGearPosition;
    dataIndex++;
}

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
    errorPosition = referencePosition - redGearPosition;
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
    errorPosition = referencePosition - redGearPosition;
}

int main(void)
{   
    char filename[100]; 
    printf("Enter the CSV file name: ");
    scanf("%s", filename);
    file = fopen(strcat(filename, ".csv"), "w+");

    signal(SIGINT, handle_sigint);
    wiringPiSetupGpio();
    pinMode(ENCODERA, INPUT);
    pinMode(ENCODERB, INPUT);

    softPwmCreate(MOTOR1, 0, 100);  // Create soft Pwm
    softPwmCreate(MOTOR2, 0, 100);  // Create soft Pwm

    wiringPiISR(ENCODERA, INT_EDGE_BOTH, funcEncoderA);
    wiringPiISR(ENCODERB, INT_EDGE_BOTH, funcEncoderB);

    errorPosition = referencePosition - redGearPosition;
    checkTimeBefore = millis();
    startTime = millis();
    while(1)
    {
        checkTime = millis();
        if (checkTime - checkTimeBefore > LOOPTIME)
        {
            if (errorPosition > 0)
            {
                softPwmWrite(MOTOR1, errorPosition*PGAIN);
                softPwmWrite(MOTOR2, 0);
                printf("gearPos: %f errorPos: %f\n", redGearPosition, errorPosition);
            }
            else
            {
                softPwmWrite(MOTOR2, -errorPosition*PGAIN);
                softPwmWrite(MOTOR1, 0);
                printf("gearPos: %f errorPos: %f\n", redGearPosition, errorPosition);
            }
            updateDataArray();
            checkTimeBefore = checkTime;
        }
    }
    return 0;
}