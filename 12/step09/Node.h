#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <cmath>
#include <iomanip>
using namespace std;

//Class Definition for Node Class
class Node
{
    private:
        static int numNodes2;
        int index;       
        double volts;

    public:
        Node();       
        int getIndex() const;  
        int getNumNodes() const;  
        void setVolts(double volt);
        double getVolts() const;
        void out(ofstream&);
};

#endif 