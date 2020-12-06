#include<bits/stdc++.h>
using namespace std; 

class Hashmap{
    int size; 
    struct node{
        int key; 
        int value; 
        node(int key = -1, int value = -1) : key(key), value(value){}
    };
    list<node> *arr;
    public:
    Hashmap(int size = 512){
        this->size = size;
        this->arr = new list<node>[size]; 
    }

    int hash(int key){
        return (key*key)%size; //return index on which given key has to be placed
    }

    void add(int key, int value){
        int index = hash(key);
        arr[index].emplace_back(key,value); 
    }

    int get(int key){
        int index = hash(key); 
        for(auto p : arr[index]){
            if(p.key == key) return p.value;
        }
        return -1; 
    }
}; 

int main(){
    // Hashmap *H = new Hashmap;
    Hashmap H(5); 
    H.add(12,100);
    H.add(18,200);
    cout << H.get(12) << "\n";
    cout << H.get(18) << "\n";
    cout << H.get(2) << "\n";
    
}