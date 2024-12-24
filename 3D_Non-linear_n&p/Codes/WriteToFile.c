#include<stdio.h>
#include "Header/myheader.h"

void WriteToFile(int N, float X[], float **n_c){
	FILE *fptr;
	fptr = fopen("CSV_Files/cube.csv", "w");
	fprintf(fptr,"x,y,z,value");
    fprintf(fptr,"\n");
	for (int i=0;i<N;i++){
		fprintf(fptr,"%f,%f,%f,%f\n",n_c[i][0],n_c[i][1],n_c[i][2],X[i]);
	}
    printf("Sucessfully written\n");

}
