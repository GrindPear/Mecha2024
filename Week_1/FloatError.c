#include <stdio.h>

int main(){
    double a = 0.1;
    double b = 0.2;
    double aplusb = a + b;
    double c = 0.3;
    printf("Double type calculation: %s\n", aplusb == c ? "true":"false");

    int Ia = 1;
    int Ib = 2;
    int IaplusIb = Ia + Ib;
    double Ic = 3;
    printf("Int type calculation: %s\n", IaplusIb == Ic ? "true":"false");

    return 0;
}