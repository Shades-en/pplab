#include <stdio.h>
#include <mpi.h>

void main()
{
    MPI_Init(NULL, NULL);
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int val;
    if (rank == 0)
    {
        val = 4536;
        printf("Process %d broadcasts %d to all\n", rank, val);
    }

    MPI_Bcast(&val, 1, MPI_INT, 0, MPI_COMM_WORLD);
    printf("Process %d recieved value %d from process 0\n", rank, val);
    MPI_Finalize();
}