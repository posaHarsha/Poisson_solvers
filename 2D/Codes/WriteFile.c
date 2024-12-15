#include "Header/myheader.h"
#include <stdio.h>
#include <stdlib.h>

//Funtion will write a CSV file contains the x,y&z coordinates and the solution at these Coordinates
void WriteToFile(int N, float *X, float **n_c){
	FILE *fptr;
	fptr = fopen("CSV_Files/2D_solution.csv", "w");
	fprintf(fptr,"x,y,z,value");
        fprintf(fptr,"\n");
	for (int i=0;i<N;i++){
		fprintf(fptr,"%f,%f,%f,%f\n",n_c[i][0],n_c[i][1],n_c[i][2],X[i]);
	}
	

}
