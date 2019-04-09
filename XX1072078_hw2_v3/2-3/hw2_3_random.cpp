
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


int main(){

    srand(5);
    //ifstream input( "input.txt" );
    ofstream output( "random.txt" );
   

    //creat random array in random.txt
    cout<<"creat random array in random.txt"<<"\n";
    int count = 0;
    while (count < 10000){
        int x = rand()%11000;
        output << x << " ";
        count++;
    }
    cout<<"Done\n";

}

