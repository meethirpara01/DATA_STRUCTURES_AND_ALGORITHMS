// Debug the code. 
// It is trying to print the given pattern.

/*
Pattern
1
23
345
4567
*/
#include<iostream>
using namespace std;


int main(){
    int n;
    cin >> n;
    int i=0, count = 1;
    while(i < n){
        int j = 0;
        while(j <= i){
            cout << count;
            j++;
            count++;
        }
        count = j + 1;
        cout<< endl;
        i++;
    }
}

// In this code mistake is condition and count i'l change it and than done.