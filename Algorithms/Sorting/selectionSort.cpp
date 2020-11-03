// arr - input array
// n - size of array
void SelectionSort(int arr[], int n)
{
    int min_i;

    for (int i = 0; i < n; i++)
    {
        min_i = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_i])
                min_i = j;
        }
        int temp = arr[i];
        arr[i] = arr[min_i];
        arr[min_i] = temp;
    }
}
