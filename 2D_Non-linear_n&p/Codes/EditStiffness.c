#include "Header/myheader.h"
#include<math.h>
#define Nd 1e23
#define eo 105.3626e-12
#define q 1.6e-19
#define Kbt 26e-3
#define Nc 3e25
#define Nv 3e25
#define Eg 1.1

float **EditStiffness(float **StiffnessMatrix,float* V,float *S, int n_nod, int * Boundary_nodes, int count,int *NodesCount){
	for(int i =0; i<n_nod; i++){
        	for(int j=0; j<n_nod; j++){
        		if(i==j){
        			StiffnessMatrix[i][j] = (StiffnessMatrix[i][j]*1e18) - ((q*(((Nv*exp((-V[i]-1.1)/(Kbt))) + (Nc*exp(V[i]/(Kbt))))))/(eo*Kbt))*NodesCount[i];  
        	}
        	else{
        		StiffnessMatrix[i][j] = (StiffnessMatrix[i][j]*1e18);
        	}
        }
        }
        for(int i=0; i<count; i++){
        	StiffnessMatrix[Boundary_nodes[i]][Boundary_nodes[i]] = 1;
        	
        }
        return StiffnessMatrix;
}
