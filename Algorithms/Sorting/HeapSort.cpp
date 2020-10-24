#include <iostream>
#include<vector>
using namespace std;

class Heap {
    vector<int> v;
    bool minHeap;

    bool compare(int a, int b){
        if(minHeap == true){
            return a < b;
        }
        return a > b;
    }

    void heapify(int idx){
        //find the left and right children of the idx
        int left = 2*idx;
        int right = 2*idx + 1;

        //compare
        int last_idx = v.size() - 1;
        int min_idx = idx;

        //if left exists and _
        if(left <= last_idx && compare(v[left],v[min_idx]) ){
            min_idx = left;
        }
        //similarly for right
        if(right <= last_idx && compare(v[right],v[min_idx] ) ){
            min_idx = right;
        }

        //recuresive and base case
        if(min_idx != idx){
            swap( v[min_idx],v[idx] );
            heapify(min_idx);
        }
    }
public:
    //Constructor
    Heap(int default_size = 10, bool type = true) {  //these are the default parameters
        v.reserve(default_size);   //vector size defined, example if it is 10, it will not expand before the vector is filled upto 10 elements
        minHeap = type;  //if true -> minheap, if false -> maxHeap
        //block the 0th index
        v.push_back(-1);
    }      

    //Insertion in heap
    void push(int d){
        //1. Insert the element at the end of the vector
        v.push_back(d);

        //2. Comparison
        //the index of the element inserted -> idx
        int idx = v.size() - 1;
        //parent of this index = idx/2
        int parent = idx/2;
        
        //keep pushing to the top till you reach the root node OR stop midway because current element is already greater (in case of minheap) than the parent
        while(idx > 1 && compare(v[idx],v[parent])){
            swap(v[idx],v[parent]);
            //update
            idx = parent;
            parent = parent/2;
        }
    }

    bool empty(){
        return v.size() == 1; //because we blocked the 0th postion so size should atleast be 2, size =1 1 means heap is empty
    }

    int top(){   //get function
        return v[1];
    }

    void pop(){
        //step 1. swap v[1] (root) and v[last]
        int last = v.size() - 1;
        swap(v[1] , v[last]);
        //step 2. remove the last node
        v.pop_back();
        //step 3. restore the heap using heapify function
        heapify(1);  // start from the root node
    }
};

int main(){
    //give some heap size and type(minheap / maxheap)
    Heap h;  //by default size = 10, type = minheap(by default)
    //to make max heap  --> Heap h(10,false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int no;
        cin >> no;
        h.push(no); 
    }

    //remove all the elements one by one
    while(!h.empty()){
        cout << h.top() << " ";
        h.pop();
    }

    return 0;
}