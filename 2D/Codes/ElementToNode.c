#include "Header/myheader.h"
#include<stdio.h>
#include<stdlib.h>


int** ExtractElementNodes(int rows, int cols){

int** Element_node = (int**)malloc(rows * sizeof(int*));
        for (int i = 0; i < rows; i++) {
             Element_node[i] = (int*)malloc(cols * sizeof(int));
         }
         
    FILE *Input;
    Input = fopen("GMSH/square.msh", "r");
    if (Input == NULL)
    {
        perror("Error opening file UserInputMshFile");
        fclose(Input);
        
    }

    int n, d, e, f, g, n_e,m,h,node_num[3];
    float a, b, c;
    char buffer[100];

    for (int i = 0; i < 5; i++)
    {
        fgets(buffer, 100, Input);
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
    int Duplicate[1000][3];
    d = 0;
    f = 0;
    h=0;
    while (f < n)
    {
        fgets(buffer, 100, Input);
        sscanf(buffer, "%d %d %d %d", &e, &e, &g, &e);

        if(g==2){
        
        n_e = e;
        for (int i = 0; i < e; i++)
        {
            fgets(buffer, 100, Input);
            sscanf(buffer, "%d %d %d %d", &m, &node_num[0], &node_num[1], &node_num[2]);
            Duplicate[h][0] = node_num[0];
            Duplicate[h][1] = node_num[1];
            Duplicate[h][2] = node_num[2];
            h++;
        }
    }
    else if(g==15 || g==1 || g==4){
        for (int i = 0; i < e; i++)
        {
            fgets(buffer, 100, Input);
        }
    }
    

        f += e;
    }

    for (int i = 0; i < n_e; i++)
    {
        for (int j = 0; j < 3; j++)
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





