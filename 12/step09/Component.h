#ifndef Component_H
#define Component_H
#include "Node.h"
#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <cmath>
#include <iomanip>
using namespace std;

//Class Definition for Component Class
class Component
{
    private:
        static int numComp;
        int compIndex;
        Node* A;
        Node* B;
    public:
        Component();
        int getCompIndex() const;
        int getNumComp() const;
        void setA(Node*);
        void setB(Node*);
        int getNodeA() const;
        int getNodeB() const;
        void out3(ofstream&) const;
        double getVoltage() const; 
};

#endif