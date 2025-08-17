#include<iostream>
using namespace std; 
int MaximizeTheCuts(int n, int x, int y, int z)
{
    if (n == 0)
    {
        return 0;
    }

    if (n < 0)
    {
        return INT_MIN;
    }

    // MAINE X LENGTH KA ONE SEGMENT I CUT NOW RECURSION WILL SEE
    int option1 = 1 + MaximizeTheCuts(n - x, x, y, z);
    // MAINE Y LENGTH KA ONE SEGMENT I CUT NOW RECURSION WILL SEE
    int option2 = 1 + MaximizeTheCuts(n - y, x, y, z);
    // MAINE Z LENGTH KA ONE SEGMENT I CUT NOW RECURSION WILL SEE
    int option3 = 1 + MaximizeTheCuts(n - z, x, y, z);

    int finalAns = max(option1, max(option2, option3));
    return finalAns;
}

int main() 
{ 
    int N;
    cout << "Enter An Length Of Rode: "; 
    cin >> N;

    int X;
    cout << "Enter Your X Length: " << endl;
    cin >> X;

    int Y;
    cout << "Enter Your Y Length: " << endl;
    cin >> Y;

    int Z;
    cout << "Enter Your Z Length: " << endl;
    cin >> Z;

    int ans = MaximizeTheCuts(N, X, Y, Z);
    cout << "Total Number OF Cut Segments Is: " << ans << endl;
    return 0; 
}