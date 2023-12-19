#include <stdio.h>
#include <omp.h>

void main(){
    int n;
    printf("No. of iterations\n");
    scanf("%d", &n);
    #pragma omp parallel for schedule(static,2) //2 iterations given to one thread before program starts - statically
    for(int i=0;i<n;i++){
        printf("Thread %d : Iteration %d\n", omp_get_thread_num(), i);
    }
}