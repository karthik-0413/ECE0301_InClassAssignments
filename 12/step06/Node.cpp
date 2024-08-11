#include "Node.h"
#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <cmath>
#include <iomanip>
using namespace std;

//Initializing static variable and it increments everytime the constructor is called
int Node::numNodes2 = 0; 

// Constructor
Node::Node()
{
    index = numNodes2;  
    volts = 0;
    numNodes2++;   
}

// Accessor function to get the node index
int Node::getIndex() const
{
    return index;
}

// Accessor function to get the number of nodes
int Node::getNumNodes()
{
    return numNodes2;
}

//Mutator Function to get the voltage
void Node::setVolts(double volt)
{
    volts = volt;
}

//Accessor function to get voltage
double Node::getVolts() const
{
    return volts;
}

//Member function to display the voltage and the corresponding index
void Node::out(ofstream& out)
{
    out << "Voltage at node " << getIndex()-1 << " = " << getVolts() << ".\n";
}