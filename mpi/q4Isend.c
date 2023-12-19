#include <stdio.h>
#include <mpi.h>

void main()
{
    MPI_Init(NULL, NULL);
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Request request;
    MPI_Status status;
    int msg0, msg1;

    if (rank == 0)
    {
        msg0 = 0;
        MPI_Isend(&msg0, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, &request);
        MPI_Irecv(&msg1, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, &request);
        MPI_Wait(&request, &status);
        printf("\n message %d recieved from %d to %d", msg1, status.MPI_SOURCE, rank);
    }
    else
    {
        msg1 = 1;
        MPI_Isend(&msg1, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &request);
        MPI_Irecv(&msg0, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &request);
        MPI_Wait(&request, &status);
        printf("\n \nmessage %d recieved from %d to %d", msg0, status.MPI_SOURCE, rank);
    }

    MPI_Finalize();
}