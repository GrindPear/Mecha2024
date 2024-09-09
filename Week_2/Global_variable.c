#include <stdio.h>

int NUM = 3;

int getNUM(){
    int NUM = 0;
    printf("Local var address: %p\n", &NUM);
    return NUM;
}

int main(){
    printf("Global var value: %d\n", NUM);
    printf("Global var address: %p\n", &NUM);
    printf("Local var value: %d\n", getNUM());
    printf("NUM address after getNUM(): %p\n", &NUM);
    return 0;
}