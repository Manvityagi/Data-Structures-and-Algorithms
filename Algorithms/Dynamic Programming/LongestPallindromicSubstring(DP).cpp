/* Given a string, find the longest substring which is palindrome
 (substring that reads the same backwards as forwards)
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s, x;
    cin >> s; // Input the string
    int n = s.length(), i, j, l;
    bool dp[n][n]; // n*n matrix for storing the results of sub-problems.
    memset(dp, 0, sizeof(dp));
    for (i = 0; i < n; i++) // substring with length one is always pallindromic
        dp[i][i] = 1;
    for (i = 0; i < n - 1; i++) // substring of length two having same characters is pallindromic
    {
        if (s[i] == s[i + 1])
            dp[i][i + 1] = 1;
    }
    for (l = 3; l <= n; l++) // The value of dp[i][j] is true, if the substring is palindrome, otherwise false.
    {
        for (i = 0; i < n - l + 1; i++)
        {
            j = i + l - 1;                             // Assigning the right index (starting index is i and length is l)
            if (s[i] == s[j] && dp[i + 1][j - 1] == 1) // To calculate dp[i][j], check the value of dp[i+1][j-1] and if s[i] is same as s[j]
                dp[i][j] = 1;                          // then we make dp[i][j] true otherwise false
            else
                dp[i][j] = 0;
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (dp[i][j] == 1)
            {
                l = j - i + 1;          // Length= right index-left index+1
                if (x.length() < l)     // Find the longest substring
                    x = s.substr(i, l); // x is the substring of length l starting from index i
            }
        }
    }
    cout << x; // Output the Longest Pallindromic Substring
}

/*Time Complexity: O(n^2)
  Space Complexity: O(n^2)
  */