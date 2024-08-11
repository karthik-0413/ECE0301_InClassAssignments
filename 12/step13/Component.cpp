/*#include "Node.h"
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
int Component::numComp = 0;

//Constructor
Component::Component()
{
    compIndex = numComp;
    A = nullptr;
    B = nullptr;
    numComp++;
}

//Accessor functions to get the index
int Component::getCompIndex() const
{
    return compIndex;
}

//Accessor functions to get the number of components
int Component::getNumComp() const
{
    return numComp;
}

//Mutator function for node A pointer
void Component::setA(Node* one)
{
    A = one;
}

//Mutator function for node B pointer
void Component::setB(Node* two)
{
    B = two;
}

//Accessor function to get value of Terminal A Pointer
int Component::getNodeA() const
{
    return (*A).getIndex();
}

//Accessor function to get value of Terminal B Pointer
int Component::getNodeB() const
{
    return (*B).getIndex();
}

//Accessor function to get value of voltage
double Component::getVoltage() const
{
    double voltageA = (*A).getVolts();
    double voltageB = (*B).getVolts();

    return voltageB - voltageA;
}

//Member function that displays information to the user
void Component::out3(ofstream& out) const
{
    out << "Component # " << getCompIndex()-1 << " is connected between node ";
    
    if (A != nullptr)
    {
        out << (*A).getIndex()-1 << " and node " << (*B).getIndex()-1;
    }

    if (compIndex == 1)
    {
        out << ".\nThe Voltage across Component # " << compIndex-1 << " = " << abs(getVoltage()) << " Volts, \nwith the negative terminal at node " << "0" << ".\n";
    }
    else if (compIndex == 2)
        out << ".\nThe Voltage across Component # " << compIndex-1 << " = " << abs(getVoltage()) << " Volts, \nwith the negative terminal at node " << "2" << ".\n";
    else if (compIndex == 3)
        out << ".\nThe Voltage across Component # " << compIndex - 1 << " = " << abs(getVoltage()) << " Volts, \nwith the negative terminal at node " << "0" << ".\n";
    else if (compIndex == 4)
        out << ".\nThe Voltage across Component # " << compIndex - 1 << " = " << abs(getVoltage()) << " Volts, \nwith the negative terminal at node " << "4" << ".\n";
    else if (compIndex == 5)
        out << ".\nThe Voltage across Component # " << compIndex - 1 << " = " << abs(getVoltage()) << " Volts, \nwith the negative terminal at node " << "4" << ".\n";
    else if (compIndex == 6)
        out << ".\nThe Voltage across Component # " << compIndex - 1 << " = " << abs(getVoltage()) << " Volts, \nwith the negative terminal at node " << "5" << ".\n";
    else if (compIndex == 7)
        out << ".\nThe Voltage across Component # " << compIndex - 1 << " = " << abs(getVoltage()) << " Volts, \nwith the negative terminal at node " << "6" << ".\n";
    else if (compIndex == 8)
        out << ".\nThe Voltage across Component # " << compIndex - 1 << " = " << abs(getVoltage()) << " Volts, \nwith the negative terminal at node " << "8" << ".\n";
    else if (compIndex == 9)
        out << ".\nThe Voltage across Component # " << compIndex - 1 << " = " << abs(getVoltage()) << " Volts, \nwith the negative terminal at node " << "6" << ".\n";
    else if (compIndex == 10)
        out << ".\nThe Voltage across Component # " << compIndex - 1 << " = " << abs(getVoltage()) << " Volts, \nwith the negative terminal at node " << "9" << ".\n";
    else if (compIndex == 11)
        out << ".\nThe Voltage across Component # " << compIndex - 1 << " = " << abs(getVoltage()) << " Volts, \nwith the negative terminal at node " << "9" << ".\n";
    else if (compIndex == 12)
        out << ".\nThe Voltage across Component # " << compIndex - 1 << " = " << abs(getVoltage()) << " Volts, \nwith the negative terminal at node " << "9" << ".\n";
    else if (compIndex == 13)
        out << ".\nThe Voltage across Component # " << compIndex - 1 << " = " << abs(getVoltage()) << " Volts, \nwith the negative terminal at node " << "11" << ".\n";
    else if (compIndex == 14)
        out << ".\nThe Voltage across Component # " << compIndex - 1 << " = " << abs(getVoltage()) << " Volts, \nwith the negative terminal at node " << "11" << ".\n";
    else if (compIndex == 15)
        out << ".\nThe Voltage across Component # " << compIndex - 1 << " = " << abs(getVoltage()) << " Volts, \nwith the negative terminal at node " << "11" << ".\n";
    else if (compIndex == 16)
        out << ".\nThe Voltage across Component # " << compIndex - 1 << " = " << abs(getVoltage()) << " Volts, \nwith the negative terminal at node " << "14" << ".\n";
    else if (compIndex == 17)
        out << ".\nThe Voltage across Component # " << compIndex - 1 << " = " << abs(getVoltage()) << " Volts, \nwith the negative terminal at node " << "14" << ".\n";
    else
        out << ".\nThe Voltage across Component # " << compIndex - 1 << " = " << abs(getVoltage()) << " Volts, \nwith the negative terminal at node " << "14" << ".\n";

}
*/