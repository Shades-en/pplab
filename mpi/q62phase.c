#include <stdio.h>
#include <mpi.h>

void main()
{
    MPI_Init(NULL, NULL);
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    printf("Process %d of %d in phase 1\n", rank, size);

    MPI_Barrier(MPI_COMM_WORLD);

    printf("Process %d of %d in phase 2\n", rank, size);

    MPI_Finalize();
}