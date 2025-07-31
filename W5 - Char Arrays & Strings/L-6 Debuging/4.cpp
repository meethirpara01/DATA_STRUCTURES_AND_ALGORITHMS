// 4. Debug the code.
#include <iostream>
using namespace std;

void reverseString(char input[], int n, int start)
{
    for (int i = start, j = n - 1 + start; i != j; i++, j--)
    {
        int temp = input[i];
        input[i] = input[j];
        input[j] = temp;
    }
}

void reverseEachWord(char input[])
{
    int start = 0, count = 1, i = 0;
    while (input[i] != 0)
    {
        i++;
        count++;
        if (input[i] == ' ' || input[i] == '\0')
        {
            reverseString(input, count - 1, start);
            start = i + 1;
            count = 0;
        }
    }
}

int main()
{
    int size;
    cout << "Enter Size Of Array :" << endl;
    cin >> size;

    char arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << " Enter " << i + 1 << " Element : ";
        cin >> arr[i];
    }

    reverseEachWord(arr);
    cout << "Your Reverse Array Element Is: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] <<  " ";
    }

    return 0;
}

// PROBLEM IN THIS CONDITION I'L FIX AND ALL SET