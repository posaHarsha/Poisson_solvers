#ifndef MY_HEADER
#define MY_HEADER

int* SelectingTestCase();
int** ExtractElementNodes(int,int);
float** ExtractNodeCoordinate(int,int);
int* TotalElemNode();
float *Volume(int total_nodes,int total_elements,int **a,float **b);
float* RHS(int n_e,int n_n,int count,int**arr,float*area,int z,int* Boundary_nodes,float** NodeCoordinate,int Vl, int Vr,float *V);
int NumberofBoundaryNodes(int n_n, float **arr);
int* ExtractBoundaryNodes(int n_n,int n, float **NodeCoordinate);
float** AssembleStiffnessMatrix(int n_e,int n_n,int count,int**arr,float**arr1,int* Boundary_nodes, float *Ve);
float* GaussianSolver(int n_n,float**StifnessMatrix,float*SMT);
void WriteToFile(int N, float *X, float **n_c);
float *Final_RHS(float **StiffnessMatrix, float* V,float *S, int n_nod, int * Boundary_nodes, int count);
float *InitialGuess(int n_nod,int * Boundary_nodes, int count, float ** NodeCoordinate, int Vl , int Vr);
float max(int n,float * arr);
float **EditStiffness(float **StiffnessMatrix,float* V,float *S, int n_nod, int * Boundary_nodes, int count, int *NodesCount);
int* NodeCount(int n_e,int n_n,int count,int**Element_node,float*Ae,int z,int* Boundary_nodes,float** NodeCoordinate,int Vl, int Vr, float* V);

#endif
