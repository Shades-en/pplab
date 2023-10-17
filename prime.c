#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int isPrime(int n) {
    if (n <= 1) {
        return 0;
    }

    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n = 50;

    double start = omp_get_wtime();
    #pragma omp parallel for
    for (int i = 2; i <= n; i++) {
        if (isPrime(i)) {
            int t = omp_get_thread_num();
            printf("Process:%d, %d\n", t, i);
        }
    }

    double end = omp_get_wtime();
    printf("Time taken is %lf\n", end - start);

    return 0;
}
