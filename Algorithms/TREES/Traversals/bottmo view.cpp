#include <bits/stdc++.h>
using namespace std;

map<int,pair<int,int>> mp; 

void helper(Node* root, int hd, int level){
    if(!root) return;
    
    if(mp[hd].second <= level)
        mp[hd] = {root->data,level};
    
    helper(root->left,hd-1,level+1);
    helper(root->right,hd+1,level+1);
}

vector <int> bottomView(Node *root){
    mp.clear();
    vector<int> ans;
    helper(root,0, 0);
    for(auto it : mp) ans.emplace_back(it.second.first);
 
   return ans;
}

