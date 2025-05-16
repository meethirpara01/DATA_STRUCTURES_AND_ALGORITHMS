#include<iostream>
#include<cmath>
using namespace std; 

float KmToMiles(int Km)
{
    float _1KmMiles = 0.621371;
    float Miles = Km * _1KmMiles;

    return Miles;
}

int main() 
{
    float Km;
    cout << "Enter a KM : " << endl;
    cin >> Km;

    float miles = KmToMiles(Km);
    cout << "YOUR MILES IS : " << miles << endl;

    return(0); 
}