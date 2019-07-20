#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    
    int array[] = {5,6,9,4,1,8,7,2,3};
    int length = sizeof(array)/sizeof(array[0]);
    
    int where2insert = 4;
    
    //insert 0 into position 4
    //use vector to conquer and combine
    
    vector<int> vec(array, array + length);
    
    cout<<"Before:";
    for (int i: vec) {
		printf("%i ",i);
	}
	
    printf("\nAfter:");
    vec.insert(vec.begin()+where2insert,0);
    for (int i: vec) {
		printf("%i ",i);
	}
	
	cout<<"\nSorted:";
	sort(vec.begin(), vec.end(), greater<int>()); 
	for (int i: vec) {
		printf("%i ",i);
	}

    return 0;
}
