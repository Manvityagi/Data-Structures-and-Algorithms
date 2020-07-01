void merge(int a[], int si, int ei)
{
    int final[1000];
    if (si >= ei)
        return;
    int mid = (si + ei) / 2;
    int i = si;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= ei)
    {
        if (a[i] < a[j])
            final[k++] = a[i++];
        else
            final[k++] = a[j++];
    }
    while (i <= mid)
        final[k++] = a[i++];

    while (j <= ei)
        final[k++] = a[j++];

    for (i = si; i <= ei; i++)
    {
        a[i] = final[i - si];
    }
}

void mergesort(int a[], int si, int ei)
{
    if (si >= ei)
        return;
    int mid = (si + ei) / 2;
    mergesort(a, si, mid);
    mergesort(a, mid + 1, ei);
    merge(a, si, ei);
}

void mergeSort(int a[], int n)
{
    mergesort(a, 0, n - 1);
}
