#include <stdio.h>

int comparisonCount = 0; // Global variable to count number of comparisons
int recursiveCalls = 0;   // Count recursive function calls

// Function to print the current state of the array
void printArray(int arr[],int low, int high) {
    for (int i = low; i <= high; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swapping(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void pointer_swapping(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array around the pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choose the last element as the pivot
    printf("Pivot: %d\n", pivot);

    int i = low - 1; // Index of the smaller element

    // Traverse the array and rearrange elements
    for (int j = low; j < high; j++) {
        comparisonCount++; // Counting comparisons
        if (arr[j] < pivot) { // If current element is smaller than pivot
            i++; // Move the smaller element index forward

            // Swap arr[i] and arr[j]
            swapping(arr, i, j);
            // pointer_swapping(&arr[i], &arr[j]);
            // int temp = arr[i];
            // arr[i] = arr[j];
            // arr[j] = temp;
        }
    }
    i++;
    // Place the pivot in the correct position
    // swapping(arr, i, high);
    pointer_swapping(&arr[i], &arr[high]);
    // int temp = arr[i];
    // arr[i] = arr[high];
    // arr[high] = temp;

    printf("Array after partitioning: ");
    printArray(arr, low, high); // Print the array after partitioning

    return i; // Return the pivot index
}

// Function to perform Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        recursiveCalls++; // Count function calls

        // Partition the array and get the pivot index
        int pivotIndex = partition(arr, low, high);

        // Sort the left subarray
        printf("Sorting left part (low = %d, pivotIndex - 1 = %d)\n", low, pivotIndex - 1);
        quickSort(arr, low, pivotIndex - 1);

        // Sort the right subarray
        printf("Sorting right part (pivotIndex + 1 = %d, high = %d)\n", pivotIndex + 1, high);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Display the original array
    printf("Original array: \n");
    printArray(arr, 0, n-1);

    // Perform Quick Sort
    quickSort(arr, 0, n-1);

    // Display the sorted array
    printf("Sorted array: \n");
    printArray(arr, 0, n-1);
    printf("Total number of comparisons: %d\n", comparisonCount); // Print comparison count
    printf("Total number of recursive calls: %d\n", recursiveCalls);

    return 0;
}