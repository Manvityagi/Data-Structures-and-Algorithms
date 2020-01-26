#include <iostream>
using namespace std;

void permutations(string str,int i, int n){
        if(i == n-1){
            cout << str << " ";
            return;
        }

        for(int j = i+1; j < n; j++){
            swap(str[i],str[j]);
            permutations(str,i+1,n);
            swap(str[i],str[j]);
        }
}

int main()
{
    string str = "ABC";

    permutations(str, 0, str.length());

    return 0;
}