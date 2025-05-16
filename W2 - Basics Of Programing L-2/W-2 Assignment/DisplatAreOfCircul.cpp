#include<iostream>
using namespace std; 
void AreaOfCircul(int red)
{
    float ans = 3.14 * red *red;
    cout << "Area Of Ciurcal : " << ans << endl;
}
int main() 
{ 
    float Redius;
    cout << "Enter Redius" << endl; 
    cin >> Redius;
    AreaOfCircul(Redius);
    return 0; 
}