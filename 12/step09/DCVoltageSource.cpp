
#include "DCVoltageSource.h"
#include "Component.h"
#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <cmath>
#include <iomanip>
using namespace std;

//Constructor
DCVoltageSource::DCVoltageSource()
{
    Vs = 0;
}

//Mutator function to set voltage value
void DCVoltageSource::setVS(double voltage)
{
    Vs = voltage;
}

// Accessor function to return voltage value
double DCVoltageSource::getVS() const
{
    return Vs;
}

//Mutator function to set current value
void DCVoltageSource::setCurrent(double curr)
{
    current = curr;
}

// Accessor function to return current value
double DCVoltageSource::getCurrent() const
{
    return current;
}

//Member function that returns the power supplied by the source
double DCVoltageSource::getPower() const
{
    return Vs * current;
}

// Member function to write details about DC voltage source to user
void DCVoltageSource::out4(std::ofstream& out)
{
    out << "\nComponent # " << getCompIndex() << " is a DC Voltage Source, Vs = " << getVS() << " Volts.\n";
    
    out3(out);

    out << "The current in this DC Voltage Source = " << abs(current) << " Amps,\n" << "flowing from Node ";

    if (getCurrent() < 0)
    {
        out << getNodeB()-1 << " to Node " << getNodeA()-1 << ".\n";
    } else
    {
        out << getNodeA()-1 << " to Node " << getNodeB()-1 << ".\n";
    }

    out << "The power supplied by this DC Voltage Source = " << getPower() << " Watts.\n";

}