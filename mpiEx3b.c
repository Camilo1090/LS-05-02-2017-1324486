
#include <stdio.h>
#include "mpi.h"

int main(int argc,char *argv[]){
	int size, rank, dest, source, count, tag=1;
	int inmsg, outmsg;
	MPI_Status Stat;

	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	dest = (rank + 1) % size;
	outmsg = rank;

	if (rank == 0) {
	  source = size - 1;
	  MPI_Send(&outmsg, 1, MPI_INT, dest, tag, MPI_COMM_WORLD);
	  MPI_Recv(&inmsg, 1, MPI_INT, source, tag, MPI_COMM_WORLD, &Stat);
	} else {
	  source = rank - 1;
	  MPI_Recv(&inmsg, 1, MPI_INT, source, tag, MPI_COMM_WORLD, &Stat);
	  MPI_Send(&outmsg, 1, MPI_INT, dest, tag, MPI_COMM_WORLD);
	}

	//MPI_Get_count(&Stat, MPI_INT, &count);
	printf("Task %d: Received %d (integer) from task %d with tag %d \n",
		   rank, inmsg, Stat.MPI_SOURCE, Stat.MPI_TAG);

	MPI_Finalize();
}
