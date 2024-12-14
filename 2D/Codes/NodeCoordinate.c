#include "Header/myheader.h"
#include<stdio.h>
#include<stdlib.h>


float** ExtractNodeCoordinate(int rows,int cols){

float** NodeCoordinate = (float**)malloc(rows * sizeof(float*));
        for (int i = 0; i < rows; i++) {
             NodeCoordinate[i] = (float*)malloc(cols * sizeof(float));
         }
    FILE *Input;
    Input = fopen("GMSH/square.msh", "r");
    if (Input == NULL)
    {
        perror("Error opening file UserInputMshFile");
        fclose(Input);
    }

    int n, d, e, f, g;
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
            NodeCoordinate[g][0] = a;
            NodeCoordinate[g][1] = b;
            NodeCoordinate[g][2] = c;
            g++;
        }

        f += e;
    }


    fclose(Input);
    return NodeCoordinate;
}
