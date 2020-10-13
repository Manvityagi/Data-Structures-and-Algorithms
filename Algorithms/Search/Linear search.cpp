#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, i;
    cin >> n;
    int a[n];
    for (i = 0; i < n; i++)
        cin >> a[i];
    int x;
    cin >> x;
    // To check if x is present in the array
    for (i = 0; i < n; i++)
    {
        if (a[i] == x) // if element is found then break the loop
            break;
    }

    if (i == n)
        cout << "Element not found" << endl;
    else
        cout << "Element found at index = " << i << endl;

    return 0;
}
