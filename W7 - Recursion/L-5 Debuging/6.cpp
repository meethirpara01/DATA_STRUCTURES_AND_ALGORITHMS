// 6. Debug the code.  Output should be 101 and 104.

#include <iostream>
using namespace std;

void shift(char input[])
{
    int i = 1;
    for (i = 1; input[i] != '\0'; i++)
        input[i - 1] = input[i];
    input[i - 1] = '\0';
}
void removeX(char input[])
{
    if (input[0] == '\0')
        return;
    if (input[0] == 'x')
    {
        shift(input);
        removeX(input);
    }
    else
        removeX(input + 1);
}

/*
Example:
xxab --> ab
*/

// YOU SHOULD ADD CONDITION FOR NULL STRING OTHERWISE IT TRY TO ACCESESS OUT OF RANG CHARECHTER
