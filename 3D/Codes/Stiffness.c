#include<stdlib.h>
#include "Header/myheader.h"

//Funtion will return the Final Stiffness Matrix After Assmebling all the Individual Element Matrices & Applying Nessasary Changess Corresponding to Bpoundary Conditions
float** AssembleStiffnessMatrix(int n_e,int n_n,int count,int**Element_node, float** NodeCoordinate,int* Boundary_nodes, float*Ve){
    float x03,y03,z03,x13,y13,z13,x23,y23,z23;
    float S1[3],S2[3],S3[3],S4[3];
    float M11;
    float M12;
    float M13;
    float M14;
    float M22;
    float M23;
    float M24;
    float M33;
    float M34;
    float M44;
    float M21;
    float M31;
    float M41;
    float M42;
    float M43;
    float M32;
   
   //Allocating Memory for the StifnessMatrix 
    float** StiffnessMatrix = (float**)malloc(n_n * sizeof(float*));
        for (int i = 0; i < n_n; i++) {
             StiffnessMatrix[i] = (float*)malloc(n_n * sizeof(float));
         }
    //Initializing the Stifness Matrix to all Zeros     
    for (int i = 0; i < n_n; i++)
    {
        for (int j = 0; j < n_n; j++)
        {
            StiffnessMatrix[i][j] = 0;
        }
    }
    for(int i =0; i<n_e; i++){
    x03 = NodeCoordinate[Element_node[i][0]-1][0] -  NodeCoordinate[Element_node[i][3]-1][0];
    x13 = NodeCoordinate[Element_node[i][1]-1][0] -  NodeCoordinate[Element_node[i][3]-1][0];
    x23 = NodeCoordinate[Element_node[i][2]-1][0] -  NodeCoordinate[Element_node[i][3]-1][0];
    y03 = NodeCoordinate[Element_node[i][0]-1][1] -  NodeCoordinate[Element_node[i][3]-1][1];
    y13 = NodeCoordinate[Element_node[i][1]-1][1] -  NodeCoordinate[Element_node[i][3]-1][1];
    y23 = NodeCoordinate[Element_node[i][2]-1][1] -  NodeCoordinate[Element_node[i][3]-1][1];
    z03 = NodeCoordinate[Element_node[i][0]-1][2] -  NodeCoordinate[Element_node[i][3]-1][2];
    z13 = NodeCoordinate[Element_node[i][1]-1][2] -  NodeCoordinate[Element_node[i][3]-1][2];
    z23 = NodeCoordinate[Element_node[i][2]-1][2] -  NodeCoordinate[Element_node[i][3]-1][2];
    S1[0] = y13*z23 - z13*y23; 
    S1[1] = z13*x23 - x13*z23;
    S1[2] = x13*y23 - y13*x23; 
    S2[0] = y23*z03 - z23*y03; 
    S2[1] = z23*x03 - x23*z03;
    S2[2] = x23*y03 - y23*x03;
    S3[0] = y03*z13 - z03*y13; 
    S3[1] = z03*x13 - x03*z13;
    S3[2] = x03*y13 - y03*x13;
    S4[0] = -(S1[0] + S2[0] + S3[0]);
    S4[1] = -(S1[1] + S2[1] + S3[1]);
    S4[2] = -(S1[2] + S2[2] + S3[2]);
    M11 = (S1[0]*S1[0] + S1[1]*S1[1] + S1[2]*S1[2])/(36*Ve[i]);
    M12 = (S1[0]*S2[0] + S1[1]*S2[1] + S1[2]*S2[2])/(36*Ve[i]);
    M13 = (S1[0]*S3[0] + S1[1]*S3[1] + S1[2]*S3[2])/(36*Ve[i]);
    M14 = (S1[0]*S4[0] + S1[1]*S4[1] + S1[2]*S4[2])/(36*Ve[i]);
    M22 = (S2[0]*S2[0] + S2[1]*S2[1] + S2[2]*S2[2])/(36*Ve[i]);
    M23 = (S2[0]*S3[0] + S2[1]*S3[1] + S2[2]*S3[2])/(36*Ve[i]);
    M24 = (S2[0]*S4[0] + S2[1]*S4[1] + S2[2]*S4[2])/(36*Ve[i]);
    M33 = (S3[0]*S3[0] + S3[1]*S3[1] + S3[2]*S3[2])/(36*Ve[i]);
    M34 = (S3[0]*S4[0] + S3[1]*S4[1] + S3[2]*S4[2])/(36*Ve[i]);
    M44 = (S4[0]*S4[0] + S4[1]*S4[1] + S4[2]*S4[2])/(36*Ve[i]);
    M21 = M12;
    M31 = M13;
    M41 = M14;
    M42 = M24;
    M43 = M34;
    M32 = M23;
        StiffnessMatrix[Element_node[i][0]-1][Element_node[i][0]-1] = M11 + StiffnessMatrix[Element_node[i][0]-1][Element_node[i][0]-1];
        StiffnessMatrix[Element_node[i][0]-1][Element_node[i][1]-1] = M12 + StiffnessMatrix[Element_node[i][0]-1][Element_node[i][1]-1]; 
        StiffnessMatrix[Element_node[i][1]-1][Element_node[i][0]-1] = M21 + StiffnessMatrix[Element_node[i][1]-1][Element_node[i][0]-1]; 
        StiffnessMatrix[Element_node[i][0]-1][Element_node[i][2]-1] = M13 + StiffnessMatrix[Element_node[i][0]-1][Element_node[i][2]-1]; 
        StiffnessMatrix[Element_node[i][2]-1][Element_node[i][0]-1] = M31 + StiffnessMatrix[Element_node[i][2]-1][Element_node[i][0]-1]; 
        StiffnessMatrix[Element_node[i][1]-1][Element_node[i][1]-1] = M22 + StiffnessMatrix[Element_node[i][1]-1][Element_node[i][1]-1]; 
        StiffnessMatrix[Element_node[i][1]-1][Element_node[i][2]-1] = M23 + StiffnessMatrix[Element_node[i][1]-1][Element_node[i][2]-1]; 
        StiffnessMatrix[Element_node[i][2]-1][Element_node[i][1]-1] = M32 + StiffnessMatrix[Element_node[i][2]-1][Element_node[i][1]-1]; 
        StiffnessMatrix[Element_node[i][2]-1][Element_node[i][2]-1] = M33 + StiffnessMatrix[Element_node[i][2]-1][Element_node[i][2]-1]; 
        StiffnessMatrix[Element_node[i][3]-1][Element_node[i][0]-1] = M41 + StiffnessMatrix[Element_node[i][3]-1][Element_node[i][0]-1]; 
        StiffnessMatrix[Element_node[i][3]-1][Element_node[i][1]-1] = M42 + StiffnessMatrix[Element_node[i][3]-1][Element_node[i][1]-1]; 
        StiffnessMatrix[Element_node[i][3]-1][Element_node[i][2]-1] = M43 + StiffnessMatrix[Element_node[i][3]-1][Element_node[i][2]-1];
        StiffnessMatrix[Element_node[i][0]-1][Element_node[i][3]-1] = M14 + StiffnessMatrix[Element_node[i][0]-1][Element_node[i][3]-1];
        StiffnessMatrix[Element_node[i][1]-1][Element_node[i][3]-1] = M24 + StiffnessMatrix[Element_node[i][1]-1][Element_node[i][3]-1];
        StiffnessMatrix[Element_node[i][2]-1][Element_node[i][3]-1] = M34 + StiffnessMatrix[Element_node[i][2]-1][Element_node[i][3]-1];
        StiffnessMatrix[Element_node[i][3]-1][Element_node[i][3]-1] = M44 + StiffnessMatrix[Element_node[i][3]-1][Element_node[i][3]-1];
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
