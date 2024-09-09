#include <stdio.h>

void StaticExample(){
    int a = 1;
    static int b = 1;
    printf("a = %d, b = %d\n", a++, b++);
}

int main(){
    for (int i=0; i<10; ++i){
        StaticExample();
    }
    return 0;
}