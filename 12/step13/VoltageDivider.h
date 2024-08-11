
#ifndef VOLTAGEDIVIDER_H
#define VOLTAGEDIVIDER_H
/*
#include "Network.h"
#include "Resistor.h"
#include "Component.h"
#include "DCVoltageSource.h"
*/
#include <iostream>
#include <fstream>
using namespace std;

//Class Definition for VoltageDivider Class
class VoltageDivider
{
    /*private:
        DCVoltageSource VS;
        Resistor OHM;
        Resistor OHM2;
    public:
        VoltageDivider();
        void setVoS(double);
        void setResis(double, double);*/
        //VoltageDivider(double, double, double);
        //void Calculations();
    public:
        void out6(ofstream&);

};

#endif
