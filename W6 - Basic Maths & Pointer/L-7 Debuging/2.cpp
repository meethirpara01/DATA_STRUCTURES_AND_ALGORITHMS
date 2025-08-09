// 2. Debug the code.

#include<iostream>
using namespace std; 

void fillPrimes(vector<int>& prime, int high)
{
    vector<bool> ck(high+1, true);
    ck[1] = false;  // HERE IS ISUE
    ck[0] = false;  // HERE IS ISUE
    for (int i = 2; (i * i) <= high; i++) {
        if (ck[i] == true) {
            for (int j = i * i; j <= sqrt(high); j = j + i) {
                ck[j] = false;
            }
        }
    }
    for (int i = 2; i * i <= high; i++) {
        if (ck[i] == true) {
            prime.push_back(i);
        }
    }
}

void segmentedSieve(int low, int high)
{
    if (low<2 and high>=2){
        low = 2;
    }
    vector<bool> prime(high-low+1, true);
    vector<int> chprime;
    fillPrimes(chprime, high);
    for (int i : chprime) {
        int lower = (low / i);
        if (lower <= 1) {
            lower = i + i;
        }
        else if (low % i) {
            lower = (lower * i) + i;
        }
        else {
            lower = (lower * i);
        }
        for (int j = lower; j <= high; j = j + i) {
            prime[j - low] = false;   // HERE IS ISUE
        }
    }
   
    for (int i = low; i <= high; i++) {
        if (prime[i - low] == true) {   // HERE IS ISUE
            cout << (i) << " ";
        }
    }
}

int main() 
{ 
    int low;
    cout << "Enter Number: " << endl; 
    cin >> low;

    int high;
    cout << "Enter Number: " << endl; 
    cin >> high;

    segmentedSieve(low, high);

    return 0; 
}