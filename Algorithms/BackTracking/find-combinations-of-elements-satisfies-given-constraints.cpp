#include <iostream>
#include <vector>
using namespace std;

// Find all combinations that satisfies given constraints 
void findAllCombinations(vector<int> &arr, int elem, int n)
{
	if(elem > n){
        for(auto e : arr)
            cout << e << " ";
        cout << endl;
        return;
    }

    for(int i = 0; i < 2*n; i++){
        if(arr[i] == -1 && (i+elem+1) < 2*n && arr[i+elem+1] == -1){
            arr[i] = elem;
            arr[i+elem+1] = elem;

            findAllCombinations(arr,elem+1,n);

            arr[i] = -1;
            arr[i+elem+1] = -1;
        }
    }
}

int main()
{
	// given number
	int n = 7;
	
	// create a vector of double the size of given number with
	// all its elements initialized by -1
	vector<int> arr(2*n, -1);

	// start from element 1
	int elem = 1;
	findAllCombinations(arr, elem, n);

	return 0;
}