#include<stdio.h>
#include<omp.h>
#include<stdlib.h>

void merge(int a[],int l,int mid,int h){
    int n1 = mid-l+1;
    int n2 = h-mid;
    int arr1[n1],arr2[n2];
    for(int i=0;i<n1;i++) arr1[i] = a[l+i];
    for(int i=0;i<n2;i++) arr2[i] = a[mid+1+i];
    int i=0,j=0,k=l;

    while(i<n1 && j<n2){
        if(arr1[i]<=arr2[j])
            a[k++] = arr1[i++];
        else
            a[k++] = arr2[j++];
    }
    while(i<n1) a[k++] = arr1[i++];
    while(j<n2)a[k++] = arr2[j++];
}

void mergesortParallel(int a[],int l,int h){
    if(l<h){
        int mid = (l+h)>>1;
        #pragma omp parallel sections
        {
            #pragma omp section
            mergesortParallel(a,l,mid);
            #pragma omp section
            mergesortParallel(a,mid+1,h);
        }
        merge(a,l,mid,h);
    }
}

void mergesortSerial(int a[],int l,int h){
    if(l<h){
        int mid = (l+h)>>1;
        mergesortSerial(a,l,mid);
        mergesortSerial(a,mid+1,h);
        merge(a,l,mid,h);
    }
}


void main(){
        int num,i;
        printf("Enter number:");
        scanf("%d",&num);
        int a[num];
        int b[num];

        for(i=0;i<num;i++){
                int temp = rand()%100;
                a[i] = temp;
                b[i] = temp;
        }

        //printf("Before sort\n");
        //for(i =0;i<num;i++){
        //      printf("%d ",a[i]);
        //}
        //printf("\n");
        double start = omp_get_wtime();
        mergesortSerial(a,0,num-1);
        printf("After serial sort\n");
        for(i =0;i<num;i++){
              printf("%d ",a[i]);
        }
        printf("\n");
        double end = omp_get_wtime();
        double val = end - start;


        start = omp_get_wtime();
        mergesortParallel(b,0,num-1);
        printf("After parallel sort\n");
        for(i =0;i<num;i++){
                printf("%d ",b[i]);
        }
        printf("\n");
        end = omp_get_wtime();
        val = end-start;
        printf("\nTime for serial is:%f\n",val);
        printf("Time for parallel execution is %f\n",val);
}
