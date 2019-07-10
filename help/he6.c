#include <stdio.h>

int main(){ 
    char *bin="10101010";
    char *a = bin;
    int num = 0;
    do {
        int b = *a!='1'?1:0;
        num = (num<<1)|b;
        a++;
    } while (*a);
    printf("%X\n", num);
}