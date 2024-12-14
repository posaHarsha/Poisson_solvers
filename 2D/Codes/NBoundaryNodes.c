#include "Header/myheader.h"

int NumberofBoundaryNodes(int n_n, float **NodeCoordinate){

    int count = -1;
    for(int i=1; i<n_n + 1; i++){
        if(NodeCoordinate[i-1][0] == 0){
            count ++;
        }
        else if(NodeCoordinate[i-1][0] == 4){
            count ++;
        }
    }
    return count+1;
    }
