#include <iostream>
#include <fstream>
#include "CurrentDivider.h"
#include "VoltageDivider.h"
#include "DCCurrentSource.h"
#include "DCVoltageSource.h"
#include <random>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    // Defining input file
    ifstream in;
    in.open("ECE 0301 - Circuits to Simulate.txt");

    // Defining output file
    ofstream out;
    out.open("ECE 0301 - Electrical Network Reports.txt");

    out << "ECE 0301 - Electrical Network Simulation\n";

    //Defining string variable to check if the loop should go on or not
    //string Circuit;
    /*
    //While loop to go throught the entire input text file
    while (getline(in, Circuit))
    {
        if (Circuit == "Voltage Divider")
        {
            double Vs, R1, R2;
            in >> Vs;
            in >> R1;
            in >> R2;
*/
            //Instance of the voltage divider class and calling its output file member function
            VoltageDivider vd;
            vd.out6(out);
        //}
        /*else if (Circuit == "Current Divider")
        {
            double Is, R11, R21;
            in >> Is;
            in >> R11;
            in >> R21;
*/
            //Instance of the current divider class and calling its output file member function
            CurrentDivider cd;
            cd.out8(out);
       //}

    //}

    return 0;
}