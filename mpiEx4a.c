
#include <stdio.h>
#include "mpi.h"

int main(int argc,char *argv[]){
	int i, upToVal, tag=1;
	int start, end, size, rank;
	long sum, sumTotal;
	MPI_Status Stat;

	upToVal = 100000;

	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	// Defina aqui el segmento que debe procesar una tarea
	// El inicio del segmento en la variable 'start', el fin del segmento
	// la variable 'end'
	
	if (upToVal % size == 0){
		int cs = upToVal/size;
		start = (cs * rank) + 1;
		end = cs * (rank + 1);
		sum = 0;
	  	for(i=start; i<= end; i++){
	 	 	sum = sum + i;
	 	}	
		sumTotal = sum;

		if (rank == 0) {		
			for (i=1; i<size; i++){
				MPI_Recv(&sum, 1, MPI_LONG, i, tag, MPI_COMM_WORLD, &Stat);
				sumTotal += sum;
			}
			//printf ("\nTotal: %d\n",sumTotal);
		} else {
		  	MPI_Send(&sum, 1, MPI_LONG, 0, tag, MPI_COMM_WORLD);
		}

	
		
		// Utilice la funcion 'MPI_Reduce' para guardar en la variable 
		// 'sumTotal' la suma parcial de todos las tareas 
		printf ("Proceso %d - Total: %li\n", rank, sumTotal);
	}
	else {
		if (rank == 0)
			printf ("uneven chuncks not implemented yet\n");
	}

	MPI_Finalize();
	
	return 0;
}
