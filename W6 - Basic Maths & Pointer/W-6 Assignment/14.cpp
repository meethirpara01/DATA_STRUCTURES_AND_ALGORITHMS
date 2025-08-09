#include<iostream>
using namespace std; 
 
int main() 
{ 
    char s[] = "Hello"; 
    char *p = s;
    cout << s[0] << " " << p[0] << endl;
    
    return 0; 
}