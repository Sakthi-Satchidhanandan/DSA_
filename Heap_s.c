/* HEAP SORT */

#include <stdio.h>

// Function to Heapify a subtree rooted at node i

void heapify(int arr[], int n, int i) 
{
    int largest, left, right, temp;
    largest = i;  // Initialize largest as root
    left = 2 * i + 1;  // Left child
    right = 2 * i + 2; // Right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) 
    {
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}

// Function to perform Heap Sort

void heapSort(int arr[], int n) 
{
    int i, temp;
    
    // Step 1 : Build Max Heap (Rearrange Array)
    for (i = n/2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    
    // Extract elements from heap one by one
    for (i = n - 1; i > 0; i--) 
    {
        // Swap the root (largest) with the last element
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Heapify the reduced heap
        heapify(arr, i, 0);
    }
}

// Main function
int main() 
{
    int n,i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    heapSort(arr, n);   //Pass Array to Heap Sort Function

    printf("Sorted array: ");
    for (i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
