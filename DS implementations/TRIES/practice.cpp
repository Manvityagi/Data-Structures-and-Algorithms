#include<bits/stdc++.h>
using namespace std; 

class Trie{
    struct node{
        bool end; 
        unordered_map<char,node*> child; 
        node() : end(false){}
    }; 
    struct node* root; 
    public: 
    
    void add(string &s){
        node* cur = root; 
        for(char i : s){
            if(cur->child.count(i) == 0) cur->child[i] = new node; 
            cur = cur->child[i];
        }
        cur->end = true;
    }

    bool prefixMatch(string &s){
        node* cur = root; 
        for(char i : s){
            if(cur->child.count(i) == 0) return false; 
            cur = cur->child[i]; 
        }
        return 1;
    }

    bool stringPresent(string &s){
        node* cur = root; 
        for(char i : s){
            if(cur->child.count(i) == 0) return false;
            cur = cur->child[i]; 
        }
        return cur->end;
    }

}; 