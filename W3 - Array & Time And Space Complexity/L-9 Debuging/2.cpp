// 2. Debug the code. Linear Search.

#include<iostream>
using namespace std;

bool linearSearch(int arr[], int n ,int val){
    for(int i=0;i<n;i++){
        if(arr[i]==val){
            return true;
        }
    }
    return false;
}
 
int main() 
{ 
    cout << "" << endl; 
    return 0; 
}


// Here Is Mistake In Return Type 