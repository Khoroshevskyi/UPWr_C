#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int arr[], int size);


// Bubble sort
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
    int* arr_bubble = arr;
    int i, j;
    for (i = 0; i < n-1; i++)
    {
        for (j = 0; j < n-i-1; j++)
        {
           if (arr_bubble[j] > arr_bubble[j+1])
              swap(&arr_bubble[j], &arr_bubble[j+1]);
        }
    }
    printArray(arr_bubble, n);
}


// Merge sort
// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

// quick sort
/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    clock_t t, t1, t2;
    int arr_length = 100;
    int arr[arr_length];
    for(int i = 0; i < arr_length; i++)
    {
        int r = rand() % 100;
        arr[i] = r;
    }
    //printf("unsorted Array: \n");
    //printArray(arr, n);

    t = clock();
    bubbleSort(arr, arr_length);
    t = clock() - t;

    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    printf("fun(1) took %f seconds to execute \n", time_taken);

    t1 = clock();
    mergeSort(arr, 0, arr_length-1);
    t1 = clock() - t1;

    double time_taken1 = ((double)t1)/CLOCKS_PER_SEC; // in seconds
    printf("fun(2) took %f seconds to execute \n", time_taken1);

    t2 = clock();
    quickSort(arr, 0, arr_length-1);
    t2 = clock() - t2;

    double time_taken2 = ((double)t2)/CLOCKS_PER_SEC; // in seconds
    printf("fun(3) took %f seconds to execute \n", time_taken2);


    printf("Sorted array: \n");
    printArray(arr, arr_length);
    return 0;

}