#include "Node.h"
#include "Network.h"
#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <cmath>
#include <iomanip>
using namespace std;

//Initializing static variable and it increments everytime the constructor is called
int Network::numNetwork = 0;

//Constructor
Network::Network(int numNodes)
{
    netIndex = numNetwork;
    numNetwork++;
    netNodes = numNodes;
    nodeArr = new Node[netNodes];
}

//Destructor
Network::~Network()
{
    delete [] nodeArr;
}

//Accessor Function to get index
int Network::getNetIndex() const
{
    return netIndex;
}

//Accessor Function to get number of nodes
int Network::getNetNodes() const
{
    return netNodes;
}

//Accessor Function to get number of networks
int Network::getNumNetwork() const
{
    return numNetwork;
}

//Mutator Function to set the voltage at a certain index
void Network::setVoltage(int i, double v)
{
    (*(nodeArr + i)).setVolts(v);   
}

//Member Function to display the details of the circuit
void Network::out2(ofstream& out)
{
    out << "\n------------------------------------------------\n\n";
    out << "Data for Electric Network # " << netIndex << ":\n";
    out << "At present, there are " << numNetwork << " Networks in existence.\n";
    out << "At present, there are " << netNodes << " nodes in existence.\n";
    out << "Network # " << netIndex << " contains " << netNodes << " nodes.\n";

    for (int i = 0; i < netNodes; i++)
    {
        (*(nodeArr + i)).out(out);
    }
}

//Member function that connects the network to the terminal class
void Network::netTerm(Terminal* comp, int Ai, int Bi)
{
    (*comp).setA(&nodeArr[Ai]);
    (*comp).setB(&nodeArr[Bi]);
}