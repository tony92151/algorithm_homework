#include <stdio.h>

int leagth = 255;

int main(){ 
    for(int i = 0; i <= leagth; i++){
        if(i%16==0){
            printf("\n");
            printf("%02x ", i);
        }else{
            printf("%02x ", i);
        }
    }
    printf("\n");
}

