#include<stdlib.h>
#include "Header/myheader.h"

//Funtion will return the Final Stiffness Matrix After Assmebling all the Individual Element Matrices & Applying Nessasary Changess Corresponding to Bpoundary Conditions
float** AssembleStiffnessMatrix(int n_e,int n_n,int count,int**Element_node, float** NodeCoordinate, float* Ae,int* Boundary_nodes){
    float x21,x32,x13;
    float y12,y31,y23;
    float dnx[n_e][3],dny[n_e][3];
   
   //Allocating Memory for the StifnessMatrix 
    float** StiffnessMatrix = (float**)malloc(n_n * sizeof(float*));
        for (int i = 0; i < n_n; i++) {
             StiffnessMatrix[i] = (float*)malloc(n_n * sizeof(float));
         }
    
    //Finding the Derivative of Each of Basis Funtions with x & y for all the Elements
    for(int i=1; i < n_e + 1; i++){
       x21 = NodeCoordinate[(Element_node[i-1][1])-1][0] - NodeCoordinate[(Element_node[i-1][0])-1][0];
       x32 = NodeCoordinate[(Element_node[i-1][2])-1][0] - NodeCoordinate[(Element_node[i-1][1])-1][0];
       x13 = NodeCoordinate[(Element_node[i-1][0])-1][0] - NodeCoordinate[(Element_node[i-1][2])-1][0];
       y12 = NodeCoordinate[(Element_node[i-1][0])-1][1] - NodeCoordinate[(Element_node[i-1][1])-1][1];
       y31 = NodeCoordinate[(Element_node[i-1][2])-1][1] - NodeCoordinate[(Element_node[i-1][0])-1][1];
       y23 = NodeCoordinate[(Element_node[i-1][1])-1][1] - NodeCoordinate[(Element_node[i-1][2])-1][1];
       dnx[i-1][0] = y23/(2*Ae[i-1]); 
       dnx[i-1][1] = y31/(2*Ae[i-1]); 
       dnx[i-1][2] = y12/(2*Ae[i-1]); 
       dny[i-1][0] = x32/(2*Ae[i-1]); 
       dny[i-1][1] = x13/(2*Ae[i-1]); 
       dny[i-1][2] = x21/(2*Ae[i-1]); 
    }

    //Finding the Stifness Matrix for Individual Element
    float M[n_e][3][3];

            for(int k = 0;k<n_e; k++){
                for(int i=0; i<3; i++){
                    for(int j =0; j<3; j++){
                        M[k][i][j] = -Ae[k]*((dnx[k][i]*dnx[k][j])+(dny[k][i]*dny[k][j]));
                    }
                }
                    }
                
    //Initializing the Stifness Matrix to all Zeros
    for (int i = 0; i < n_n; i++)
    {
        for (int j = 0; j < n_n; j++)
        {
            StiffnessMatrix[i][j] = 0;
        }
    }

    //Assembling the Individual Stiffness Matrix to a big Stifness Matrix
    for(int k=0; k<n_e; k++){
        for(int i=0; i<3; i++){
                    for(int j =0; j<3; j++){
        StiffnessMatrix[Element_node[k][i]-1][Element_node[k][j]-1] += M[k][i][j];
                    }
        }
    }

    //Changing the Stiffness Matrix Based on Boundary Conditions
    //Let's say you have an 5x5 Matrix and 3rd Node is on the Boundary then it change as follows
    //   | . . . . . |                   | . . . . . |
    //   | . . . . . |  _________ \      | . . . . . |
    //   | 1 2 0 1 4 |             \     | 0 0 1 0 0 |
    //   | . . . . . |  _________  /     | . . . . . |
    //   | . . . . . |            /      | . . . . . |
    for(int i=0; i<count; i++){
          for(int k=0; k<n_n; k++){
        StiffnessMatrix[Boundary_nodes[i]][k] = 0;
     }
     StiffnessMatrix[Boundary_nodes[i]][Boundary_nodes[i]] = 1;
     }
    
    return StiffnessMatrix;

}
