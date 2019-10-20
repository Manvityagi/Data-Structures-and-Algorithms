#include<bits/stdc++.h>
using namespace std;

void update(int index,int value, int* BIT, int n){
    for(;index <= n; index += (index & (-index)) )
            BIT[index] += value;
}
int query(int index, int* BIT){
    int sum = 0; 
    for(;index > 0; index -= index&(-index))
        sum += BIT[index];
    
    return sum;
}

int main(){
    int n;
    int* arr = new int[n+1]();
    int* BIT = new int[n+1]();
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        update(i,arr[i],BIT,n);
    }
    cout << "Sum  of first 5 elements " << query(5,BIT);
    cout << "Sum  of elts from index 2 to index 6 " << query(6,BIT) - query(1,BIT) << endl; 
    return 0;
    
}