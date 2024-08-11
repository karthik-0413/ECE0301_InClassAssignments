/*#include "VoltageDivider.h"
#include "Network.h"
#include "DCVoltageSource.h"
#include "Resistor.h"
#include "Node.h"
#include "Component.h"
#include "CurrentDivider.h"
#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <cmath>
#include <iomanip>
#include <cmath>
using namespace std;

// Constructor
Resistor::Resistor()
{
    resistance = 1000;
}

//Mutator function to set resistance value
void Resistor::setResistance(double resis)
{
    resistance = resis;
}

//Accessor function to get resistor value
double Resistor::getResistance() const
{
    return resistance;
}

// Accessor function to return current value
double Resistor::getCurrent() const
{
    double volt = getVoltage();
    return volt / resistance;
}

//Member function that returns the power supplied by the resistor
double Resistor::getPower() const
{
    return pow(getCurrent(), 2) * resistance;
}

//Member function to write details about the resistor to user
void Resistor::out5(ofstream& out)
{
    
    out << "\nComponent # " << getCompIndex() << " is a Resistor, R = " << getResistance() << " Ohms.\n";
    
    out3(out);

    out << "The current in this Resistor = " << abs(getCurrent()) << " Amps,\n" << "flowing from Node ";

    if (getCurrent() > 0)
    {
        out << getNodeB()-1 << " to Node " << getNodeA()-1 << ".\n";
    }
    else
    {
        out << getNodeA()-1 << " to Node " << getNodeB()-1 << ".\n";
    }

    out << "The power dissipated in this Resistor = " << getPower() << " Watts." << endl;
}
*/