#include "Folhdeccic.cpp"
#include "Lhdeccic.cpp"
#include <iostream>
#include <fstream>

int main()
{
    ofstream outFile("ECE 0301 - Differential Equation Reports.txt");

    Signal obj2(201, 20, 0.5);
    obj2.fillExponentialArray(2, 0.4);
    obj2.setFunction("w");


    Signal obj1(201, 20, 0.5);
    obj1.fillExponentialArray(1, -0.4);
    obj1.setFunction("v");

    obj2 = obj2 + obj1;
    obj2.outFile();
    //obj2.MATHGL();

    outFile.close();

    return 0;
}