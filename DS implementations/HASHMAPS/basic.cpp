#include<bits/stdc++.h>
using namespace std; 

class Hashmap{
    int size; 
    struct node{
        int key; 
        int value; 
        node(int key = -1, int value = -1) : key(key), value(value){}
    };
    node *arr;
    public:
    Hashmap(int size = 512){
        this->size = size;
        this->arr = new node[size]; 
    }

    int hash(int key){
        return (key*key)%size; //return index on which given key has to be placed
    }

    void add(int key, int value){
        int index = hash(key);
        arr[index] = node(key,value); 
    }

    int get(int key){
        int index = hash(key); 
        if(arr[index].key == key){
            return arr[index].value;
        }
        cout << "Collison or Wrong Key\n";
        return -1; 
    }

}; 

int main(){
    // Hashmap *H = new Hashmap;
    Hashmap H; 
    H.add(12,100);
    H.add(15,200);
    cout << H.get(12) << "\n";
    cout << H.get(15) << "\n";
    cout << H.get(2) << "\n";
    
}