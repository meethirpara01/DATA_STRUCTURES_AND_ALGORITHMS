// Debug the code. 
// It is trying to print the given pattern.


/*
Pattern
N = 5
E
DE
CDE
BCDE
ABCDE
*/
#include<iostream>
using namespace std;

int main() {
    int i,j,n;;
    cin>>n;
    char p='A'- n;
    for(i=1;i<=n;i++){
        for(j=1;j<=i;j++){
            cout<<p;
            p--;  
        }
        cout<<endl;
    }

    cout << 'A' - 2 <<endl ;
}