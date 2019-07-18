#include <stdio.h>

int pow1(int base, int n)
{
    int res = 1;
    for (int i = 0; i < n; ++i)
        res *= base;
    return res;    
}

int pow2(int base, int n)
{
    if (n == 0)
        return 1;
    int res = pow2(base, n / 2);
    res *= res;
    if (n % 2)
        res *= base;

    return res;    
}

int pow3(int base, int n)
{
    int res = 1;
    int InPowerOf2 = base;
    while (n > 0)
    {
        if (n & 1 == 1)
            res *= InPowerOf2;
    
        InPowerOf2 *= InPowerOf2;
        n = n >> 1;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    for (int i = 0; i < 10000; ++i)
        for (int j = 0; j < 10000; ++j)
        {
            //pow1(i, j);
            pow2(i, j);
            pow3(i, j);
        }
    return 0;
}