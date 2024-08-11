#ifndef RESISTOR_H
#define RESISTOR_H
#include "Component.h"
#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <cmath>
#include <iomanip>
using namespace std;

//Class Definition for the Resistor Class with Component Class has inheritance
class Resistor : public Component
{
private:
    double resistance; 
public:
    Resistor();
    void setResistance(double);
    double getResistance() const;
    double getCurrent() const; 
    double getPower() const;
    void out5(std::ofstream&);
};

#endif