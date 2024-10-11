/* SAMPLING_TIME_2 */

#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>

int main()
{
    wiringPiSetupGpio();
    unsigned int startTime = millis();

    unsigned int checkTimeBefore = millis();
    unsigned int checkTime;

    int cnt = 0;

    while(cnt < 100)
    {
        checkTime = millis();
        if (checkTime - checkTimeBefore >= 5) // 5 msec
        {
            cnt++;
            printf("loop time: %d msec, After init: %d msec\n", checkTime - checkTimeBefore, checkTime - startTime);
            checkTimeBefore = checkTime;
        }
    }
    return 0;
}