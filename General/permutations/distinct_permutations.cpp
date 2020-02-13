#include <bits/stdc++.h>
using namespace std;

int factorial(int n)
{
    // single line to find factorial
    return (n == 1 || n == 0) ? 1 : n * factorial(n - 1);
}

vector<string> lexpermute(string s)
{
    vector<string> output;
    int n = s.size();
    char first_char, sec_char;
    sort(s.begin(), s.end());
    output.push_back(s);
    int anscount = factorial(s.size()), fc_pos, sc_pos;

    for (int i = 1; i < anscount; i++)
    {
        //previously printed string
        string prev = output[i - 1];

        //find rightmost character which is smaller than its next character
        for (int i = n - 2; i >= 0; i--)
        {
            if (prev[i] < prev[i + 1])
            {
                first_char = prev[i];
                fc_pos = i;
                break;
            }
        }

        //find second char // smallest character greater than first character
        sec_char = first_char;
        for (int i = fc_pos + 1; i < n; i++)
        {
            if (prev[i] < sec_char && prev[i] > first_char)
            {
                sec_char = prev[i];
                sc_pos = i;
            }
        }

        //swap fc & sc
        swap(prev[fc_pos], prev[sc_pos]);

        //sort the substring after fc original index
        sort(prev.begin() + fc_pos + 1, prev.end());
        output.push_back(prev);
    }

    return output;
}

int main()
{
    string s;
    cin >> s;

    vector<string> output = lexpermute(s);

    for(auto a : output){
        cout << a << " ";
    }
}