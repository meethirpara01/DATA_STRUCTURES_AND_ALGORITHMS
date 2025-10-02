#include <iostream>
using namespace std;
class abc
{
    public:
        int x;
        int y;

    abc(int _x, int _y)
    {
        x = _x;
        y = _y;
        cout << x << " " << y << endl;
    }
};

int main()
{
    abc s1(2, 4);
    return 0;
}