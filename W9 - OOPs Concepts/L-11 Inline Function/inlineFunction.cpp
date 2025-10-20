#include <iostream>
using namespace std;

inline void inlineFunction(int num)
{
    cout << num << endl;
}

int main()
{
    inlineFunction(5);
    inlineFunction(5);
    inlineFunction(5);
    inlineFunction(5);
    inlineFunction(5);
    inlineFunction(5);
    inlineFunction(5);
    inlineFunction(5);
    inlineFunction(5);
    inlineFunction(5);
    inlineFunction(5);

    return 0;
}