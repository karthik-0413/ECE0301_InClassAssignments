#include "Solhdeccic.cpp"
#include "Folhdeccic.cpp"
#include "Lhdeccic.cpp"
#include "Signal.cpp"
#include <iostream>
#include <fstream>

int main()
{
    ofstream outFile("ECE 0301 - Differential Equation Reports.txt");
/*
    Folhdeccic x(2, -1.25, 120);
    x.setDiffLabel("x");
    x.fillSolutionSignal();
    x.writeSolutionToFile(outFile);

    //b, to, k0, a, k1

    Solhdeccic y(2, 0, 0, 3, 250);
    y.setDiffLabel("y");
    y.outFile(outFile);
    y.writeSolutionToFile(outFile);
*/
    Solhdeccic s(4, 0, -50, 4, 500);
    s.setDiffLabel("s");
    s.outFile(outFile);
    s.writeSolutionToFile(outFile);
/*
    Solhdeccic g(101, -5, 100, 2, -100);
    g.setDiffLabel("g");
    g.outFile(outFile);
    g.writeSolutionToFile(outFile);
*/
    outFile.close();

    return 0;
}