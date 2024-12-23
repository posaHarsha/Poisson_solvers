#include "Header/myheader.h"
#include<stdlib.h>

//Funtion will b in the Equation [A][x] = [b] after Changing some Values According to Boundary Conditions
float* RHS(int n_e,int n_n,int count,int**Element_node,float*Ve1,int z,int* Boundary_nodes,float** NodeCoordinate,int Vl, int Vr){
      
      float* S = (float*)malloc(n_e * sizeof(float));
      
      for(int i=0; i<n_n; i++){
        S[i] = 0;
    }
    for(int i=0; i<n_e; i++){
        S[Element_node[i][0] - 1] = S[Element_node[i][0] - 1] + -((Ve1[i]*z)/4); 
        S[Element_node[i][1] - 1] = S[Element_node[i][1] - 1] + -((Ve1[i]*z)/4); 
        S[Element_node[i][2] - 1] = S[Element_node[i][2] - 1] + -((Ve1[i]*z)/4); 
        S[Element_node[i][3] - 1] = S[Element_node[i][3] - 1] + -((Ve1[i]*z)/4);
    }

    //Changing the RHS Matrix Based on Boundary Conditions
    //Let's say you have an 5x5 Matrix and 3rd Node is on the Boundary then it change as follows
    //   | . |                   | . |
    //   | . |  _________ \      | . |
    //   | 4 |             \     | 1 |
    //   | . |  _________  /     | . |
    //   | . |            /      | . |
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
