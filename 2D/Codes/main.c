#include<stdio.h>
#include "Header/myheader.h"

int main(){
        int* Testcase;
        Testcase = SelectingTestCase();
	//Four Testcases are Available in the funtion Accesed by numbers 1 --> 4
        int z = Testcase[2];
        int Vl = Testcase[0];
        int Vr = Testcase[1];
        
	int* N;
	N = TotalElemNode();
	//Extract a 2x1 Vector has Number of nodes & Elements
	int n_nod,n_elem;
	n_nod = N[0];
	n_elem = N[1];
	
	int** Element_node;
        Element_node = ExtractElementNodes(n_elem,3);            
        //Extracting 2D ARRAY with Element and Corresponding Node Numbers
        
        float** NodeCoordinate;
        NodeCoordinate = ExtractNodeCoordinate(n_nod,3);            
        //Extracting 2D ARRAY with Node and It's Coordinates
        
        float* Ae;
        Ae = ExtractElementArea(n_nod,n_elem,Element_node,NodeCoordinate);
        //Extarcting the  Area of Each Element
        
        int count = NumberofBoundaryNodes(n_nod,NodeCoordinate);
	//Extracting the number of Nodes on Boundary
        
        int* Boundary_nodes;
        Boundary_nodes =  ExtractBoundaryNodes(n_nod,count,NodeCoordinate);
	//Extracting the Node Numbers of Nodes that are ON Boundary
        
        float** StiffnessMatrix;
        StiffnessMatrix = AssembleStiffnessMatrix(n_elem,n_nod,count,Element_node,NodeCoordinate,Ae,Boundary_nodes);
        //Extarcting the final StifnessMatrix
	
        float* S;
        S = RHS(n_elem,n_nod,count,Element_node,Ae,z,Boundary_nodes,NodeCoordinate,Vl,Vr);
	//Extarcting the Final RHS Matrix
        
        float* sol;
        sol = GaussianSolver(n_nod,StiffnessMatrix,S);
	//Final Potential at Each point in the Sqaure Exracted in 1D ARRAY with corresponding Node Numbers 
        
        WriteToFile(n_nod,sol,NodeCoordinate);
	//Writing all the Coordinates & Potential at the Respective Coordinates into a CSV File
}
