#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Header/myheader.h"





int main()
{
    int Vr,Vl;
    int z;
    Vr = 1;
    Vl =1;
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
    float *V111;
    
    Boundary_nodes = ExtractBoundaryNodes(n_n,count,NodeCoordinate);
    //printf("%d = count\n",count);
    
    float** StiffnessMatrix;
    StiffnessMatrix = AssembleStiffnessMatrix(n_e,n_n,count,Element_node,NodeCoordinate,Boundary_nodes,Ve1);
     
    float * S;
    S = RHS(n_e,n_n,count,Element_node,Ve1,z,Boundary_nodes,NodeCoordinate,Vl,Vr);
     
    V111 = GaussianSolver(n_n,StiffnessMatrix,S);
     
    WriteToFile(n_n,V111,NodeCoordinate);
    printf("%d \n",n_n);

    
}
