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

//Class Definition for Network Class with Node has the inheritance class
class Network : public Node
{
    private:
        static int numNetwork;
        int netIndex;
        int netNodes;
        Node* nodeArr;
        int numNodes;
    public:
        Network(int);
        ~Network();
        int getNetIndex() const;
        int getNetNodes() const;
        int getNumNetwork() const;
        void setVoltage(int, double);
        void out2(ofstream&);
        void netTerm(Component*, int, int); 

};

#endif 