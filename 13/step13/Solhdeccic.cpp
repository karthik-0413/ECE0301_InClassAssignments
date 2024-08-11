#include "Solhdeccic.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

//Default Constructor
Solhdeccic::Solhdeccic() : Lhdeccic(2, 0, 0)
{
    a = 3;
    K1 = 1;
    fillSolutionSignal();
}

//Parameterized Constructor
Solhdeccic::Solhdeccic(double bValue, double initialTimeValue, double initialValue, double a2, double K12) : Lhdeccic(bValue, initialTimeValue, initialValue)
{
    a = a2;
    K1 = K12;
    fillSolutionSignal();
}

//Mutator Function to set the a value
void Solhdeccic::setA(double num)
{
    a = num;
}

//Accessor Function to get the a value
double Solhdeccic::getA() const
{
    return a;
}

//Mutator Function to set the K1 value
void Solhdeccic::setK1(double num)
{
    K1 = num;
}

//Accessor Function to get the K1 value
double Solhdeccic::getK1() const
{
    return K1;
}

//Mutator Function to set B via the Base Class
void Solhdeccic::setB(double num)
{
    Lhdeccic::setB(num);
    fillSolutionSignal();
}

//Mutator Function to set initialTime via the Base Class
void Solhdeccic::setInitialTime(double num)
{
    Lhdeccic::setInitialTime(num);
    fillSolutionSignal();
}

//Mutator Function to set initialValue via the Base Class
void Solhdeccic::setInitialValue(double num)
{
    Lhdeccic::setInitialValue(num);
    fillSolutionSignal();
}

//Accessor Function that returns the differential equation given
string Solhdeccic::getExpression2() const
{
    //If-Else Loop to get the sign of a and b right
    if(getA() > 0 && getB() > 0)
        return getDiffLabel() + "''(t) + " + textNum(fabs(getA())) + " " + getDiffLabel() + "'(t) + " + textNum(fabs(getB())) + " " + getDiffLabel() + "(t) = 0";
    if(getA() > 0 && getB() < 0)
        return getDiffLabel() + "''(t) + " + textNum(fabs(getA())) + " " + getDiffLabel() + "'(t) - " + textNum(fabs(getB())) + " " + getDiffLabel() + "(t) = 0";
    if(getA() < 0 && getB() > 0)
        return getDiffLabel() + "''(t) - " + textNum(fabs(getA())) + " " + getDiffLabel() + "'(t) + " + textNum(fabs(getB())) + " " + getDiffLabel() + "(t) = 0";
    if(getA() < 0 && getB() < 0)
        return getDiffLabel() + "''(t) - " + textNum(fabs(getA())) + " " + getDiffLabel() + "'(t) - " + textNum(fabs(getB())) + " " + getDiffLabel() + "(t) = 0";


    if(getA() == 0 && getB() > 0)
        return getDiffLabel() + "' (t) + " + textNum(fabs(getB())) + " " + getDiffLabel() + "(t) = 0";
    if(getA() == 0 && getB() < 0)
        return getDiffLabel() + "' (t) - " + textNum(fabs(getB())) + " " + getDiffLabel() + "(t) = 0";
    if(getA() > 0 && getB() == 0)
        return getDiffLabel() + "'' (t) + " + textNum(fabs(getA())) + " " + getDiffLabel() + "(t) = 0";
    if(getA() < 0 && getB() == 0)
        return getDiffLabel() + "'' (t) - " + textNum(fabs(getA())) + " " + getDiffLabel() + "(t) = 0";


    if(getA() == 0 && getB() == 0)
        return getDiffLabel() + "''(t)";
    
    else
        return "0";
    
}

//Accessor Function that returns the initial conditions for the equation
string Solhdeccic::getInitialCondition() const
{
    return getDiffLabel() + "(" + textNum(getInitialTime()) + ") = " + textNum(getInitialValue()) + ", " + getDiffLabel() + "'(" + textNum(getInitialTime()) + ") = " + textNum(getK1());
}     

//Member Function that fills the signal vector with the desired equation
void Solhdeccic::fillSolutionSignal()
{
    //Declaring variables as directed by the instructions for the overdamped case
    double Root1 = (-a + sqrt(pow(a, 2) - (4*getB()))) / 2;
    double Root2 = (-a - sqrt(pow(a, 2) - (4*getB()))) / 2;
    double TC = std::max(1/Root1, 1/Root2);
    double c1 = (getInitialValue() * Root2 - getK1()) / (Root2 - Root1);
    double c2 = (getInitialValue() * -Root1 + getK1()) / (Root2 - Root1);
    
    //Define a pointer to an object from the signal class and point it to the solution member function
    Signal* solutionPtr = getSolution();

    //Setting numSample, SampleRate, InitialTime with the description given to us
    solutionPtr->setNumSample(501);
    solutionPtr->setSampleRate(100);
    solutionPtr->setInitialTime(getInitialTime());

    //Making another Signal variable and make it have the same amount of each value
    Signal solutionPtr2;
    solutionPtr2.setNumSample(501);
    solutionPtr2.setSampleRate(100);
    solutionPtr2.setInitialTime(getInitialTime());

    //Filling the signal vector with the given equation
    solutionPtr->fillExponentialArray(1.0 / -Root1, c1);
    solutionPtr2.fillExponentialArray(1.0 / -Root2, c2);

    //Adding the two signals up and rounding their signal values
    *solutionPtr = *solutionPtr + solutionPtr2;
    solutionPtr->roundSignalRound();
}

//Member Function that writes the equation given and the initial condition given to the output file
void Solhdeccic::outFile(ofstream& out)
{
    out << "----------------------------------" << endl;
    out << "Second-Order Differential Equation" << endl;
    out << "----------------------------------" << endl;
    out << getExpression2() << endl;
    out << "\nInitial Condition" << endl;
    out << "-----------------" << endl;
    out << getInitialCondition() << "\n" << endl;
}
