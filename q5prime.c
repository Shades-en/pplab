#include <stdio.h>
#include <omp.h>

int isPrime(int n){
    if(n<=0 || n==1)
        return 0;
    
    for(int i=2; i<=n/2; i++){
        if(n%i==0)
            return 0;
    }
    return 1;
}

void main(){
    int n;
    printf("Enter a number to check\n");
    scanf("%d", &n);
    printf("\nprime numbers: ");
    double start = omp_get_wtime();
    #pragma omp parallel for
    for(int i=0;i<=n;i++){
        if(isPrime(i)){
            printf("%d\t", i);
        }
    }
    double end = omp_get_wtime();
    double timeP = end - start;

    printf("\nprime numbers: ");
    start = omp_get_wtime();
    for(int i=0;i<=n;i++){
        if(isPrime(i)){
            printf("%d\t", i);
        }
    }
    end = omp_get_wtime();
    double timeS = end - start;

    printf("\nTime for serial = %lf, \nTime for parallel is %lf", timeS, timeP);
}