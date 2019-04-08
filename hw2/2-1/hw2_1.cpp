
/**
 *  Name : hw1
 *
 *  Author : Tony Guo
 *  
 *  Country : Taiwan
 *
 *  Date : 18 Mar, 2019 
 * 
 *  github : https://github.com/tony92151/algorithm_homework
 */


#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


void InsertionSort(int *A, int length){

    for (int i = 1; i < length; i++) {
        int key = A[i];
        int j = i - 1;
        while (key < A[j] && j >= 0) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
}


int main(){

    ifstream input( "input.txt" );
    ofstream output( "output.txt" );
   
    int length;
    int array;

    if (input.is_open()){
        //bool first = true;

        //read first line to get length
        input >> length;
        cout<<"Length:" << length <<"\n";

        //define array length
        int *array = new int [length];

        //read each number in array
        int count = 0;
        while (count < length && input >> array[count]) count++;

        //display array
        cout<<"old array : ";
        for(int i = 0; i < length; i++) cout<<array[i]<<"  ";
        cout<<"\n";

        //sort
        InsertionSort(array, length);

        //display new array
        cout<<"new array : ";
        for(int i = 0; i < length; i++) cout<<array[i]<<"  ";
        cout<<"\n";

        //store new array in optput.txt
        cout<<"store new array in optput.txt\n";
        count = 0;
        output <<  length <<"\n";
        while (count < length && output << array[count]<<"\n") count++;
        cout<<"Done\n";
    }

}

