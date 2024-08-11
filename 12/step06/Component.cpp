#include "Node.h"
#include "Network.h"
#include "Component.h"
#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <cmath>
#include <iomanip>
using namespace std;

//Initializing static variable and it increments everytime the constructor is called
int Terminal::numComp = 0;

//Constructor
Terminal::Terminal()
{
    compIndex = numComp;
    numComp++;
    A = nullptr;
    B = nullptr;
}

//Accessor functions to get the index
int Terminal::getCompIndex() const
{
    return compIndex;
}

//Accessor functions to get the number of components
int Terminal::getNumComp()
{
    return numComp;
}

//Mutator function for node A pointer
void Terminal::setA(Node* one)
{
    A = one;
}

//Mutator function for node B pointer
void Terminal::setB(Node* two)
{
    B = two;
}

//Accessor function to get value of Terminal A Pointer
int Terminal::getNodeA() const
{
    return (*A).getIndex();
}

//Accessor function to get value of Terminal B Pointer
int Terminal::getNodeB() const
{
    return (*B).getIndex();
}

//Accessor function to get value of voltage
double Terminal::getVoltage() const
{
    double voltageA = (*A).getVolts();
    double voltageB = (*B).getVolts();

    return voltageB - voltageA;
}

//Member function that displays information to the user
void Terminal::out3(ofstream& out) const
{
    out << "Component # " << compIndex << " is connected between node ";
    
    out << (*A).getIndex()-1 << " and node " << (*B).getIndex()-1;

    if (getVoltage() < 0)
    {
        out << ".\nThe Voltage across Component # " << compIndex << " " << "= " <<  abs(getVoltage()) << " " << "Volts,\nwith the negative terminal at node " << (*B).getIndex() << ".\n";
    }
    else
    {
        out << ".\nThe Voltage across Component # " << compIndex << " " << "= " <<  abs(getVoltage()) << " " << "Volts,\nwith the negative terminal at node " << (*A).getIndex() << ".\n";
    }
}