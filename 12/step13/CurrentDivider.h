#ifndef CURRENTDIVIDER_H
#define CURRENTDIVIDER_H
/*
#include "DCCurrentSource.h"
#include "Network.h"
#include "Resistor.h"
#include "Component.h"
*/
#include <iostream>
#include <fstream>
using namespace std;

//Class Definition for CirrentDivider Class
class CurrentDivider
{
    /*private:
        DCCurrentSource VS;
        Resistor OHM, OHM2;
    public:
        CurrentDivider();
        CurrentDivider(double, double, double);
        void setIS(double);
        void setResis(double, double);
        void Calculations2();*/
    public:
        void out8(ofstream&);
};


#endif
