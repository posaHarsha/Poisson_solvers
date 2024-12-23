#include "Header/myheader.h"
#include<stdlib.h>

float *InitialGuess(int n_nod,int * Boundary_nodes, int count, float ** NodeCoordinate, int Vl , int Vr){
	float* V = (float*)malloc(n_nod * sizeof(float));
	
	for(int i=0; i<n_nod; i++){
        	V[i] = 1;
        }
        for(int i=0; i<count; i++){
     		if(NodeCoordinate[Boundary_nodes[i]][0] == 0){
     			V[Boundary_nodes[i]] = Vl;
     		}
     		else if(NodeCoordinate[Boundary_nodes[i]][0] == 4){
     			V[Boundary_nodes[i]] = Vr;
     		}
     	}
     	return V;
        
}
