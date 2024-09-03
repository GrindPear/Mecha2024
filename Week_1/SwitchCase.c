#include <stdio.h>

int main(){
    int a = 1;
    switch(a){
        case 1:
        printf("A");
        // break;
        case 2:
        printf("B");
        break;
        case 3:
        printf("C");
        break;
        default:
        printf("Default");
        break;
    }
}