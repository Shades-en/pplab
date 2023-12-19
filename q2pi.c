#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <math.h>

void main(int argc, char *argv[])
{
    int iter = strtol(argv[1], NULL, 10);
    float pi;
    #pragma omp parallel for reduction(+:pi)
    for (int i = 0; i < iter; i++){
        pi += pow(-1, i) / (2 * i + 1);
    }
    printf("The value is %lf\n", 4*pi);
}