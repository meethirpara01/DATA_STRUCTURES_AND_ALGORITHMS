#include <iostream>
#include <string.h>
using namespace std;
int LenthOfString(char ch[], int size)
{
    int index = 0;
    int count = 0;
    while (ch[index] != '\0')
    {
        count++;
        index++;
    }
    return count;

    // int length = 0;
    // for (int i = 0; i < size; i++)
    // {
    //     if (ch[i] == '\0')
    //     {
    //         // ruk jao
    //         break;
    //     }
    //     else
    //     {
    //         length++;
    //     }
    // }
    // return length;
}

void ReverseString(char ch[], int len)
{
    int start = 0;
    int end = len - 1;
    while (start < end)
    {
        swap(ch[start], ch[end]);
        start++;
        end--;
    }
    cout << "After Reverse: " << ch << endl;
}

int main()
{
    char ch[10];
    cout << "Enter String: " << endl;
    cin.getline(ch, 10);

    ReverseString(ch, LenthOfString(ch, 10));
    return 0;
}