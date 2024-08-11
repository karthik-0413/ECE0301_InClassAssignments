/*#ifndef Component_H
#define Component_H
#include <iostream>
//#include "Network.h"
#include "Node.h"
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
        double getVoltage() const;
        void out3(ofstream&) const;
};

#endif 
*/