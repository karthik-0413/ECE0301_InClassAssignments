#include "Solhdeccic.h"
#include "Lhdeccic.h"
#include "Signal.h"
#include <iostream>
#include <fstream>

int main()
{
    //Declaring an output file
    ofstream outFile;
    outFile.open("ECE 0301 - Differential Equation Reports.txt");

    //b, to, k0, a, k1

    //Making an object from the SOLHDECCIC Class
    Solhdeccic obj1(4, 0, -50, 4, 500);
    obj1.setDiffLabel("s");

    //Calling the member function that display the equation, initial conditions, and the solution
    obj1.outFile(outFile);
    obj1.outFile2(outFile);

    outFile.close();

    return 0;
}