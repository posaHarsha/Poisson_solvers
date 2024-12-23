#ifndef MY_HEADER
#define MY_HEADER

int* SelectingTestCase();
int** ExtractElementNodes(int,int);
float** ExtractNodeCoordinate(int,int);
int* TotalElemNode();
float *Volume(int total_nodes,int total_elements,int **a,float **b);
float* RHS(int n_e,int n_n,int count,int**arr,float*area,int z,int* Boundary_nodes,float** NodeCoordinate,int Vl, int Vr);
int NumberofBoundaryNodes(int n_n, float **arr);
int* ExtractBoundaryNodes(int n_n,int n, float **NodeCoordinate);
float** AssembleStiffnessMatrix(int n_e,int n_n,int count,int**arr,float**arr1,int* Boundary_nodes, float *Ve);
float* GaussianSolver(int n_n,float**StifnessMatrix,float*SMT);
void WriteToFile(int N, float *X, float **n_c);

#endif
