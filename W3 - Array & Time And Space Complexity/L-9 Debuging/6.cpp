// 6. Debug the code. List all triplets in array that sums to X.

#include<iostream>
using namespace std;

int tripletSumToX(int input[], int size, int x){
	int triplets = 0;
	for(int i=0; i<size; i++){
		for(int j=i + 1; j<size; j++){
			for(int k=j+ 1; k<size; k++){
				if(input[i] + input[j] + input[k] == x) triplets++;
			}
		}
	}
	return triplets;
}

int main() 
{ 
    cout << "" << endl; 
    return 0; 
}


// Here J start from i + 1 and k start from j + 1