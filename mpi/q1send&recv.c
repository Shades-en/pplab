#include <stdio.h>
#include <mpi.h>
#include <string.h>

void main()
{
    MPI_Init(NULL, NULL);
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Status status;
    char msg[] = "Hello world";
    if (rank == 0)
    {
        MPI_Send(msg, strlen(msg), MPI_CHAR, 1, 0,MPI_COMM_WORLD);
        printf("\nSent message %s from %d", msg, rank);
    }
    if (rank == 1)
    {
        MPI_Recv(msg, strlen(msg), MPI_CHAR, 0, 0, MPI_COMM_WORLD, &status);
        printf("\nRecieved message %s from %d to %d", msg, status.MPI_SOURCE, rank);
    }

    MPI_Finalize();
}