/* SWITCH_INTERRUPT EXAMPLE*/

#include <stdio.h>
#include <wiringPi.h>

#define SWITCH 18

int switchPressed = 0;      // Counter for switch
int switchStatus;       // Status of switch input

void switch_pressed_callback()
{
    switchPressed++;
    pinMode(SWITCH, INPUT);
    wiringPiISR(SWITCH, INT_EDGE_FALLING, switch_pressed_callback);     // Execute switch pressed callback() at falling edge
    while(1)
    {
        // Loop forever
    }
    return 0;
}