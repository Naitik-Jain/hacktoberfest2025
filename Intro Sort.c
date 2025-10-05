#include <stdio.h>
#include <math.h>

void swap(int *a,int *b){ int t=*a;*a=*b;*b=t; }

void heapify(int arr[], int n, int i){
    int largest=i,l=2*i+1,r=2*i+2;
    if(l<n && arr[l]>arr[largest]) largest=l;
    if(r<n && arr[r]>arr[largest]) largest=r;
    if(largest!=i){ swap(&arr[i],&arr[largest]); heapify(arr,n,largest);}
}

void heapSort(int arr[], int n){
    for(int i=n/2-1;i>=0;i--) heapify(arr,n,i);
    for(int i=n-1;i>0;i--){ swap(&arr[0],&arr[i]); heapify(arr,i,0);}
}

int partition(int arr[], int l, int h){
    int pivot=arr[h],i=l-1;
    for(int j=l;j<h;j++){
        if(arr[j]<=pivot){ i++; swap(&arr[i],&arr[j]); }
    }
    swap(&arr[i+1],&arr[h]);
    return i+1;
}

void introSortUtil(int arr[], int begin, int end, int depth){
    int n=end-begin+1;
    if(n<=16){
        for(int i=begin+1;i<=end;i++){
            int key=arr[i],j=i-1;
            while(j>=begin && arr[j]>key){ arr[j+1]=arr[j]; j--; }
            arr[j+1]=key;
        }
        return;
    }
    if(depth==0){ heapSort(arr+begin,n); return; }
    int p=partition(arr,begin,end);
    introSortUtil(arr,begin,p-1,depth-1);
    introSortUtil(arr,p+1,end,depth-1);
}

void introSort(int arr[], int n){
    int depthLimit=2*log(n);
    introSortUtil(arr,0,n-1,depthLimit);
}

int main() {
    int n;
    printf("Intro Sort\nEnter number of elements: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements: ");
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);

    introSort(arr,n);

    printf("Sorted array: ");
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
    printf("\n");
    return 0;
}
