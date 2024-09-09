#include <stdio.h>

void Swap(int num1, int num2){
    printf("num1 address: %p\n", &num1);
    printf("num2 address: %p\n", &num2);

    int ref = num1;
    num1 = num2;
    num2 = ref;
    
}

int main(){
    int a = 3;
    int b = 5;

    printf("a address: %p\n", &a);
    printf("b address: %p\n", &b);

    Swap(a, b);

    printf("%d\n", a);
    printf("%d\n", b);
}