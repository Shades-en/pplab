#include <stdio.h>
#include <omp.h>

int fibo(int n){
    if(n<=1){
        return n;
    }
    int i = fibo(n-1);
    int j = fibo(n-2);
    return i+j;
}


void main(){
    int n;
    printf("Enter n\n");
    scanf("%d", &n);
    #pragma omp parallel
    {
        #pragma omp single
        for(int i=0;i<=n;i++){
            #pragma omp task
            printf("fibonacci ans =%d from thread(%d)\n", fibo(i), omp_get_thread_num());
        }
    }  
}