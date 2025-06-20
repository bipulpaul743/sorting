#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void randomizedQuickSort(int arr[], int low, int high);
int randomizedPartition(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void swap(int *a, int *b);

int main() {
    int n;

    // Input from user
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Seed for random number generator
    srand(time(NULL));

    // Perform randomized quicksort
    randomizedQuickSort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

void randomizedQuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = randomizedPartition(arr, low, high);

        printf("Pivot selected: %d at index %d\n", arr[pivotIndex], pivotIndex);
        printf("After partition: ");
        for (int i = 0; i <= high; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        randomizedQuickSort(arr, low, pivotIndex - 1);
        randomizedQuickSort(arr, pivotIndex + 1, high);
    }
}

int randomizedPartition(int arr[], int low, int high) {
    int randIndex = low + rand() % (high - low + 1);
    swap(&arr[randIndex], &arr[high]);

    printf("Randomly chosen pivot: %d (swapped with index %d)\n", arr[high], randIndex);

    return partition(arr, low, high);
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
            printf("Swapped %d and %d: ", arr[i], arr[j]);
            for (int k = low; k <= high; k++) {
                printf("%d ", arr[k]);
            }
            printf("\n");
        }
    }

    swap(&arr[i + 1], &arr[high]);
    printf("Moved pivot %d to correct position: ", pivot);
    for (int k = low; k <= high; k++) {
        printf("%d ", arr[k]);
    }
    printf("\n");

    return i + 1;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}