#ifndef SIGNAL_H
#define SIGNAL_H
#include <iostream>

//Signal Class Declaration
class Signal
{
	private:
        unsigned int numSample;
        double sampleRate;
        double initialTime;
        double* signalptr;
        double* timeptr;
        std::string out;
	public:
        Signal();
        Signal(unsigned int, double, double);
        ~Signal();
        void setNumSample(unsigned int);
        void setSampleRate(double);
        void setInitialTime(double);
        unsigned int getNumSample() const;
        double getSampleRate() const;
        double getInitialTime() const;
        double* getSignalPtr() const;
        double* getTimePtr() const;
        void setOut(std::string&);
        void zeroArray();
        void fillArray();
        void graph(double, double, double);
        void round();
        void MATHGL();
        void outFile();
};

#endif