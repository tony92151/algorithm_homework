#include <stdio.h>

a = 10;
b = 18;
c = 5;

int main(){
    a = 10;// 01010
    b = 18;// 10010
    c = 5; // 00101
    printf("%d\n", a|c); //01111
    printf("%d\n", b&c); //00000
}