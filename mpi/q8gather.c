#include <stdio.h>
#include <mpi.h>

void main()
{
    MPI_Init(NULL, NULL);
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int msg = rank;
    int rec[size];

    MPI_Gather(&msg, 1, MPI_INT, rec, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if(rank==0){
        for (int i = 0; i < size; i++)
        {
            printf("%d\t", rec[i]);
        }
        printf("\n");
    }
    
    MPI_Finalize();
}