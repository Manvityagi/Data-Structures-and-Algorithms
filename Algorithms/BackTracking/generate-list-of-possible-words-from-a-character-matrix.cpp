#include <bits/stdc++.h>
using namespace std;

#define M 3
#define N 4

int row[] = {-1, -1, -1, 0, 1, 0, 1, 1};
int col[] = {-1, 1, 0, -1, -1, 1, 0, 1};

unordered_set<string> ans = {};

bool isSafe(int x, int y, bool processed[][N])
{
    return (x >= 0 && x < M) && (y >= 0 && y < N) &&
           !processed[x][y];
}

int findmaxlen(vector<string> words)
{
    int maxlen = INT_MIN;
    for (auto w : words)
    {
        int len = w.size();
        maxlen = max(maxlen, len);
    }
    return maxlen;
}

bool find(string word, unordered_set<string> dict)
{
    for (auto a : dict)
    {
        if (a == word)
            return true;
    }
    return false;
}

void findWords(char board[M][N], string foundword, unordered_set<string> dict, bool processed[M][N], int x, int y, int maxlen)
{
    if (foundword.size() > maxlen)
        return;
    if (find(foundword, dict))
    {
        ans.insert(foundword);
        foundword = "";
    }

    foundword.push_back(board[x][y]);
    processed[x][y] = true;
    for (int i = 0; i < 8; i++)
    {
        int newx = x + row[i];
        int newy = y + col[i];

        if (isSafe(newx, newy, processed))
        {
            findWords(board, foundword, dict, processed, newx, newy, maxlen);
        }
    }
    processed[x][y] = false;
    foundword.pop_back();
}

void searchBoggle(char board[M][N], vector<string> words)
{
    bool processed[M][N]{};
    int maxlen = findmaxlen(words);
    unordered_set<string> dict;
    for (auto w : words)
    {
        dict.insert(w);
    }
    string foundword = "";
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++)
            findWords(board, foundword, dict, processed, i, j, maxlen);
    }

}

int main()
{
    char board[M][N] = {
        {'M', 'S', 'E', 'F'},
        {'R', 'A', 'T', 'D'},
        {'L', 'O', 'N', 'E'}};

    vector<string> words{"START", "NOTE", "SAND", "STONED"};

    searchBoggle(board, words);
    for (auto a : ans)
    {
        cout << a << " ";
    }

    return 0;
}
