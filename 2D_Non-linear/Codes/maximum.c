#include "Header/myheader.h"
#include<math.h>

float max(int n,float arr[]){
   float max = fabs(arr[0]);
   for(int i = 0; i<n; i++){
      if (fabs(arr[i]) > max)
            max = fabs(arr[i]);
   }
   return max;
}
