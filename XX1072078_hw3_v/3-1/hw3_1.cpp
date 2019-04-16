
/**
 *  Name : hw3
 *
 *  Author : Tony Guo
 *  
 *  Country : Taiwan
 *
 *  Date : 16 April, 2019 
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

int RANDOMIZED_PARTITION(int *A, int p, int r){
    srand(5);
    int i = p + rand()%(r-p+1);
    swap(&A[i], &A[r]);
    return PARTITION(A,p,r);
}


int RANDOMIZED_SELECT(int *A,int p,int r,int i){
    if(p==r){
        return A[p];
    }
    int q =  RANDOMIZED_PARTITION(A,p,r);
    int k = q - p + 1;
    if(i==k){
        return A[q+1];
    }
    else if (i<k){
        return RANDOMIZED_SELECT(A,p,q-1,i);
    }
    else{
        return RANDOMIZED_SELECT(A,q+1,r,i-k);
    }
}


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


        //copy to another array
        int array2[length];
        count = 0;
        while (count < length){
            array2[count] = array[count];
            count++;
        } 

        //display array
        cout<<"Array : ";
        for(int i = 0; i < length; i++) cout<<array[i]<<"  ";
        cout<<"\n";

        //SELECT
        int result = RANDOMIZED_SELECT(array, 1,20,3);

        //result
        cout<<"Find 3th small number\n";
        cout<<"Result : ";
        cout <<  result <<"\n";

        //use InsertionSort to comform
        InsertionSort(array2, length);


        //result
        cout<<"New array : ";
        for(int i = 0; i < length; i++) cout<<array2[i]<<"  ";
        cout<<"\n";
        
    }

}

