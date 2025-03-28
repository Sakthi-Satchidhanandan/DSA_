/* QUICK SORT */

#include <stdio.h>

// Function to partition the array with Last Element taken as PIVOT

int partition(int arr[], int low, int high) 
    {
    int pivot = high; // Last element as pivot
    int i = -1; // Pointer for smaller element index
    int j, temp;

    for (j = 0; j < pivot; j++) 
    {
        if (arr[j] < arr[pivot])          // If current element is smaller than pivot
        { 
            i++;
            temp = arr[i];           // Swap arr[i] and arr[j]
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } 
    
    // Once PIVOT is reached, Swap pivot with the element at i=i+1
    i++;
    temp = arr[i];
    arr[i] = arr[pivot];
    arr[pivot] = temp;

    return i;                        // Return partition index
}

// QuickSort function

void quickSort(int arr[int n], int low, int high) 
{
    if (low < high) 
    {
        int pi = partition(arr, low, high);    // Get pivot index
        quickSort(arr, low, pi - 1);           // Recursively sort elements before pivot
        quickSort(arr, pi + 1, high);          // Recursively sort elements after pivot
    }
}

// Main function to test QuickSort

int main() 
{
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
