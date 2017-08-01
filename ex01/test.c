#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 
// static int myCompare (const void * a, const void * b)
// {
//     return strcmp (*(const char **) a, *(const char **) b);
// }
 
// void sort(const char *arr[], int n)
// {
//     qsort (arr, n, sizeof (const char *), myCompare);
// }
 
// int main ()
// {
//     const char *arr[] = {"GeeksforGeeks", "GeeksQuiz", "CLanguage"};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     int i;
 
//     printf("Given array is\n");
//     for (i = 0; i < n; i++)
//         printf("%d: %s \n", i, arr[i]);
 
//     sort(arr, n);
 
//     printf("\nSorted array is\n");
//     for (i = 0; i < n; i++)
//         printf("%d: %s \n", i, arr[i]);
 
//     return 0;
// }





// /* C implementation QuickSort */
// #include<stdio.h>
 
// // A utility function to swap two elements
// void swap(int* a, int* b)
// {
//     int t = *a;
//     *a = *b;
//     *b = t;
// }
 
// /* This function takes last element as pivot, places
//    the pivot element at its correct position in sorted
//     array, and places all smaller (smaller than pivot)
//    to left of pivot and all greater elements to right
//    of pivot */
// int partition (int arr[], int low, int high)
// {
//     int pivot = arr[high];    // pivot
//     int i = (low - 1);  // Index of smaller element
 
//     for (int j = low; j <= high - 1; j++)
//     {
//         // If current element is smaller than or
//         // equal to pivot
//         if (arr[j] <= pivot)
//         {
//             i++;    // increment index of smaller element
//             swap(&arr[i], &arr[j]);
//         }
//     }
//     swap(&arr[i + 1], &arr[high]);
//     return (i + 1);
// }
 
//  The main function that implements QuickSort
//  arr[] --> Array to be sorted,
//   low  --> Starting index,
//   high  --> Ending index 
// void quickSort(int arr[], int low, int high)
// {
//     if (low < high)
//     {
//         /* pi is partitioning index, arr[p] is now
//            at right place */
//         int pi = partition(arr, low, high);
 
//         // Separately sort elements before
//         // partition and after partition
//         quickSort(arr, low, pi - 1);
//         quickSort(arr, pi + 1, high);
//     }
// }
 
// /* Function to print an array */
// void printArray(int arr[], int size)
// {
//     int i;
//     for (i=0; i < size; i++)
//         printf("%d ", arr[i]);
//     printf("n");
// }
 
// // Driver program to test above functions
// int main()
// {
//     int arr[] = {10, 7, 8, 9, 1, 5};
//     printf("size of arr is %lu, size of ar[0] is %lu\n", sizeof(arr), sizeof(arr[0]));
//     int n = sizeof(arr)/sizeof(arr[0]);
//     quickSort(arr, 0, n-1);
//     printf("Sorted array: n");
//     printArray(arr, n);
//     return 0;
// }





#include <stdio.h>
 
void quicksort(int *A, int len);
 
int main (void) {
  int a[] = {4, 65, 2, -31, 0, 99, 2, 83, 782, 1};
  int n = sizeof a / sizeof a[0];
 
  int i;
  for (i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
 
  quicksort(a, n);
 
  for (i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
 
  return 0;
}
 
void quicksort(int *A, int len) {
  if (len < 2) return;
 
  int pivot = A[len / 2];
 
  int i, j;
  for (i = 0, j = len - 1; ; i++, j--) {
    while (A[i] < pivot) i++;
    while (A[j] > pivot) j--;
 
    if (i >= j) break;
 
    int temp = A[i];
    A[i]     = A[j];
    A[j]     = temp;
  }
 
  quicksort(A, i);
  quicksort(A + i, len - i);
}
 