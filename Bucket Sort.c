#include <stdio.h>
#include <stdlib.h>

void insertionSort(float arr[], int n) {
    for(int i=1;i<n;i++) {
        float key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key) { arr[j+1]=arr[j]; j--; }
        arr[j+1]=key;
    }
}

void bucketSort(float arr[], int n) {
    float *buckets[n];
    int bucketSizes[n];
    for(int i=0;i<n;i++) bucketSizes[i]=0;
    for(int i=0;i<n;i++) {
        int index=(int)(arr[i]*n);
        if(!buckets[index]) buckets[index]=(float*)malloc(n*sizeof(float));
        buckets[index][bucketSizes[index]++]=arr[i];
    }
    int k=0;
    for(int i=0;i<n;i++) {
        if(buckets[i]) {
            insertionSort(buckets[i],bucketSizes[i]);
            for(int j=0;j<bucketSizes[i];j++) arr[k++]=buckets[i][j];
            free(buckets[i]);
        }
    }
}

int main() {
    int n;
    printf("Bucket Sort (0-1 floats)\nEnter number of elements: ");
    scanf("%d",&n);
    float arr[n];
    printf("Enter elements (0 to 1): ");
    for(int i=0;i<n;i++) scanf("%f",&arr[i]);

    bucketSort(arr,n);

    printf("Sorted array: ");
    for(int i=0;i<n;i++) printf("%.2f ",arr[i]);
    printf("\n");
    return 0;
}
