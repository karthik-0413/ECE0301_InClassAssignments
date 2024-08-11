#include "Solhdeccic.h"
#include <iostream>
#include <fstream>
using namespace std;

Solhdeccic::Solhdeccic() : Lhdeccic(2, 0, 0)
{
    a = 3;
    K1 = 1;
    fillSolutionSignal();
}

Solhdeccic::Solhdeccic(double bValue, double initialTimeValue, double initialValue, double a2, double K12) : Lhdeccic(bValue, initialTimeValue, initialValue)
{
    a = a2;
    K1 = K12;
    fillSolutionSignal();
}

void Solhdeccic::setA(double num)
{
    a = num;
}

double Solhdeccic::getA() const
{
    return a;
}

void Solhdeccic::setK1(double num)
{
    K1 = num;
}

double Solhdeccic::getK1() const
{
    return K1;
}

void Solhdeccic::setB(double num)
{
    Lhdeccic::setB(num);
    fillSolutionSignal();
}

void Solhdeccic::setInitialTime(double num)
{
    Lhdeccic::setInitialTime(num);
    fillSolutionSignal();
}

void Solhdeccic::setInitialValue(double num)
{
    Lhdeccic::setInitialValue(num);
    fillSolutionSignal();
}

string Solhdeccic::getExpressionVirtual() const
{
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
    
}

string Solhdeccic::getInitialCondition() const
{
    return getDiffLabel() + "(" + textNum(getInitialTime()) + ") = " + textNum(getInitialValue()) + ", " + getDiffLabel() + "'(" + textNum(getK1()) + ") = " + textNum(getK1());
}     

void Solhdeccic::fillSolutionSignal()
{
    double Root1 = (-a + sqrt(pow(a, 2) - (4*getB()))) / 2;
    double Root2 = (-a - sqrt(pow(a, 2) - (4*getB()))) / 2;
    double TC = std::max(1/Root1, 1/Root2);
    double c1 = (getInitialValue() * Root2 - getK1()) / (Root2 - Root1);
    double c2 = (getInitialValue() * -Root1 + getK1()) / (Root2 - Root1);
    

    Signal* solutionPtr = getSolution();
    solutionPtr->setNumSample(501);
    solutionPtr->setSampleRate(100);
    solutionPtr->setInitialTime(getInitialTime());
    Signal solutionPtr2(solutionPtr->getNumSample(), solutionPtr->getSampleRate(), solutionPtr->getInitialTime());

    solutionPtr->fillExponentialArray(1.0 / -Root1, c1);
    solutionPtr2.fillExponentialArray(1.0 / -Root2, c2);

    *solutionPtr = *solutionPtr + solutionPtr2;
}


void Solhdeccic::outFile(ofstream& out)
{
    out << "---------------------------------" << endl;
    out << "Second-Order Differential Equation" << endl;
    out << "---------------------------------" << endl;
    out << getExpressionVirtual() << endl;
    out << "\nInitial Condition" << endl;
    out << "-----------------" << endl;
    out << getInitialCondition() << "\n" << endl;
}
