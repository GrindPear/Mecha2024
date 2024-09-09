#include <stdio.h>

int main(){
    int a[3] = {1,2,3};
    printf("%p %p %p \n", a, &a[0], &a);
    printf("%p %p %p \n", a+1, &a[0]+1, &a+1);
    printf("%d %d %d \n", sizeof(a), sizeof(&a[0]), sizeof(&a));
}