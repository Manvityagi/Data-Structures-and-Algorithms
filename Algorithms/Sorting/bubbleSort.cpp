// arr - input array
// n - size of array
void BubbleSort(int arr[], int n)
{
    for (int round = 0; round < n - 1; round++)
    {
        for (int j = 0; j < n - round - 1; j++)
            if (arr[j + 1] < arr[j])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
    }
}
