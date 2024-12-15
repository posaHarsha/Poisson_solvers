#include "Header/myheader.h"
#include<stdlib.h>
#include<math.h>


//Funtion will Extract the Area of Each Trinagular Element
float* ExtractElementArea(int total_nodes,int total_elements,int **a,float **b)
{
    float x[3],y[3];
    float* area = (float*)malloc(total_elements * sizeof(float));
    
    for(int j =1; j<total_elements+1; j++){
        for(int i =0; i<3 ; i++){
            x[i] = b[(a[j-1][i] - 1)][0] ;
            }
        for(int i =0; i<3 ; i++){
            y[i] = b[(a[j-1][i] - 1)][1] ;
            }
    area[j-1] = fabs(0.5*((x[0]*(y[1]-y[2])) + (x[1]*(y[2]-y[0])) + (x[2]*(y[0]-y[1]))));
    }
    return area;
    
}
