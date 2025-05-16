// 1. Debug the code. Sum of array.

#include<iostream>
using namespace std;

int main(){
    int n, sum;
    cin >> n;
    int input[n];
    for(int i=0;i<n;i++){
        cin >> input[i];
    }
     for(int i=0; i<n; i++){
         sum = sum + input[i];
     }
    cout << sum << endl;
    return 0;
}

// It's An Wrong Statement In Taking Input