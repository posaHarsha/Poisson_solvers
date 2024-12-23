#include<stdio.h>
#include "Header/myheader.h"

int main(){
        //int* Testcase;
        //Testcase = SelectingTestCase();
	//Four Testcases are Available in the funtion Accesed by numbers 1 --> 4
        int z = 2;//Testcase[2];
        int Vl = 1;//Testcase[0];
        int Vr = 1;//Testcase[1];
        
	int* N;
	N = TotalElemNode();
	//Extract a 2x1 Vector has Number of nodes & Elements
	int n_nod,n_elem;
	n_nod = N[0];
	n_elem = N[1];
	float *V;
	
	
        int** Element_node;
        Element_node = ExtractElementNodes(n_elem,3);            
        float** NodeCoordinate;
        NodeCoordinate = ExtractNodeCoordinate(n_nod,3);            
        float* Ae;
        Ae = ExtractElementArea(n_nod,n_elem,Element_node,NodeCoordinate);
        int count = NumberofBoundaryNodes(n_nod,NodeCoordinate);
        int* Boundary_nodes;
        int* NodesCount;
        Boundary_nodes =  ExtractBoundaryNodes(n_nod,count,NodeCoordinate);
        V = InitialGuess(n_nod,Boundary_nodes,count,NodeCoordinate,Vl,Vr);
        NodesCount = NodeCount(n_elem,n_nod,count,Element_node,Ae,z,Boundary_nodes,NodeCoordinate,Vl,Vr,V);
	
        float** StiffnessMatrix;
        float* S;
        float* sol;
        float* F_RHS;
        //Newton-Raphson Method of Solving Non-Linear Equations
        while(1){
        	StiffnessMatrix = AssembleStiffnessMatrix(n_elem,n_nod,count,Element_node,NodeCoordinate,Ae,Boundary_nodes);    
        	S = RHS(n_elem,n_nod,count,Element_node,Ae,z,Boundary_nodes,NodeCoordinate,Vl,Vr,V); 
        	F_RHS = Final_RHS(StiffnessMatrix,V,S,n_nod,Boundary_nodes,count);
        	StiffnessMatrix = EditStiffness(StiffnessMatrix,V,S,n_nod,Boundary_nodes,count,NodesCount);
        	sol = GaussianSolver(n_nod,StiffnessMatrix,F_RHS);
        	for(int i =0; i<n_nod; i++){
        		V[i] = V[i] + sol[i];
        	}
        	if(max(n_nod,sol) < 0.05){
        		break;
        	}
        }
        
        WriteToFile(n_nod,V,NodeCoordinate);
}
