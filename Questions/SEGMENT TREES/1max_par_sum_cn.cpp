#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int max;
    int smax;
};

void buildTree(int* arr, node* tree, int start, int end, int treeIndex){
        if(start == end)
        {
            tree[treeIndex].max = arr[start];
            tree[treeIndex].smax = INT_MIN;
            return;
        }

        int mid = (end+start)/2;
        buildTree(arr,tree,start,mid,2*treeIndex);
        buildTree(arr,tree,mid+1,end,2*treeIndex+1);

        node left = tree[2*treeIndex];
        node right = tree[2*treeIndex+1];

        tree[treeIndex].max = max(left.max,right.max); 
        tree[treeIndex].smax = min(max(left.max,right.smax),max(left.smax,right.max)); 
        return;
}


node query(node* tree, int start, int end, int treeIndex, int left, int right){
        //base case - left,right completely out of range of start,end
            if(start > right || end < left){
                node base;
                base.max = INT_MIN;
                base.smax = INT_MIN;
                return base;
            }

        //left right completely inside of start,end
            if(left == start && right == end)
                return tree[treeIndex];

        //partially 
        int mid = start + (end - start)/2;
        node leftans = query(tree,start,mid,2*treeIndex,left,right);
        node rightans = query(tree,mid+1,end,2*treeIndex+1,left,right);

        node ans;
        ans.max = max(leftans.max,rightans.max);
        ans.smax = min(max(leftans.max,rightans.smax),max(leftans.smax,rightans.max));

        return ans;

}

void update(int* arr, node* tree, int start, int end, int treeIndex, int idx, int val){
    if(start == end){
        arr[idx] = val;
        tree[treeIndex].max = val;
        tree[treeIndex].smax = INT_MIN;
        return;
    }

    int mid = (start+end)/2;

    if(idx > mid)
        update(arr,tree,mid+1,end,idx,val,2*treeIndex+1);
    else
        update(arr,tree,start,mid,idx,val,2*treeIndex);
    
        node left = tree[2*treeIndex];
        node right = tree[2*treeIndex+1];

        tree[treeIndex].max = max(left.max,right.max); 
        tree[treeIndex].smax = min(max(left.max,right.smax),max(left.smax,right.max)); 
        return;
}

int main(){
    int arr[] = {2,3,1,4,7,6};
    node* tree = new node[18];

    buildTree(arr,tree,0,0,1);

    for(int i = 0; i < 18; i++)
        cout << tree[i].max << " " << tree[i].smax << endl;
    
    // int left = 1,right = 4;
    // node ans = query(tree,0,0,1,left,right);
    // cout << "Maximum Pair " << ans.max << " " << ans.smax << endl; 

    // int idx = 2, val = 10;
    // update(arr,tree,0,0,1,idx,val);

    // for(int i = 0; i < tree.size(); i++)
    //     cout << tree[i].max << tree[i].smax << endl;

    // ans = query(tree,0,0,1,left,right);
    // cout << "Maximum Pair " << ans.max << " " << ans.smax; 
}