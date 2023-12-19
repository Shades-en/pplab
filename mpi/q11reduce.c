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

    MPI_Reduce(&val, &min, 1, MPI_INT, MPI_MIN, 0, MPI_COMM_WORLD);
    MPI_Reduce(&val, &max, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);
    MPI_Reduce(&val, &sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    MPI_Reduce(&val, &prod, 1, MPI_INT, MPI_PROD, 0, MPI_COMM_WORLD);

    if (rank == 0)
    {
        printf("min = %d, max = %d, prod = %d, sum = %d\n", min, max, prod, sum);
    }

    MPI_Finalize();
}