/* MOTOR_PWM */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <wiringPi.h>
#include <softPwm.h>


#define MOTOR1 19   // Motor DI 1
#define MOTOR2 26   // Motor DI 2

void handle_sigint(int sig) {
    printf("\nEXIT PROGRAM\n");
    softPwmWrite(MOTOR1, 0);
    softPwmWrite(MOTOR2, 0);
    exit(0);
}

int main(void)
{   
    signal(SIGINT, handle_sigint);
    wiringPiSetupGpio();
    softPwmCreate(MOTOR1, 0, 100);  // Create soft Pwm
    softPwmCreate(MOTOR2, 0, 100);  // Create soft Pwm
    while(1)
    {
        int cnt = 0;
        for (; cnt<100; cnt++)
        {
            softPwmWrite(MOTOR1, cnt);
            softPwmWrite(MOTOR2, 0);
            delayMicroseconds(100000);  // 0.1 sec delay
        }
        cnt = 0;
        for (; cnt<100; cnt++)
        {
            softPwmWrite(MOTOR1, 0);
            softPwmWrite(MOTOR2, cnt);
            delayMicroseconds(100000);  // 0.1 sec delay
        }
    }
    return 0;
}