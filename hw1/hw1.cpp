
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


void MergeSort(int A[],int p,int q);
void Merge(int A[], int p, int q, int m);


int main(){

    ifstream input( "input.txt" );
    ofstream output( "output.txt" );
   
    int leagth;
    int array;

    if (input.is_open()){
        bool first = true;

        //read first line to get length
        input >> leagth;
        cout<<"Length:" << leagth <<"\n";

        //define array length
        int *array = new int [leagth];

        //read each number in array
        int count = 0;
        while (count < leagth && input >> array[count]) count++;

        //display array
        cout<<"old array : ";
        for(int i = 0; i < leagth; i++) cout<<array[i]<<"  ";
        cout<<"\n";

        //sort
        MergeSort(array, 0, 10);

        //display new array
        cout<<"new array : ";
        for(int i = 0; i < leagth; i++) cout<<array[i]<<"  ";
        cout<<"\n";

        //store new array in optput.txt
        cout<<"store new array in optput.txt\n";
        count = 0;
        while (count < leagth && output << array[count]){
            output << " ";
            count++;
        }
        cout<<"Done\n";


    }

}

void MergeSort(int A[], int p, int r) {
	if (p < r) {
		int h = (p+r)/2;//half
		MergeSort(A, p, h);
		MergeSort(A, h+1, r);
		Merge(A, p, r, h);
	}
}

void Merge(int A[], int p, int q, int r) {
	int n1 = r - p + 1;
	int n2 = q - r;

    //new array
	int *L = new int[n1];
	int *R = new int[n2];

	for (int i = 0; i < n1; i++) {
		L[i] = A[p+i]; 
	}
	for (int i = 0; i < n2; i++) {
		R[i] = A[i+r+1]; 
	}

	L[n1] = 2147483647;//INF
	R[n2] = 2147483647;//INF

	int i = 0, j = 0;
	for (int k = p; k <= q; k++) {
		if (L[i] <= R[j]) {
			A[k] = L[i];
			i++;
		}
		else {
			A[k] = R[j];
			j++;
		}
	}
}


