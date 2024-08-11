#include "Folhdeccic.h"
#include "Lhdeccic.h"
#include "Signal.h"
#include <iostream>
#include <fstream>

int main()
{
    //Declaring an output file
    ofstream outFile;
    outFile.open("ECE 0301 - Differential Equation Reports.txt");

    //Making an object from the FOLHDECCIC Class 
    Folhdeccic obj2(2, -1.25, 120);

    //Changing the function label to "x"
    obj2.setDiffLabel("x");

    //Calling the member function that display the equation, initial conditions, and the solution
    obj2.outFile(outFile);
    obj2.outFile2(outFile);

    //Closing the output file
    outFile.close();

    //If the program makes to this step, then it returns 0 to the main and ends the program
    return 0;
}