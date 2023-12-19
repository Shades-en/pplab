#include <stdio.h>
#include <mpi.h>

void main()
{
    MPI_Init(NULL, NULL);
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int min, max, sum, prod;
    int val = rank;

    MPI_Allreduce(&val, &min, 1, MPI_INT, MPI_MIN, MPI_COMM_WORLD);
    MPI_Allreduce(&val, &max, 1, MPI_INT, MPI_MAX, MPI_COMM_WORLD);
    MPI_Allreduce(&val, &sum, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
    MPI_Allreduce(&val, &prod, 1, MPI_INT, MPI_PROD, MPI_COMM_WORLD);

    printf("process %d : min = %d, max = %d, prod = %d, sum = %d\n", rank, min, max, prod, sum);

    MPI_Finalize();
}