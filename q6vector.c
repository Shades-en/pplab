#include <stdio.h>
#include <omp.h>
#include <stdlib.h>


void main(){
    int n;
    printf("Enter value of n\n");
    scanf("%d", &n);
    int res[n], a[n], b[n];

    for(int i=0;i<n;i++){
        a[i] = rand()%100;
        b[i] = rand()%100;
    }
    printf("\nvector a : ");
    for(int i=0;i<n;i++){
        printf("%d\t", a[i]);
    }
    printf("\nvector b : ");
    for(int i=0;i<n;i++){
        printf("%d\t", b[i]);
    }

    printf("\nresult : ");
    #pragma omp parallel for
    for(int i=0;i<n;i++){
        res[i] = a[i] + b[i]; 
    }

    printf("\nvector res : ");
    for(int i=0;i<n;i++){
        printf("%d\t", res[i]);
    }
}