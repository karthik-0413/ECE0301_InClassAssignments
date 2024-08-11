#ifndef DCVOLTAGESOURCE_H
#define DCVOLTAGESOURCE_H
#include "Component.h"
#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <cmath>
#include <iomanip>
using namespace std;

//Class Definition for DCVoltageSource Class with Component Class has inheritance
class DCVoltageSource : public Component
{
private:
    double Vs;
    double current;
public:
    DCVoltageSource(); 
    void setVS(double);
    double getVS() const;
    void setCurrent(double);
    double getCurrent() const;
    double getPower() const;
    void out4(ofstream&);
};

#endif