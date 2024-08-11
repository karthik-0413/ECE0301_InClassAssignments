#include "Solhdeccic.cpp"
#include "Lhdeccic.cpp"
#include <iostream>
#include <fstream>

int main()
{
    ofstream outFile("ECE 0301 - Differential Equation Reports.txt");

    Solhdeccic obj1;
    obj1.outFile(outFile);
    obj1.writeSolutionToFile(outFile);

    outFile.close();

    return 0;
}