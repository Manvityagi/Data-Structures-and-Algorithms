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

void updateSegmentTreeLazy(int* tree, int* lazy, int treeIndex, int start, int end, int qs, int qe, int inc){
            //base case
            if(start > end || qs > qe) return;
            //update tree a/c to lazy tree before moving on to other operations
            if(lazy[treeIndex] != 0){
                tree[treeIndex] += lazy[treeIndex];
                if(start != end){
                    lazy[2*treeIndex] += lazy[treeIndex];
                    lazy[2*treeIndex+1] += lazy[treeIndex];
                }
                lazy[treeIndex] = 0;
            }
            //no overlap
            if(qe < start || qs > end)
                return;
            //complete overlap
            if(qs <= start && qe >= end){
                tree[treeIndex] += inc;
                if(start != end){
                    lazy[2*treeIndex] += inc;
                    lazy[2*treeIndex+1] += inc; 
                }
                return;
            }
            //partial overlap
            int mid = (start + end )/2;
            updateSegmentTreeLazy(tree,lazy,2*treeIndex,start,mid,qs,qe,inc);
            updateSegmentTreeLazy(tree,lazy,2*treeIndex+1,mid+1,end,qs,qe,inc);
            tree[treeIndex] = tree[2*treeIndex] + tree[2*treeIndex+1];
}

int query(int* tree, int* lazy, int s, int e, int treeIndex, int left, int right){
    if(s > right || e < left)
        return 0;

     if(lazy[treeIndex] != 0){
                tree[treeIndex] += lazy[treeIndex];
                if(s != e){
                    lazy[2*treeIndex] += lazy[treeIndex];
                    lazy[2*treeIndex+1] += lazy[treeIndex];
                }
                lazy[treeIndex] = 0;
            }

    if(left <= s && right >= e)
        return tree[treeIndex];
    
    int mid = s + (e-s)/2;
    int ans1 = query(tree,lazy,s,mid,2*treeIndex,left,right);
    int ans2 = query(tree,lazy,mid+1,e,2*treeIndex+1,left,right);

    return ans1+ans2;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int* tree = new int[18];

    buildTree(arr,tree,0,8,1);

    for(int i = 1; i <= 18; i++)
        cout << tree[i] << endl;

    // update(arr,tree,0,8,4,10,1);

    
    // for(int i = 1; i <= 18; i++)
    //     cout << tree[i] << endl;

    // cout << query(tree,0,8,1,2,7);

}