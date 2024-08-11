#ifndef SIGNAL_H
#define SIGNAL_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

//Signal Class Declaration
class Signal
{
    private:
       unsigned int numSample;
       double sampleRate;
       double initialTime;
       string function;
       string filename;
       string expression;
       vector<double> signal;
       vector<double> time;
    public:
        Signal();
        Signal(unsigned int, double, double, const string&, const string&);
        void setNumSample(unsigned int);
        void setSampleRate(double);
        void setInitialTime(double);
        void setFunction(const string&);
        void setExpression(const string&);
        unsigned int getNumSample() const;
        double getSampleRate() const;
        double getInitialTime() const;
        void graph(double, double, double);
        string getFunction() const;
        string getFilename() const;
        string getExpression() const;
        vector<double> getSignal() const;
        vector<double> getTime() const;
        double getSignal2(unsigned int);
        double getTime2(unsigned int);
        void fillArray();
        string textNum(double) const;
        void setConstant(double);
        const Signal operator=(const Signal&);
        const Signal operator+(const Signal&);
        const Signal operator*(const Signal&);
        void round2();
        void outFile();
};

#endif