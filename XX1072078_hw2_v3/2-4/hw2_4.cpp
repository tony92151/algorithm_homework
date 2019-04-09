
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

// reference https://blog.gtwang.org/programming/measure-the-execution-time-in-c-language/2/

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

struct timespec diff(struct timespec start, struct timespec end) {
  struct timespec temp;
  if ((end.tv_nsec-start.tv_nsec)<0) {
    temp.tv_sec = end.tv_sec-start.tv_sec-1;
    temp.tv_nsec = 1000000000+end.tv_nsec-start.tv_nsec;
  } else {
    temp.tv_sec = end.tv_sec-start.tv_sec;
    temp.tv_nsec = end.tv_nsec-start.tv_nsec;
  }
  return temp;
}

int main(){

    ifstream input( "random.txt" );
    ofstream output( "result.txt" );
   
    int length = 10000;
    int array;

    struct timespec start, end;
    double time_used,time_used2;

    if (input.is_open()){

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


        cout<<"******************** QUICKSORT ********************"<<"\n";

        clock_gettime(CLOCK_MONOTONIC, &start);

        QUICKSORT(array, 0,length-1);

        clock_gettime(CLOCK_MONOTONIC, &end);

        struct timespec temp = diff(start, end);

        time_used = temp.tv_nsec;
        cout<<"cost : "<< time_used <<" nanosecond"<<"\n"<<"\n";
        
        ///////////////////////////////////////////////////////////////////////

        cout<<"******************** InsertionSort ********************"<<"\n";

        clock_gettime(CLOCK_MONOTONIC, &start);

        InsertionSort(array2, length);

        clock_gettime(CLOCK_MONOTONIC, &end);

        struct timespec temp2 = diff(start, end);

        time_used2 = temp2.tv_nsec;
        cout<<"cost : "<< time_used2 <<" nanosecond"<<"\n"<<"\n";

        //store result in result.txt
        cout<<"store result in result.txt\n";
        count = 0;
        output << "QUICKSORT use : "<< time_used << " nanosecond"<<"\n";
        output << "InsertionSort use : "<< time_used2 << " nanosecond"<<"\n";
        cout<<"Done\n";
    }

}

