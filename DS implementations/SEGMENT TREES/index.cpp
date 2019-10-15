#include<bits/stdc++.h>
using namespace std;

void buildTree(int* arr, int* tree, int start, int end, int treenode)
{
    //base case
    if(start == end)
    {
        tree[treenode] = arr[start];
        return;
    }

    int mid = start + (end-start)/2;

    buildTree(arr,tree,start,mid,2*treenode);
    buildTree(arr,tree,mid+1,end,2*treenode+1);

    tree[treenode] = tree[2*treenode] + tree[2*treenode+1];
}

void update(int* arr, int* tree, int s, int e, int idx, int value, int TN){
    if(s == e){
        arr[idx] = value;
        tree[TN] = value;
        return;
    }

    int mid = s + (e-s)/2;

    if(idx > mid)
        update(arr,tree,mid+1,e,idx,value,2*TN+1);
    else
        update(arr,tree,s,mid,idx,value,2*TN);
    
    tree[TN] = tree[2*TN] + tree[2*TN+1]; 
}

int query(int* tree,int s, int e, int TN, int left, int right){
    if(s > right || e < left)
        return 0;
    
    if(left >= s && right <= e)
        return tree[TN];
    
    int mid = s + (e-s)/2;
    int ans1 = query(tree,s,mid,2*TN,left,right);
    int ans2 = query(tree,mid+1,e,2*TN+1,left,right);

    return ans1+ans2;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int* tree = new int[18];

    buildTree(arr,tree,0,8,1);

    for(int i = 1; i <= 18; i++)
        cout << tree[i] << endl;

    update(arr,tree,0,8,4,10,1);

    
    for(int i = 1; i <= 18; i++)
        cout << tree[i] << endl;

    cout << query(tree,0,8,1,2,7);

}