#include <stdio.h>

// Iterative function to calculate gcd of two numbers
// using euclid's algortihm
int euclid(int a, int b)
{
    int r;

    // the algorithm stops when reaching a zero remainder
    while (b > 0)
    {
        r = a % b;
        // a becomes b and b becomes r (a % b)
        a = b;
        b = r;
    }

    return a;
}


//sahi h ye , chakkar hi ni koi
int gcd(int a, int b)
{
    if (a == 0 || b == 0)
    {
        return a == 0 ? b : a;
    }
    return gcd(a % b, b % a);
}

// main function
int main()
{
    int b = 2740;
    int a = 1760;

    printf("euclid(%d, %d) = %d", a, b, euclid(a, b));

    return 0;
}