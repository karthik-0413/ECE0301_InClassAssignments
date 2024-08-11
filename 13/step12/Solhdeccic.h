#ifndef Solhdeccic_H
#define Solhdeccic_H

#include "Lhdeccic.h"
#include "Signal.h"
#include <iostream>
using namespace std;

class Solhdeccic : public Lhdeccic
{
    private:
        double a;
        double K1;
    public:
        Solhdeccic();
        Solhdeccic(double bValue, double initialTimeValue, double initialValueValue, double, double);

        virtual void setB(double);
        void setA(double);
        double getA() const;
        void setK1(double);
        double getK1() const;
        virtual void setInitialTime(double);
        virtual void setInitialValue(double);

        virtual string getExpressionVirtual() const;
        virtual string getInitialCondition() const;
        virtual void outFile(ofstream&);
        virtual void fillSolutionSignal();
};

#endif
