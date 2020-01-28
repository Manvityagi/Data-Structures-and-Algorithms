#include <iostream>
#include <unordered_map>
using namespace std;

// Function to determine if given pattern matches with a string or not
bool match(string str, int i, string pat, int j, unordered_map<char, string> &map)
{
    int n = str.size();
    int m = pat.size();

    if (n < m)
        return false;

    // if both pattern and the string reaches end
    if (i == n && j == m)
        return true;

    // if either string or pattern reaches end
    if (i == n || j == m)
        return false;

    //take the curr j as curr
    char curr = pat[j];
    if (map.find(curr) != map.end())
    {
        string s = map[curr];
        int k = s.size();

        //i ke baad agle k characters agar s se match na kare to return false
      	if (str.substr(i, k).compare(s))
			return false;

        return match(str, i + k, pat, j + 1, map);
    }

    for (int k = 1; k <= n - i; k++)
    {
        map[curr] = str.substr(i, k);

        if (match(str, i + k, pat, j + 1, map))
            return true;

        map.erase(curr);
    }

    return false;
}


// main function
int main()
{
    // input string and pattern
    string str = "codesleepcode";
    string pat = "XYX";

    // create a map to store mappings between the pattern and string
    unordered_map<char, string> map;

    // check for solution
    if (match(str, 0, pat, 0, map))
    {
        for (auto entry : map)
        {
            cout << entry.first << ": " << entry.second << endl;
        }
    }
    else
    {
        cout << "Solution doesn't exist";
    }

    return 0;
}