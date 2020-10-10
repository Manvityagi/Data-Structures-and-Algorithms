#include <iostream>
using namespace std;
int binarySearch(int *arr,int n,int x){
    int low=0,high=n-1,mid;
    while(low<=high){        //we will stop running this loop when low will become greater than high
        mid=low+(high-low)/2;
        if(x==arr[mid]){   //if value of x become equal to mid value of array then we return mid
            return mid;
        }
        else if(x<arr[mid]){     //if value of x is less than mid then high will become mid-1
            high=mid-1;
        }
        else{     //if value of x is less than mid then high will become mid-1
            low=mid+1;
        }
    }
    return -1;       //if value is not in the array then we will return -1
}
int main() {
    int n,x,ans;      //size of the array
    cin>>n;
    cin>>x;  //value of number
    int arr[n+1];  //array
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    ans=binarySearch(arr,n,x);
    cout<<"The number "<<x<<" is found at position "<<ans+1<<"."<<endl;
    return 0;
}
