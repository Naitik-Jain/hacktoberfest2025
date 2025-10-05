#include <stdio.h>
#include <stdlib.h>

// Function to perform insertion sort (used for sorting individual buckets)
void insertionSort(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Bucket Sort function
void bucketSort(float arr[], int n) {
    // Create n empty buckets
    float* buckets[n];
    int bucketSizes[n];
    for (int i = 0; i < n; i++)
        bucketSizes[i] = 0;

    // Find maximum value to normalize
    float maxValue = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maxValue)
            maxValue = arr[i];

    // Allocate memory for buckets
    for (int i = 0; i < n; i++)
        buckets[i] = (float*)malloc(n * sizeof(float));

    // Put array elements in different buckets
    for (int i = 0; i < n; i++) {
        int index = (int)((arr[i] / (maxValue + 1)) * n);  // normalize
        buckets[index][bucketSizes[index]++] = arr[i];
    }

    // Sort individual buckets using insertion sort
    for (int i = 0; i < n; i++)
        insertionSort(buckets[i], bucketSizes[i]);

    // Concatenate all buckets into arr[]
    int k = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < bucketSizes[i]; j++)
            arr[k++] = buckets[i][j];

    // Free memory
    for (int i = 0; i < n; i++)
        free(buckets[i]);
}

// Main function
int main() {
    float arr[] = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++)
        printf("%.2f ", arr[i]);
    printf("\n");

    bucketSort(arr, n);

    printf("Sorted array:   ");
    for (int i = 0; i < n; i++)
        printf("%.2f ", arr[i]);
    printf("\n");

    return 0;
}
