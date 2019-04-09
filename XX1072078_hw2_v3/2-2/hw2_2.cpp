
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
using namespace std;

void swap(int *a,int *b){
    int store = *a;
    *a = *b;
    *b = store;
}

int PARTITION(int *A, int p, int r){
    int x = A[r];
    int i = p - 1;
    for (int j = p; j <= r-1; j++) {
        if (A[j] < x) {
            i++;
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[i+1], &A[r]);
    return i+1;
}

void QUICKSORT(int *A, int p, int r){
    if (p < r) {
        int pivot = PARTITION(A, p, r);
        QUICKSORT(A, p, pivot - 1);
        QUICKSORT(A, pivot + 1, r);
    }
}


int main(){

    ifstream input( "input.txt" );
    ofstream output( "output.txt" );
   
    int length;
    int array;

    if (input.is_open()){

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
        QUICKSORT(array, 0,length-1);

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

