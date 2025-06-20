#include<stdio.h>
int comparisonCount = 0;
int recursiveCalls = 0;
void printArray(int arr[],int low, int high) {
    for (int i = low; i <= high; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge(int arr[], int low, int mid, int high) {
    int i = low;
    int j = mid+1;
    int k = low;
    int b[high - low + 1];
    printf("Merging: ");
    while (i<=mid && j<=high) {
        comparisonCount++;
        if(arr[i] <= arr[j]) {
            b[k] = arr[i];
            i++;
        } else {
            b[k] = arr[j];
            j++;
        }
        printf("%d ", b[k]);
        k++;
    }
    while (i<=mid) {
        comparisonCount++;
        b[k] = arr[i];
        printf("%d ", b[k]);
        i++;
        k++;
    }
    while (j<=high) {
        comparisonCount++;
        b[k] = arr[j];
        printf("%d ", b[k]);
        j++;
        k++;
    }

    for (k=low; k<=high; k++) {
        arr[k] = b[k];
    }
    printf("\n");
}

void mergeSort(int arr[], int low, int high) {
    if(low < high) {
        recursiveCalls++;
        int mid = low + (high - low)/2;
        printf("Dividing: left=%d mid=%d right=%d\n", low, mid, high);
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    while (1) {
        if (n == 0) {
            printf("Empty array, nothing to sort.\n");

            return 0;
        }
        if (n < 0) {
            printf("Enter the positive value.\n");
            printf("Enter the number of elements: ");
            scanf("%d", &n);
        } else {
            int arr[n];
            printf("Enter %d elements: ", n);
            for (int i = 0; i < n; i++) {
                scanf("%d", &arr[i]);
            }
        
            // Display the original array
            printf("Original array : ");
            printArray(arr, 0, n-1);
        
            // Perform Merge Sort
            mergeSort(arr, 0, n-1);
        
            // Display the sorted array
            printf("Sorted array : ");
            printArray(arr, 0, n-1);
            printf("Total number of comparisons: %d\n", comparisonCount); // Print comparison count
            printf("Total number of recursive calls: %d\n", recursiveCalls);
        
            return 0;
        }
    }     
}