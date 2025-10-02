#include <iostream>
using namespace std;

#define PI 3.14159465
#define MAXX(x, y) (x > y ? x : y)


float circleArea(float r)
{
    return PI * r * r;
}

float circlePerimeter(float r)   
{
    return 2 * PI * r;
}

void fun()
{
    int x = 6;
    int b = 17;
    int c = MAXX(x, b);
}

void fun1()
{
    int a = 6;
    int b = 17;
    int c = MAXX(a, b);
}

void fun2()
{
    int y = 6;
    int b = 17;
    int c = MAXX(y, b);
}

int main()
{
    float num;
    cout << "Enter An Number :- " << endl;
    cin >> num;

    cout << "Area Of Circle Is:- " << circleArea(num) << endl;
    cout << "Perimeter Of Circle Is:- " << circlePerimeter(num) << endl;

    return 0;
}