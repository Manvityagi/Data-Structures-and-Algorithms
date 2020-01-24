#include <bits/stdc++.h>
using namespace std;

//lexicographically sorted
void permute(string s, int i, int n){
    if(i == n){
        cout << s << " ";
        return;
    }

    for(int j = i; j < n; j++){
        swap(s[j],s[i]);
        sort(s.begin()+i+1,s.end());
        permute(s,i+1,n);
        swap(s[j],s[i]);
    }
}

int main()
{
   string s;
   cin >> s;
   sort(s.begin(),s.end());
   permute(s,0,s.size()-1);
}