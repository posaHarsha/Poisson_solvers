#include "/home/harsha/Documents/3D_2D_Possion_solver/2D/Codes/Header/myheader.h"
#include<stdlib.h>
#include<stdio.h>

int* SelectingTestCase(){
      int* Testcase = (int*)malloc(3 * sizeof(int));
      int a;
      printf("Enter the TestCase number(1-->4): ");
      scanf("%d",&a);
      if(a==1){
	      Testcase[0] = 1;
	      Testcase[1] = 9;
	      Testcase[2] = 0;
      }
      else if(a==2){
	      Testcase[0] = 1;
	      Testcase[1] = 1;
	      Testcase[2] = 4;
      }
      else if(a==3){
	      Testcase[0] = 1;
	      Testcase[1] = 1;
	      Testcase[2] = -4;
      }
      else if(a==4){
	      Testcase[0] = 1;
	      Testcase[1] = 9;
	      Testcase[2] = 6;
      }
      else{
	      Testcase[0] = 0;
	      Testcase[1] = 0;
	      Testcase[2] = 0;
      }
	      
return Testcase;
}
