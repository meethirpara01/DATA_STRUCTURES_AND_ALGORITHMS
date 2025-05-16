#include<iostream>
#include<cmath>
#include<vector>
using namespace std; 

void ConvertTemp(int celsius)
{
    double k = celsius + 273.15;
    double f = celsius * 1.80 + 32.00;

    vector<double>v;
    v.push_back(k);
    v.push_back(f);

    cout << v.at(0) << endl;
    cout << v.at(1) << endl;
}

int main() 
{
    double celsius;
    cout << "Enter a celsius : " << endl;
    cin >> celsius;

    ConvertTemp(celsius);

    return(0); 
}