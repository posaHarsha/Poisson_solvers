#include "Header/myheader.h"
#include<stdlib.h>

int* NodeCount(int n_e,int n_n,int count,int**Element_node,float*Ae,int z,int* Boundary_nodes,float** NodeCoordinate,int Vl, int Vr, float V[]){
      
      int* S = (int*)malloc(n_e * sizeof(int));
      
      for(int i=0; i<n_n; i++){
        S[i] = 0;
    }
    for(int i=0; i<n_e; i++){
        S[Element_node[i][0] - 1] += 1; 
        S[Element_node[i][1] - 1] += 1; 
        S[Element_node[i][2] - 1] += 1; 
        //S[Element_node[i][3] - 1] += 1;
    }

    return S;
}
