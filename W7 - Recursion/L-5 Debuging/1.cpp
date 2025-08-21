// 1. Debug the code.

bool isPowerOfFour(int n)
{
    if (n <= 0)
    {
        return false;
    }
    if (n == 1)
    {
        return true;
    }
    if (n % 4 != 0)
    {
        return false;
    }

    return isPowerOfFour(n / 4);
}

// IN THIS CODE LITEL CHANGE IN CONDITIONS I'L FIX IT AND ALL SET