#include <stdio.h>
#include <mpi.h>

void main()
{
    MPI_Init(NULL, NULL);
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Status status;

    int target = (rank + 1) % size;
    int source = (rank - 1 + size) % size;
    int msg = rank;
    int msgt;

    MPI_Sendrecv(&msg, 1, MPI_INT, target, 0, &msgt, 1, MPI_INT, source, 0, MPI_COMM_WORLD, &status);
    printf("Message %d recieved from %d to %d\n", msgt, status.MPI_SOURCE, rank);

    MPI_Finalize();
}