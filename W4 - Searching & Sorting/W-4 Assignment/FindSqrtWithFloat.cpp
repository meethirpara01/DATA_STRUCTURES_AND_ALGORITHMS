#include<iostream>
using namespace std; 

int FindSqrt(int num)
{
    int start = 0;
    int end = num;
    int mid = start + (end - start) / 2;
    int ans = -1;

    while (start <= end)
    {
        if (mid * mid <= num)
        {
            ans = mid;
            start = mid + 1;
        }
        else
            end = mid - 1;
        mid = start + (end - start) / 2;  
    }
    return ans;
}

double FindSqrtWithPoint(int num)
{
    double sqrt = FindSqrt(num);
    double step = 0.1;
    int precision = 10;
    for (int i = 0; i < precision; i++)
    {
        double j = sqrt;
        while (j * j <= num)
        {
            sqrt = j;
            j += step;
        }
        step /= 10;
    }
    return sqrt;
}
int main() 
{ 
    int num;
    cout << "Enter Number: "; 
    cin >> num;

    double ans = FindSqrtWithPoint(num);
    printf("%0.10f", ans);
    cout << endl;
    cout << "Your Answer Is: " << ans << endl;
    return 0; 
}