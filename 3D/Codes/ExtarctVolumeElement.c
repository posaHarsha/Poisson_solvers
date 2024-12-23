#include <math.h>
#include "Header/myheader.h"
#include<stdlib.h>

float *Volume(int total_nodes,int total_elements,int **a,float **b)
{
    float x[4],y[4],z[4];
    float b1,c1,d1;
    float* Ve = (float*)malloc(total_elements * sizeof(float));
    
    for(int j=0; j<total_elements; j++){
    for(int i =0; i<4 ; i++){
       x[i] = b[(a[j][i] - 1)][0] ;
    }
    for(int i =0; i<4 ; i++){
       y[i] = b[(a[j][i] - 1)][1] ;
    }
    for(int i =0; i<4 ; i++){
       z[i] = b[(a[j][i] - 1)][2] ;
    }
    
    
    b1 = (y[1]-y[3])*(z[2]-z[3]) -  (z[1]-z[3])*(y[2]-y[3]);
    c1 = (z[1]-z[3])*(x[2]-x[3]) -  (x[1]-x[3])*(z[2]-z[3]);
    d1 = (x[1]-x[3])*(y[2]-y[3]) -  (y[1]-y[3])*(x[2]-x[3]);
    Ve[j] = fabs((((x[0]-x[3])*b1) + ((y[0]-y[3])*c1) + ((z[0]-z[3])*d1))/6); 
    }
    return Ve;
    
}
