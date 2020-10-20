#include <bits/stdc++.h>
using namespace std;


int ternarySearch(int l, int r, int key, int arr[])
{
    if (l<=r) {
      // Finding mid1 and mid2
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;

        // Check if key is present at any mid
        if (arr[mid1] == key) {
            return mid1;
        }
        if (arr[mid2] == key) {
            return mid2;
        }

        // when key not present in any mid
        if (key < arr[mid1]) {

            return ternarySearch(l, mid1 - 1, key, arr);
        }
        else if (key > arr[mid2]) {
            return ternarySearch(mid2 + 1, r, key, arr);
        }
        else {
            return ternarySearch(mid1 + 1, mid2 - 1, key, arr);
        }
    }


    return -1;  // when key not found
}

int main()
{

  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
  cin>>arr[i];
  int elem;
  cin>>elem;

  sort(arr,arr+n);  // we sort the array provided

  int res=ternarySearch(0,n-1,elem,arr);
  if(res==-1)
  cout<<"Element not found";
  else
  cout<<"Index of"<<elem<<"is :"<<res;


}
