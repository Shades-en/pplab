#include <stdio.h>
#include <mpi.h>

void main()
{
    int rank, size;
    MPI_Status status;
    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int msg0;
    int msg1;
    if (rank == 0)
    {
        msg0 = 0;
        MPI_Ssend(&msg0, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        MPI_Recv(&msg1, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, &status);
        printf("\n message %d recieved from %d to %d", msg1, status.MPI_SOURCE, rank);
    }
    else
    {
        msg1 = 1;
        MPI_Recv(&msg0, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
        MPI_Ssend(&msg1, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
        printf("\n \nmessage %d recieved from %d to %d", msg0, status.MPI_SOURCE, rank);
    }

    MPI_Finalize();
}