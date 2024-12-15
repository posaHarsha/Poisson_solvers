#include "Header/myheader.h"
#include<stdlib.h>

//Funtion will Extract the Node numbers of all the Nodes that are on Boundary
int* ExtractBoundaryNodes(int n_n,int n, float **NodeCoordinate){
    int* y = (int*)malloc(n * sizeof(int));
    int count = -1;

    // Applying Dirclet Bounary Conditions
    for(int i=1; i<n_n + 1; i++){
        if(NodeCoordinate[i-1][0] == 0){
            count ++;
            y[count] = i-1;
        }
        else if(NodeCoordinate[i-1][0] == 4){
            count ++;
           y[count] = i-1;
        }
    }
    return y;
    }
