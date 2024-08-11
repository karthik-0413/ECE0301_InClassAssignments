/*#include "Node.h"
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
Network::Network(int num)
{
    numNodes = num;
    getNumNodes();
    netNodes = numNodes;
    netIndex = numNetwork;
    nodeArr = new Node[netNodes];
    numNetwork++;
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
    out << "Data for Electric Network # " << getNumNetwork()-1 << ":\n";
    out << "At present, there are " << getNumNetwork() << " Networks in existence.\n";
    out << "At present, there are " << getNetNodes() << " nodes in existence.\n";
    out << "Network # " << getNetIndex() << " contains " << getNetNodes() << " nodes.\n";

    for (int i = 0; i < netNodes; i++)
    {
        (*(nodeArr + i)).out(out);
    }
}

//Member function that connects the network to the terminal class
void Network::netTerm(Component* comp, int Ai, int Bi)
{
    (*comp).setA(nodeArr + Ai);
    (*comp).setB(nodeArr + Bi);
}

*/