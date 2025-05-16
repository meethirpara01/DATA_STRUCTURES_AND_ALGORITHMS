// 5. Debug the code. List all pairs in array that sums to X.

#include<iostream>
using namespace std;

int pairSumToX(int input[], int size, int x){
	int pairs = 0;
	for(int i=0; i<size; i++){
		for(int j=i + 1; j<size; j++){
			if(input[i] + input[j] == x) pairs++;
		}
	}
	return pairs;
}

int main() 
{ 
    cout << "" << endl; 
    return 0; 
}
// Here J Start From (I+ 1) Not i