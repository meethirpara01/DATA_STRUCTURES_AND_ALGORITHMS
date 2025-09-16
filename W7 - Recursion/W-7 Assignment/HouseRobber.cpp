#include<iostream>
using namespace std; 

int robberHouse(vector<int>& homes, int i) 
{
    // BASE CASE
    if (i >= homes.size())
        return 0;

    // PROCCESSING
    int way1 = homes[i] + robberHouse(homes, i + 2);
    int way2 = 0 + robberHouse(homes, i + 1);

    return max(way1, way2);
}

int robber(vector<int>& homes)  
{
    return robberHouse(homes, 0);;
}

int main() 
{ 
    int size;
    cout << "Enter An Size Of Array: "; 
    cin >> size;

    vector<int> homes(size);
    for (int i = 0; i < size; i++)
    {
        cout << "Enter Element " << i + 1 << " Of Array: ";
        cin >> homes[i];
    }

    int ans = robber(homes);
    cout << "Maximum Money Can Collacte Form This Robbery: " << ans << endl;
    return 0; 
}