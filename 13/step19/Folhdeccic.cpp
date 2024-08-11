#include "Folhdeccic.h"
#include <iostream>
#include <fstream>
using namespace std;

Folhdeccic::Folhdeccic() : Lhdeccic()
{
    fillSolutionSignal();
}

Folhdeccic::Folhdeccic(double bValue, double initialTimeValue, double initialValue) : Lhdeccic(bValue, initialTimeValue, initialValue)
{
    fillSolutionSignal();
}

void Folhdeccic::setB(double num)
{
    Lhdeccic::setB(num);
    fillSolutionSignal();
}

void Folhdeccic::setInitialTime(double num)
{
    Lhdeccic::setInitialTime(num);
    fillSolutionSignal();
}

void Folhdeccic::setInitialValue(double num)
{
    Lhdeccic::setInitialValue(num);
    fillSolutionSignal();
}

string Folhdeccic::getExpressionVirtual() const
{
    return getDiffLabel() + "'(t) + " + textNum(getB()) + " " + getDiffLabel() + "(t) = 0";
}

string Folhdeccic::getInitialCondition() const
{
    return getDiffLabel() + "(" + textNum(getInitialTime()) + ") = " + textNum(getInitialValue());
}     

void Folhdeccic::fillSolutionSignal()
{
    Signal* solutionPtr = getSolution();
    solutionPtr->setNumSample(501);
    solutionPtr->setSampleRate(200);
    solutionPtr->setInitialTime(getInitialTime());
    solutionPtr->fillExponentialArray(1.0 / getB(), getInitialValue());
    solutionPtr->roundSignalRound();
}


void Folhdeccic::outFile(ofstream& out)
{
    out << "---------------------------------" << endl;
    out << "First-Order Differential Equation" << endl;
    out << "---------------------------------" << endl;
    out << getExpressionVirtual() << endl;
    out << "\nInitial Condition" << endl;
    out << "-----------------" << endl;
    out << getInitialCondition() << "\n" << endl;
}
