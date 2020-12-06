#include<bits/stdc++.h>
using namespace std; 

class hashmap{
    int size;
    struct node{
        int key;
        int value; 
        node(int key = -1, int value = -1) : key(key), value(value){} 
    }; 
    node* arr; 

    public:
    hashmap(int size = 512){
        this->size = size; 
        this->arr = new node[size]; 
    }

    int hash(int key){
        return (key*key)%size;
    }

    void add(int key, int value){
        int index = hash(key); 
        arr[index] = key; 
    }

    int get(int key){
        int index = hash(key); 
        if(arr[index].key == key) return arr[index].value;
        return -1; 
    }
}; 

int main(){
    return 0; 
}