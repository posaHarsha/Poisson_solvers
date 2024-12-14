#include "Header/myheader.h"
#include<stdlib.h>

float* RHS(int n_e,int n_n,int count,int**Element_node,float*Ae,int z,int* Boundary_nodes,float** NodeCoordinate,int Vl, int Vr){
      
      float* S = (float*)malloc(n_e * sizeof(float));
      
      for(int i=0; i<n_n; i++){
        S[i] = 0;
    }
    for(int i=0; i<n_e; i++){
        S[Element_node[i][0] - 1] = S[Element_node[i][0] - 1] + ((z*Ae[i])/3); 
        S[Element_node[i][1] - 1] = S[Element_node[i][1] - 1] + ((z*Ae[i])/3); 
        S[Element_node[i][2] - 1] = S[Element_node[i][2] - 1] + ((z*Ae[i])/3); 
    }
    for(int i=0; i<count; i++){
     if(NodeCoordinate[Boundary_nodes[i]][0] == 0){
     S[Boundary_nodes[i]] = Vl;
     }
     else if(NodeCoordinate[Boundary_nodes[i]][0] == 4){
     S[Boundary_nodes[i]] = Vr;
     }
     }
    
    return S;
}
