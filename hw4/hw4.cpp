/**
 *  Name : hw4
 *
 *  Author : Tony Guo
 *  
 *  Country : Taiwan
 *
 *  Date : 14 May, 2019 
 * 
 *  github : https://github.com/tony92151/algorithm_homework
 */


#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int knapsack(int W[],int i,int w,int V[],int v){ // i = length , w = maxWeight
    //int remain = w;
    //int cau = i;
    //int *Re = new int[i];
    //int value = 0; 
    
    if (i<=0 || w<=0) {
        //cout<<"stop!"<<'\n';
        return 0;
    }
    else if (W[i] > w) {
        //i = i-1;
        //cout<<"skip item "<< i <<'\n';
        v = knapsack(W,i-1,w,V,v);
        //return v;
    }
    else if (i>0 && W[i] < w){
        //cout<<"choose A"<<'\n';
        //i = i-1;
        int value1 = knapsack(W,i-1,w ,V,v);             // not choose this item
        //w = w-W[i];
        //cout<<"choose B"<<'\n';
        //cout<<"i = "<<i-1<<", v = "<<V[i-1]<<'\n';
        int value2 = V[i-1] + knapsack(W,i-1,w-W[i],V,v);  // choose this item
        v = max(value1,value2);
        //cout<<"v max = "<<v<<'\n';
        //return v;  
    }
    //cout<<"v = "<<v<<'\n';
    return v;
}

int main(){

    int length = 6;

    int maxWeight = 15;

    int Items[6] = {1, 2, 3, 4, 5 ,6 };
    int weight[6] = {4, 4, 5, 3, 6, 1 };
    int value[6] = {5, 1, 3, 3, 2, 7 };

    int v = 0;

    cout<<"Items  : ";
    for(int i = 0; i < length; i++) cout<<Items[i]<<"  ";
    cout<<'\n';
    cout<<"weight : ";
    for(int i = 0; i < length; i++) cout<<weight[i]<<"  ";
    cout<<'\n';
    cout<<"value  : ";
    for(int i = 0; i < length; i++) cout<<value[i]<<"  ";
    cout<<'\n';

    v = knapsack(weight,length,maxWeight,value,v);

    cout<<'\n'<<"Max Value = "<< v <<'\n';
    
}
