#include <stdio.h>
#include <omp.h>

void main(){
    int n = 100;
    int sum=0;
    #pragma parallel for 
    for(int i=1; i<=n;i++){
        #pragma omp critical
        sum+=i;
    }
    printf("result : %d\n", sum);
}