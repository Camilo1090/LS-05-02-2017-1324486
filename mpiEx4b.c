
#include <stdio.h>
#include "mpi.h"

int main(int argc,char *argv[]){
	int i, upToVal;
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
		
		// Utilice la funcion 'MPI_Reduce' para guardar en la variable 
		// 'sumTotal' la suma parcial de todos las tareas 
		MPI_Reduce(&sum, &sumTotal, 1, MPI_LONG, MPI_SUM, 0, MPI_COMM_WORLD);		
		printf ("Proceso %d - Total: %li\n", rank, sumTotal);
	}
	else {
		if (rank == 0)
			printf ("uneven chuncks not implemented yet\n");
	}

	MPI_Finalize();
	
	return 0;
}
