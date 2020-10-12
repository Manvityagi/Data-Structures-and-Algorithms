#include <iostream>
using namespace std;

//implementing counting sort sorting algorithm
void countingSort(int *input_arr,int n,int range){
    int count_arr[range];
    int output_arr[n];
    // initialize all elements to 0 in count array
    for(int i=0;i<range;i++){
    count_arr[i]=0;
    }
     // to take a count of all elements in the input array
    for(int i=0;i<n;i++){
    ++count_arr[input_arr[i]];
    }
     // cummulative count of count array to get the 
 // positions of elements to be stored in the output array
    for(int i=1;i<range;i++){
    count_arr[i]=count_arr[i]+count_arr[i-1];
    }
     // placing input array elements into output array in proper
 //  positions such that the result is a sorted array

    for(int i=0;i<n;i++){
    output_arr[--count_arr[input_arr[i]]]=input_arr[i];
    }
     // copy output array elements to input array
    for(int i=0;i<n;i++){
    input_arr[i]=output_arr[i];
    }
}
int main() {
    int n;
    cin>>n;
    int range=10;
    int input_arr[n+1];
    for(int i=0;i<n;i++){   //taking input array
    cin>>input_arr[i];
    }
    cout<<"Before sorting: ";
    for(int i=0;i<n;i++){
    cout<<input_arr[i]<<" ";
    }
    cout<<endl;
    countingSort(input_arr,n,range);
    cout<<"After sorting: ";
    for(int i=0;i<n;i++){
    cout<<input_arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
