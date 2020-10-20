// C++ implementation of Radix Sort

#include <iostream>
using namespace std;
  
// A utility function to get maximum value in arr[]
int maxValue(int *arr,int n){
    int max=arr[0];
    for(int i=1;i<n;i++)
        if(arr[i]>max)
            max=arr[i];
    return max;
}
//implementing counting sort sorting algorithm
void countingSort(int *arr,int n,int div){
    int range=10;
    // initialize all elements to 0 in count array
    int count[range]={0};
    int output[n];
    // to take a count of all elements in the input array
    for(int i=0;i<n;i++){
        count[(arr[i]/div)%10]++;
    }
    // cummulative count of count array to get the
    // positions of elements to be stored in the output array
    for(int i=1;i<range;i++){
        count[i]=count[i]+count[i-1];
    }
    // placing input array elements into output array in proper
    //  positions such that the result is a sorted array

    for(int i=0;i<=n-1;i++){
        output[count[(arr[i]/div)%10]-1]=arr[i];
        count[(arr[i]/div)%10]--;
    }
    // copy output array elements to input array

    for(int i=0;i<n;i++){
        arr[i]=output[i];
    }
}
void radixSort(int *arr,int n){
    int m=maxValue(arr,n);
    for(int div=1;m/div>0;div*=10){
        countingSort(arr,n,div);
    }
}
int main() {
    int n;
    cin>>n;
    int arr[n+1];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Before Sorting: "<<endl;
   for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    radixSort(arr,n);
    cout<<endl<<"After Sorting: "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
