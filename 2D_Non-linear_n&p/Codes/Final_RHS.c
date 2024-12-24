#include "Header/myheader.h"
#include<stdlib.h>

float *Final_RHS(float **StiffnessMatrix, float* V,float *S, int n_nod, int * Boundary_nodes, int count){
	float* F_RHS = (float*)malloc(n_nod * sizeof(float));
	
	for(int i=0; i<n_nod; i++){
        	F_RHS[i] = 0;
        }
        for(int i =0; i<n_nod; i++){
        	for(int j=0; j<n_nod; j++){
        		F_RHS[i] += StiffnessMatrix[i][j]*V[j];
        	}
        	F_RHS[i] = -((F_RHS[i]*1e18) - S[i]);
        }
        for(int i=0; i<count; i++){
        	
        	F_RHS[Boundary_nodes[i]] = 0;
        }
        return F_RHS;
        
}
