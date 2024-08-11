#include "Lhdeccic.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

//Default Constructor
Lhdeccic::Lhdeccic()
{
    b = 1;
    initialTime = 0;
    initialValue = 1;
    diffLabel = "y";
}

//Parameterized Constructor
Lhdeccic::Lhdeccic(double bValue, double initialTimeValue, double initialValueValue)
{
    b = bValue;
    initialTime = initialTimeValue;
    initialValue = initialValueValue;
    diffLabel = "y";
}

//Mutator Function to set B
void Lhdeccic::setB(double num)
{
    b = num;
}

//Mutator Function to set initialTime
void Lhdeccic::setInitialTime(double num)
{
    initialTime = num;
}

//Mutator Function to set initialValue
void Lhdeccic::setInitialValue(double num)
{
    initialValue = num;
}

//Accessor Function to get B 
double Lhdeccic::getB() const
{
    return b;
}

//Accessor Function to get initialTime
double Lhdeccic::getInitialTime() const
{
    return initialTime;
}

//Accessor Function to get initialValue
double Lhdeccic::getInitialValue() const
{
    return initialValue;
}

//Accessor Function to get Signal variable
Signal Lhdeccic::getSolutionSignal() const
{
    return solution;
}

//Accessor Function to get Signal pointer
Signal* Lhdeccic::getSolution()
{
    return &solution;
}

//Mutator Function to set the label of the expression 
void Lhdeccic::setDiffLabel(const string& label)
{
    diffLabel = label;
    solution.setFunction(label);
}

//Accessor Function to get the label of the expression
string Lhdeccic::getDiffLabel() const
{
    return diffLabel;
}

//Member Function given to us by the instructor
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

string Lhdeccic::getSolution() const
{
    // Concatenate the strings to form the equation representation
    return diffLabel + "(t) = " + solution.getExpression();
}

void Lhdeccic::outFile2(ofstream& outFile) const
{
    outFile << "Solution\n--------\n";
    outFile << getSolution() << endl;
    solution.outFile();
}


