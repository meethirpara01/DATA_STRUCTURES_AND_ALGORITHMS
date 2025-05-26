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

int main()
{
    char ch[10];
    cout << "Enter String: " << endl;
    cin.getline(ch, 10);

    int len = LenthOfString(ch, 10); // WE CAN USE OF STRLEN();
    cout << "Lenth Of String: " << len << endl;
    return 0;
}