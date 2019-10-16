#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int total_sum;
    int max_suffix_sum;
    int max_prefix_sum;
    int max_sub_sum;

    node(){
        total_sum       = INT_MIN;
        max_suffix_sum  = INT_MIN;
        max_prefix_sum  = INT_MIN;
        max_sub_sum     = INT_MIN;
    }
};

node merge(node left, node right){
        node parentNode;
        parentNode.total_sum = left.total_sum + right.total_sum; 
        parentNode.max_suffix_sum = max(right.max_suffix_sum, right.total_sum + left.max_suffix_sum);
        parentNode.max_prefix_sum = max(left.max_prefix_sum, left.total_sum + right.max_prefix_sum);
        parentNode.max_sub_sum = max(left.max_sub_sum, right.max_sub_sum, left.max_suffix_sum + right.max_prefix_sum);
        return parentNode;

}

void buildTree(int* arr, node* tree, int start, int end, int treeIndex){
        if(start == end)
        {
            tree[treeIndex].total_sum = arr[start];
            tree[treeIndex].max_suffix_sum = arr[start];
            tree[treeIndex].max_prefix_sum = arr[start];
            tree[treeIndex].max_sub_sum = arr[start];
            return;
        }

        int mid = (end+start)/2;
        buildTree(arr,tree,start,mid,2*treeIndex);
        buildTree(arr,tree,mid+1,end,2*treeIndex+1);

        node left = tree[2*treeIndex];
        node right = tree[2*treeIndex+1];
        tree[treeIndex] = merge(left,right);
       
        return;
}


node query(node* tree, int start, int end, int treeIndex, int left, int right){
        //base case - left,right completely out of range of start,end
            if(start > right || end < left){
                node base;
                return base;
            }

        //left right completely inside of start,end
            if(left <= start && right >= end)
                return tree[treeIndex];

        //partially 
        int mid = start + (end - start)/2;
        node leftans = query(tree,start,mid,2*treeIndex,left,right);
        node rightans = query(tree,start,mid,2*treeIndex+1,left,right);
        node ans = merge(leftans,rightans);
        return ans;
}

void update(int* arr,node* tree, int start, int end, int treeIndex, int idx, int val){
        //base case - left,right completely out of range of start,end
            if(start == end){
                 arr[idx] = val;
                 tree[treeIndex].total_sum = arr[start];
                 tree[treeIndex].max_suffix_sum = arr[start];
                 tree[treeIndex].max_prefix_sum = arr[start];
                 tree[treeIndex].max_sub_sum = arr[start];
                     return;
            }

        //partially 
        node leftans,rightans;
        int mid = start + (end - start)/2;
        if(idx <= mid)
            leftans = query(tree,start,mid,2*treeIndex,idx,val);
        else
            rightans = query(tree,start,mid,2*treeIndex+1,idx,val);

        node ans = merge(leftans,rightans);
        
}


int main(){
    int arr[] = {-1,3,2,-5,6,7,-8,9};
    node* tree = new node[24];

    buildTree(arr,tree,0,0,1);

    for(int i = 0; i < 18; i++)
        cout << tree[i].total_sum << " " << tree[i].max_suffix_sum << tree[i].max_prefix_sum << tree[i].max_sub_sum << endl;
    
    int left = 1,right = 4;
    node ans = query(tree,0,0,1,left,right);
    cout << ans.max_sub_sum; 

}