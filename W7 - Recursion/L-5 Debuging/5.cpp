// 5. Debug the code.
#include <iostream>
using namespace std;

void removeConsecutiveDuplicates(char *input)
{
    if (input[0] == '\0')
    {
        return;
    }
    if (input[0] == input[1])
    {
        int i = 2;
        for (; input[i] != '\0'; i++)
        {
            input[i - 1] = input[i];
        }
        input[i - 1] = input[i];
        removeConsecutiveDuplicates(input);
    }
    else
    {
        removeConsecutiveDuplicates(input + 1);
    }
}
/*
Example:
xxab --> xab
*/

// IN THIS CODE YOU SHOULD ADD ELSE CONDITION
