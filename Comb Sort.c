#include <stdio.h>

void combSort(int arr[], int n) {
    int gap = n;
    float shrink = 1.3;
    int sorted = 0;

    while(!sorted) {
        gap = (int)(gap/shrink);
        if(gap <= 1) { gap=1; sorted=1; }
        for(int i=0; i+gap<n; i++) {
            if(arr[i] > arr[i+gap]) {
                int temp = arr[i]; arr[i]=arr[i+gap]; arr[i+gap]=temp;
                sorted=0;
            }
        }
    }
}

int main() {
    int arr[] = {8, 4, 1, 56, 3, -44, 23, -6, 28, 0};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Original array: ");
    for(int i=0;i<n;i++) printf("%d ", arr[i]);
    printf("\n");

    combSort(arr, n);

    printf("Sorted array:   ");
    for(int i=0;i<n;i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
