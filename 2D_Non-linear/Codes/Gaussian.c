#include "Header/myheader.h"
#include<stdlib.h>

//Funtion to solve [A][x] = [b] Equation Using Gaussian Elimination and Returning the [x]
float* GaussianSolver(int n_n,float** StiffnessMatrix,float* SMT){

      float* sol = (float*)malloc(n_n * sizeof(float));
      
      for(int k = 0 ; k<n_n-1; k++){
        for(int i=k+1; i<n_n;i++){
            float factor = StiffnessMatrix[i][k]/StiffnessMatrix[k][k];
            for(int j = k+1; j<n_n; j++){
                StiffnessMatrix[i][j] = StiffnessMatrix[i][j] - factor*StiffnessMatrix[k][j];
            }
            SMT[i]=SMT[i]- factor*SMT[k];
        }
    }
    sol[n_n-1]=SMT[n_n-1]/StiffnessMatrix[n_n-1][n_n-1];
    for(int i = n_n-2; i>=0; i--){
        float sum = SMT[i];
        for(int j = i+1; j<n_n; j++){
            sum = sum - StiffnessMatrix[i][j]*sol[j];
        }
        sol[i] = sum/StiffnessMatrix[i][i];
     }
     return sol;
}
