#include "Header/myheader.h"

float **EditStiffness(float **StiffnessMatrix,float* V,float *S, int n_nod, int * Boundary_nodes, int count){
	for(int i =0; i<n_nod; i++){
        	for(int j=0; j<n_nod; j++){
        		if(i==j){
        			StiffnessMatrix[i][j] -= 2*(S[i]/V[i]);  
        	}
        }
        }
        for(int i=0; i<count; i++){
        	StiffnessMatrix[Boundary_nodes[i]][Boundary_nodes[i]] = 1;
        	
        }
        return StiffnessMatrix;
}
