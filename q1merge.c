#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

void merge(int arr[], int low, int mid, int high){
    int i=low;
    int k=low;
    int j=mid+1;
    int temp[high+1];

    while(i<mid+1 && j<high+1){
        if(arr[i]<=arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }

    while(i<mid+1)
        temp[k++] = arr[i++];
    while(j<high+1)
        temp[k++] = arr[j++];

    for(int i=low;i<=high;i++){
        arr[i] = temp[i];
    }
}


void mergeSortSerial(int arr[], int low, int high){
    if(low<high){
        int mid = (low+high)>>1;
        mergeSortSerial(arr, low, mid);
        mergeSortSerial(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

void mergeSortParallel(int arr[], int low, int high){
    if(low<high){
        int mid = (low+high)>>1;
        #pragma omp parallel sections
        {
            #pragma omp section
            mergeSortSerial(arr, low, mid);
            #pragma omp section
            mergeSortSerial(arr, mid+1, high);
        }
        merge(arr, low, mid, high);
    }
}

void main(){
    int n;
    printf("Enter number of elements\n");
    scanf("%d", &n);
    int arr[n], arr2[n];
    for(int i=0;i<n;i++){
        int temp = rand()%100;
        arr[i] = temp;
        arr2[i] = temp;
    }

    // printf("\nArray before sorting is \n");
    // for(int i=0;i<n;i++){
    //     printf("%d\t", arr[i]);
    // }
    // printf("\n");

    float start = omp_get_wtime();
    mergeSortSerial(arr, 0, n-1);
    float end = omp_get_wtime();
    float time1 = end - start;

    start = omp_get_wtime();
    mergeSortParallel(arr2, 0, n-1);
    end = omp_get_wtime();
    float time2 = end - start;

    // printf("\nArray After sorting is \n");
    // for(int i=0;i<n;i++){
    //     printf("%d\t", arr2[i]);
    // }
    // printf("\n");

    printf("time taken for serial is %lf and for parallel is %lf", time1, time2);
}