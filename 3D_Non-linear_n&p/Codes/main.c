#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Header/myheader.h"





int main()
{
    float Vr,Vl;
    int z;
    Vr = -0.142;
    Vl = -0.442;
    z = 4;
    int * N1 = TotalElemNode();
    int n_e,n_n;
    n_n = N1[0];
    n_e = N1[1];
    int** Element_node;
    Element_node = ExtractElementNodes(n_e,4);            
        
    float** NodeCoordinate;
    NodeCoordinate = ExtractNodeCoordinate(n_n,3); 
    
    int count;
    count = NumberofBoundaryNodes(n_n,NodeCoordinate);
    
    int * Boundary_nodes;
    float *Ve1;
    Ve1 = Volume(n_n,n_e,Element_node,NodeCoordinate);
    float *V;
    int * NodesCount;
    
    
    Boundary_nodes = ExtractBoundaryNodes(n_n,count,NodeCoordinate);
    V = InitialGuess(n_n,Boundary_nodes,count,NodeCoordinate,Vl,Vr);
    //printf("%d = count\n",count);
    NodesCount = NodeCount(n_e,n_n,count,Element_node,Ve1,z,Boundary_nodes,NodeCoordinate,Vl,Vr,V);
    
    float** StiffnessMatrix;
    float * S;
    float *F_RHS;
    float * sol;
    while(1){
        	StiffnessMatrix = AssembleStiffnessMatrix(n_e,n_n,count,Element_node,NodeCoordinate,Boundary_nodes,Ve1);   
        	S = RHS(n_e,n_n,count,Element_node,Ve1,z,Boundary_nodes,NodeCoordinate,Vl,Vr,V);
        	F_RHS = Final_RHS(StiffnessMatrix,V,S,n_n,Boundary_nodes,count);
        	StiffnessMatrix = EditStiffness(StiffnessMatrix,V,S,n_n,Boundary_nodes,count,NodesCount);
        	sol = GaussianSolver(n_n,StiffnessMatrix,F_RHS);
        	for(int i =0; i<n_n; i++){
        		V[i] = V[i] + sol[i];
        	}
        	if(max(n_n,sol) < 0.009){
        		break;
        	}
        	printf("Doing ");
        }
    
     
    
   
     
    //V111 = GaussianSolver(n_n,StiffnessMatrix,S);
     
    
    float Ec[n_n];
    for(int i =0; i<n_n; i++){
        		Ec[i] = -V[i]; //V[i] = V[i] + sol[i];
        	}
    printf("%d \n",n_n);
    WriteToFile(n_n,Ec,NodeCoordinate);

    
}
