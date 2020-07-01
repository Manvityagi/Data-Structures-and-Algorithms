// arr - input array
// n - size of array
void InsertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int hole = i;
        int val = arr[i];
        while (hole > 0 && arr[hole - 1] > val)
        {
            arr[hole] = arr[hole - 1];
            hole--;
        }
        arr[hole] = val;
    }
}
