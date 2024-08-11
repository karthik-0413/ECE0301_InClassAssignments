#include "Folhdeccic.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

//Default Constructor
Folhdeccic::Folhdeccic() : Lhdeccic()
{
    fillSolutionSignal();
}

//Paramerterized Constructor
Folhdeccic::Folhdeccic(double bValue, double initialTimeValue, double initialValue) : Lhdeccic(bValue, initialTimeValue, initialValue)
{
    fillSolutionSignal();
}

//Mutator Function to set B via the Base Class
void Folhdeccic::setB(double num)
{
    Lhdeccic::setB(num);
    fillSolutionSignal();
}

//Mutator Function to set initialTime via the Base Class
void Folhdeccic::setInitialTime(double num)
{
    Lhdeccic::setInitialTime(num);
    fillSolutionSignal();
}

//Mutator Function to set initialValue via the Base Class
void Folhdeccic::setInitialValue(double num)
{
    Lhdeccic::setInitialValue(num);
    fillSolutionSignal();
}

//Accessor Function that returns the differential equation given
string Folhdeccic::getExpression2() const
{
    return getDiffLabel() + "'(t) + " + textNum(getB()) + " " + getDiffLabel() + "(t) = 0";
}

//Accessor Function that returns the initial conditions for the equation
string Folhdeccic::getInitialCondition() const
{
    return getDiffLabel() + "(" + textNum(getInitialTime()) + ") = " + textNum(getInitialValue());
}     

//Member Function that fills the signal vector with the desired equation
void Folhdeccic::fillSolutionSignal()
{
    //Define a pointer to an object from the signal class and point it to the solution member function
    Signal* solutionPtr = getSolution();

    //Setting numSample, SampleRate, InitialTime with the description given to us
    solutionPtr->setNumSample(501);
    solutionPtr->setSampleRate(200);
    solutionPtr->setInitialTime(getInitialTime());

    //Filling the signal vector with Equation3
    solutionPtr->fillExponentialArray(1.0 / getB(), getInitialValue());

    //Rounding value in the signal vector
    solutionPtr->roundSignalRound();
}

//Member Function that writes the equation given and the initial condition given to the output file
void Folhdeccic::outFile(ofstream& out)
{
    out << "---------------------------------" << endl;
    out << "First-Order Differential Equation" << endl;
    out << "---------------------------------" << endl;
    out << getExpression2() << endl;
    out << "\nInitial Condition" << endl;
    out << "-----------------" << endl;
    out << getInitialCondition() << "\n" << endl;
}
