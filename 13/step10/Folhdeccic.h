#ifndef FOLHDECCIC_H
#define FOLHDECCIC_H

#include "Lhdeccic.h"
#include "Signal.h"
#include <iostream>
using namespace std;

class Folhdeccic : public Lhdeccic
{
    public:
        Folhdeccic();
        Folhdeccic(double bValue, double initialTimeValue, double initialValueValue);

        virtual void setB(double);
        virtual void setInitialTime(double);
        virtual void setInitialValue(double);

        virtual string getExpressionVirtual() const;
        virtual string getInitialCondition() const;
        virtual void outFile(ofstream&);
        virtual void fillSolutionSignal();
};

#endif
