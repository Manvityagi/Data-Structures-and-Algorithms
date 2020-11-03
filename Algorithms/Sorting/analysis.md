Bubble sort and Insertion sort 

- Average and worst case time complexity: n^2
- Best case time complexity: n when array is already sorted.
- Worst case: when the array is reverse sorted.

Selection sort 

- Best, average and worst case time complexity: n^2 which is independent of distribution of data.

Merge sort 

- Best, average and worst case time complexity: nlogn which is independent of distribution of data.

Heap sort 

- Best, average and worst case time complexity: nlogn which is independent of distribution of data.

Quick sort 

- It is a divide and conquer approach with recurrence relation:
  T(n) = T(k) + T(n-k-1) + cn
- Worst case: when the array is sorted or reverse sorted, the partition algorithm divides the array in two subarrays with 0 and n-1 elements. Therefore,
  T(n) = T(0) + T(n-1) + cn
  Solving this we get, T(n) = O(n^2)

-   Best case and Average case: On an average, the partition algorithm divides the array in two subarrays with equal size. Therefore,

T(n) = 2T(n/2) + cn
Solving this we get, T(n) = O(nlogn)