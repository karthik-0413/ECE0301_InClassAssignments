#ifndef NETWORK_H
#define NETWORK_H
#include "Node.h"
#include "Component.h"
#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <cmath>
#include <iomanip>
using namespace std;

//Class definition for Network class with Node class being the inheritance class
class Network : public Node
{
    private:
        static int numNetwork;
        int netIndex;
        int netNodes;
        Node* nodeArr;
    public:
        Network(int numNodes = 2);
        ~Network();
        int getNetIndex() const;
        int getNetNodes() const;
        int getNumNetwork() const;
        void setVoltage(int, double);
        void out2(ofstream&);
        void netTerm(Terminal*, int, int); 

};

#endif 