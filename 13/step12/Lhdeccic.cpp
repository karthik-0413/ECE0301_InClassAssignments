#include "Lhdeccic.h"
#include "Signal.cpp"
#include <iostream>
using namespace std;

Lhdeccic::Lhdeccic()
{
    b = 1;
    initialTime = 0;
    initialValue = 1;
    diffLabel = "y";
}

Lhdeccic::Lhdeccic(double bValue, double initialTimeValue, double initialValueValue)
{
    b = bValue;
    initialTime = initialTimeValue;
    initialValue = initialValueValue;
    diffLabel = "y";
}

void Lhdeccic::setB(double num)
{
    b = num;
}

void Lhdeccic::setInitialTime(double num)
{
    initialTime = num;
}

void Lhdeccic::setInitialValue(double num)
{
    initialValue = num;
}

double Lhdeccic::getB() const
{
    return b;
}

double Lhdeccic::getInitialTime() const
{
    return initialTime;
}

double Lhdeccic::getInitialValue() const
{
    return initialValue;
}

Signal Lhdeccic::getSolutionSignal() const
{
    return solution;
}

Signal* Lhdeccic::getSolution()
{
    return &solution;
}

void Lhdeccic::setDiffLabel(const string& label)
{
    diffLabel = label;
    solution.setFunction(label);
}

string Lhdeccic::getDiffLabel() const
{
    return diffLabel;
}

string Lhdeccic::textNum(double x) const
{
    if (x >= 100)
    {
        // Large numbers truncated as int -> string
        return std::to_string(static_cast<int>(x));
    }
    else
    {
        // Small numbers will get 3 digits
        std::string x_exp = std::to_string(x);
        // Return 4 characters, or 5 if x<0
        return x_exp.substr(0, 4 + (x < 0));
    }
}

string Lhdeccic::getSolutionEquation() const
{
    // Concatenate the strings to form the equation representation
    return diffLabel + "(t) = " + solution.getExpression();
}

void Lhdeccic::writeSolutionToFile(ofstream& outFile) const
{
    outFile << "Solution\n--------\n";
    outFile << getSolutionEquation() << endl << endl;
    solution.outFile();
}


