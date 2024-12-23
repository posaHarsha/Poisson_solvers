#include "Header/myheader.h"
#include<stdio.h>

int* TotalElemNode(){
    FILE *Input;
    Input = fopen("GMSH/cube1.msh", "r");
    if (Input == NULL)
    {
        perror("Error opening file UserInputMshFile");
        fclose(Input);
    }

    int n, d, e, f, g,n_e,n_n;
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
    n_n = n;
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
    d = 0;
    f = 0;
    while (f < n)
    {
        fgets(buffer, 100, Input);
        sscanf(buffer, "%d %d %d %d", &e, &e, &g, &e);

        if(g==4){
        n_e = e;
    }
    else if(g==15 || g==1 || g==2){
        for (int i = 0; i < e; i++)
        {
            fgets(buffer, 100, Input);
        }
    }
    

        f += e;
    }
    int static N[2];
    N[0] = n_n;
    N[1] = n_e;
    return N;

    fclose(Input);

}
