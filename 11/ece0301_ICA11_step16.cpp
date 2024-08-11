#include "Signal.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

//Main Function
int main()
{
    // Create signals m, w, x, y, z
    Signal m(401, 10000, 0, "m", "0.75*cos(100*pi*t)");
    Signal w(401, 10000, 0, "w", "1");
    Signal x;
    x = m + w;
    Signal y(401, 10000, 0, "y", "120*cos(4000*pi*t)");
    Signal z;
    z = x * y;


    //Getting the signal array values with the give equation
    m.graph(0.75, 100*M_PI, 0);
    y.graph(120, 4000*M_PI, (-M_PI/4));

    //Setting function, setting constants, or rounding numbers
    m.round2();
    w.setConstant(1);
    w.round2();
    x.setFunction("x");
    x.round2();
    y.round2();
    z.setFunction("z");
    z.round2();

    //Calls the member function to write signal information to a text file
    m.outFile();
    w.outFile();
    x.outFile();
    y.outFile();
    z.outFile();

    //If the program gets to this stage, then it ends with returning 0 to the main function
    return 0;
}