#include <stdio.h>

void combSort(int arr[], int n){
    int gap=n;
    float shrink=1.3;
    int sorted=0;
    while(!sorted){
        gap=(int)(gap/shrink);
        if(gap<=1){ gap=1; sorted=1; }
        for(int i=0;i+gap<n;i++){
            if(arr[i]>arr[i+gap]){ int t=arr[i]; arr[i]=arr[i+gap]; arr[i+gap]=t; sorted=0; }
        }
    }
}

int main(){
    int n;
    printf("Comb Sort\nEnter number of elements: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements: ");
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);

    combSort(arr,n);

    printf("Sorted array: ");
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
    printf("\n");
    return 0;
}
