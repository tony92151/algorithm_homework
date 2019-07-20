#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    
    char array[] = {'b', 'c', 'a', 'a', 'b', 'a', 'b', 'c', 'a', 'a', 'a', 'g', 'c'};
                   //0    1    2    3    4    5    6    7    8    9   10   11   12
    int length = sizeof(array)/sizeof(array[0]);
    
    int resultlength = 0;
    int resulstart = 0;
    char resulchar;
 
	for (int i=length;i>1;i--) {
	    
	    for (int u=0;u<=length-i;u++) {
	        bool allsame = true;
	        for (int r=u;r<u+i-1;r++) {
	            allsame = allsame & (array[r]==array[r+1]);
	            //printf("len:%i  from:%i  wh:%i  T:%d  A:%d \n",i,u,r,(array[r]==array[r+1]),allsame);
	        }
	        //printf("=================================\n");
	        if (allsame && i>resultlength){
    	        resulstart = u;
    	        resultlength = i;
    	        resulchar = array[u];
	        }
	    }
	    
	}
    printf("Result char : %c \n",array[resulstart]);
    printf("Result length : %i \n",resultlength);
    printf("Result from index: %i \n",resulstart);
}
