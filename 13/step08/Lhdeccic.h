#ifndef LHDECCIC_H
#define LHDECCIC_H
#include "Signal.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

//Class Definition of the LHDECCIC Class
class Lhdeccic
{
    private:
        double b;
        double initialTime;
        double initialValue;
        string diffLabel;
        Signal solution;

    public:
        Lhdeccic();
        Lhdeccic(double, double, double);

        virtual void setB(double);
        virtual void setInitialTime(double);
        virtual void setInitialValue(double);
        void setDiffLabel(const string&);

        Signal getSolutionSignal() const;
        Signal* getSolution();

        double getB() const;
        double getInitialTime() const;
        double getInitialValue() const;
        string getDiffLabel() const;
        string textNum(double) const;

        virtual string getExpression2() const = 0;
        virtual void fillSolutionSignal() = 0;
        virtual string getSolution() const;
        void outFile2(ofstream& outFile) const;
};

#endif
