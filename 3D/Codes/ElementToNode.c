#include "Header/myheader.h"
#include<stdio.h>
#include<stdlib.h>


//The Funtion will Return a 2D Array contains the corresponding Node Numbers of Each Element
//Row number Corresponds to Element number and the 3  Entries in the Row Corresponds to the the Node numbers Associated with the Element
int** ExtractElementNodes(int rows, int cols){

	//Allocting Memory to the 2D Array
        int** Element_node = (int**)malloc(rows * sizeof(int*));
        for (int i = 0; i < rows; i++) {
             Element_node[i] = (int*)malloc(cols * sizeof(int));
         }
         
    FILE *Input;
    Input = fopen("GMSH/cube1.msh", "r");
    if (Input == NULL)
    {
        perror("Error opening file UserInputMshFile");
        fclose(Input);
        
    }

    int n, d, e, f, g, n_e,m,h,node_num[4];
    float a, b, c;
    char buffer[100];
    //buffer can read upto 100 characters in the line

    for (int i = 0; i < 5; i++)
    {
        fgets(buffer, 100, Input);//this will take the cursor to the Next line
    }

    sscanf(buffer, "%d %d %d %d", &d, &e, &f, &g);


    for (int i = 0; i < d; i++)
    {
        fgets(buffer, 100, Input);
    }

    for (int i = 0; i < e; i++)
    {
        fgets(buffer, 100, Input);
    }
   

    for (int i = 0; i < f; i++)
    {
        fgets(buffer, 100, Input);
    }

    for (int i = 0; i < g; i++)
    {
        fgets(buffer, 100, Input);
    }

    for (int i = 0; i < 3; i++)
    {
        fgets(buffer, 100, Input);
    }
    int n1[2];
    sscanf(buffer, "%d %d %d %d", &n1[0], &n1[1], &n1[2], &n);
    f = 0;
    g = 0;

    while (f < n)
    {
        fgets(buffer, 100, Input);
        sscanf(buffer, "%d %d %d %d", &e, &e, &e, &e);
        for (int i = 0; i < e; i++)
        {
            fgets(buffer, 100, Input);
        }

        for (int i = 0; i < e; i++)
        {
            fgets(buffer, 100, Input);
            sscanf(buffer, "%f %f %f", &a, &b, &c);
            g++;
        }

        f += e;
    }

    for (int i = 0; i < 3; i++)
    {
        fgets(buffer, 100, Input);
    }

    sscanf(buffer, "%d %d %d %d", &n, &n, &n, &n);
    int Duplicate[10000][4];
    d = 0;
    f = 0;
    h=0;
    while (f < n)
    {
        fgets(buffer, 100, Input);
        sscanf(buffer, "%d %d %d %d", &e, &e, &g, &e);

        if(g==4){
        
        n_e = e;
        for (int i = 0; i < e; i++)
        {
            fgets(buffer, 100, Input);
            sscanf(buffer, "%d %d %d %d %d", &m, &node_num[0], &node_num[1], &node_num[2], &node_num[3]);
            Duplicate[h][0] = node_num[0];
            Duplicate[h][1] = node_num[1];
            Duplicate[h][2] = node_num[2];
            Duplicate[h][3] = node_num[3];
            h++;
        }
    }
    else if(g==15 || g==1 || g==2){
        for (int i = 0; i < e; i++)
        {
            fgets(buffer, 100, Input);
        }
    }
    

        f += e;
    }

    for (int i = 0; i < n_e; i++)
    {
        for (int j = 0; j < 4; j++)
    {
           Element_node[i][j] = Duplicate[i][j];
    }
    }
   
    
    for (int i = 0; i < 3; i++)
    {
        fgets(buffer, 100, Input);
    }

    fclose(Input);
    return Element_node;
    }





