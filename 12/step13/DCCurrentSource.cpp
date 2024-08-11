#include "VoltageDivider.h"
#include "Network.h"
#include "DCVoltageSource.h"
#include "DCCurrentSource.h"
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
using namespace std;

//Constructor
DCCurrentSource::DCCurrentSource()
{
    IS = 0;
}
/*
//Mutator function to set the source current
void DCCurrentSource::setIS(double I)
{
    IS = I;
}

//Accessor function to get the source current
double DCCurrentSource::getIS() const
{
    return IS;
}

//Accessor function to get the power from the source current
double DCCurrentSource::getPower() const
{
    return getIS() * getVoltage();
}

//Member function to write details about the source current to user
void DCCurrentSource::out7(ofstream& out)
{

    out << "\nComponent # " << getCompIndex()-1 << " is a DC Current Source, Is = " << IS << " Amps.\n";
    out3(out);

    out << "The current in this DC Current Source = " << abs(getIS()) << " Amps,\n" << "flowing from Node " << getNodeA() << " to Node " << getNodeB() << ".\n" << "The power supplied by this DC Current Source = " << getPower() << " Watts.\n";
}
*/