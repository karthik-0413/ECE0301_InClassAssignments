#ifndef COMPONENT_H
#define COMPONENT_H
#include "Node.h"
#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <cmath>
#include <iomanip>
using namespace std;

//Class definition for the Terminal Class
class Terminal
{
    private:
        static int numComp;
        int compIndex;
        Node* A;
        Node* B;
    public:
        Terminal();
        int getCompIndex() const;
        int getNumComp();
        void setA(Node*);
        void setB(Node*);
        int getNodeA() const;
        int getNodeB() const;
        void out3(ofstream&) const;
        double getVoltage() const; 
};

#endif