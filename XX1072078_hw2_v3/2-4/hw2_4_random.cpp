
/**
 *  Name : hw1
 *
 *  Author : Tony Guo
 *  
 *  Country : Taiwan
 *
 *  Date : 9 April, 2019 
 * 
 *  github : https://github.com/tony92151/algorithm_homework
 */

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
using namespace std;

void swap(int *a,int *b){
    int store = *a;
    *a = *b;
    *b = store;
}


int main(){
    ifstream input( "random.txt" );
    ofstream output( "random.txt" );
   
    cout<<"creat random array in random.txt"<<"\n";

    if (input.is_open()){

        int count2 = 0;

        //define array length
        int *array = new int [10000];
        
        while (count2 < 10000){
            array[count2] = count2;
            count2++;
        }


        //swap random
        count2 = 0;
        while (count2 < 1000){
            int x = rand()%10000;
            swap(&array[x], &array[x+1]);
            count2++;
        }

        //store in random.txt
        count2 = 0;
        while (count2 < 10000){
            output << array[count2] << " ";
            count2++;
        }
    } 
    cout<<"Done\n";

}

