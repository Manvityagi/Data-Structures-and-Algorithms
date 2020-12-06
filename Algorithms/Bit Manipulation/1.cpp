//BIT MANIPULATION BASICS
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i;
    cin >> i;
    int x = 10, f = 0, a = 0;
    bool powerOf2, ithBitActive;

    /*                                    Check if x is power of 2?                                  */
    if (__builtin_popcount(x) == 1)
        powerOf2 = 1;
    else
        powerOf2 = 0;

    if (x && !((x & (x - 1))))
        powerOf2 = 1;
    else
        powerOf2 = 0;






    /*                                     Check if ith bit is active or not                                  */
    if (x >> i & 1)
        ithBitActive = 1;
    else
        ithBitActive = 0;








    /*                          To make ith bit active (bits current state doesn't matter)                                  */

    if (!(x >> i & 1))
        x += (1 << i);
    //  101 - 0 - 10
    //  000   1   00
    x |= (1 << i);








    /*                                       To flip ith bit                                  */
    // 5 -> 101 -> flip -> 00000000000000000000101 |
    x ^= (1 << i);

    return 0;
}