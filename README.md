# Poisson_solvers
C code for solving 2D Possion Equation Using FEM for Triangular Elements
We are Solving Equation for a Square of 4x4 size for Dirclet Boundary Conditions at x=0 & x=4


#### Changes before Running in your system:

--> In the File Testcase of TestCases Folder First line is

    #include "/home/harsha/Documents/3D_2D_Possion_solver/2D/Codes/Header/myheader.h"
    change it to 
    #include "(your_path)/2D/Codes/Header/myheader.h"

#### Instructions for running the Code:

--> In the Terminal of 2D folder run Below Commands

    make clean
    make
    ./solver
    (Enter a number b/w 1 & 4 for Different Test Cases)
    make plot

You Should See a 3D Plot of the Solution Based on Number you Entered

#### Changes after Each command Execution:

--> make clean command will delete all the .o files (if any)

--> After make command Executable file solver is Generated

--> After ./solver command a CSV file Contains Solution is Generated

--> make plot will Execute a python code that Generate the 3D plot of CSV file
    
