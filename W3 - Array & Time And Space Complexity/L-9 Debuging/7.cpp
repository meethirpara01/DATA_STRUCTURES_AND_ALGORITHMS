//7. Debug the code. Sort 0s and 1s

#include<iostream>
using namespace std;

void sort0sand1s(int input[], int size){
	int nextZero = 0;
	for(int i=0; i<size; i++){
		if(input[nextZero] == 0){
			int temp = input[nextZero];
			input[nextZero] = input[i];
			input[i] = temp;
		}
	}
    nextZero++;
}

int main() 
{ 
    cout << "" << endl; 
    return 0; 
}


// Here need to increment nextzero 