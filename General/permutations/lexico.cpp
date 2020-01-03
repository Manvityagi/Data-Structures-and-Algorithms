#include<bits/stdc++.h>
using namespace std;

int factorial(int n) 
{ 
    // single line to find factorial 
    return (n==1 || n==0) ? 1: n * factorial(n - 1);  
} 
  
int main(){
    string s;
    cin >> s;

    vector<string> output;
    sort(s.begin(),s.end());
    output.push_back(s);

    int anscount = factorial(s.size());

    for(int i = 1; i < anscount; i++){
        //previously printed string 
        string prev = output[i-1];
    }
}