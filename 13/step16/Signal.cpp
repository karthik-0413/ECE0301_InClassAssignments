#include "Signal.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

//Default Constructor
Signal::Signal()
{
    numSample = 101;
	sampleRate = 100;
	initialTime = 0;
    setFunction("x");
    setExpression("0");
    signal.resize(numSample, 0);
    time.resize(numSample, 0);
    fillTimeArray();
}

//Parameterized Constructor
Signal::Signal(unsigned int num, double rate, double time2)
{
    numSample = num;
    sampleRate = rate;
    initialTime = time2;
    signal.resize(numSample, 0);
    time.resize(numSample, 0);
    fillTimeArray();
}

//Mutator Function to set NumSample
void Signal::setNumSample(unsigned int num)
{
    numSample = num;
    
    time.resize(numSample);
    signal.resize(numSample);

    fillTimeArray();
}

//Mutator Function to set SampleRate
void Signal::setSampleRate(double num)
{
    sampleRate = num;

    fillTimeArray();
}

//Mutator Function to set InitialTime
void Signal::setInitialTime(double num)
{
    initialTime = num;

    fillTimeArray();
}

//Mutator Function to set Function
void Signal::setFunction(const string& label)
{
    function = label;
    filename = "diff_eqn_soln_" + label;
}

//Mutator Function to set Expression
void Signal::setExpression(const string& express)
{
    expression = express;
}

//Accessor Function to get NumSample
unsigned int Signal::getNumSample() const
{
    return numSample;
}

//Accessor Function to get SampleRate
double Signal::getSampleRate() const
{
    return sampleRate;
}

//Accessor Function to get initialTime
double Signal::getInitialTime() const
{
    return initialTime;
}

//Accessor Function to get function
string Signal::getFunction() const
{
    return function;
}

//Accessor Function to get filename
string Signal::getFilename() const
{
    return filename;
}

//Accessor Function to get the expression
string Signal::getExpression() const
{
    return expression;
}

//Accessor Function to get the signal vector
vector<double> Signal::getSignal() const
{
    return signal;
}

//Accessor Function to get the time vector
vector<double> Signal::getTime() const
{
    return time;
}

//Overloaded Accessor Function to get the signal vector
double Signal::getSignal2(unsigned int i) const
{
    return signal[i];
}

//Overloaded Accessor Function to get the time vector
double Signal::getTime2(unsigned int i) const
{
    return time[i];
}

//Mutator function that puts 100 numbers from 0 - 100 going up by the sample rate every iteration in the timeptr pointer
void Signal::fillTimeArray()
{
    //For-Loop to fill the timeptr pointer array with the numbers explained above
    for (unsigned int i = 0; i < numSample; i++)
    {
        time[i] = initialTime + (i/sampleRate);
    }
}

//Function to graph sine graph
void Signal::fillSignalArray(double amp, double freq, double phase)
{
    for (unsigned int i = 0; i < numSample; i++)
    {
        signal[i] = amp * cos((freq * time[i]) + phase);
    }
}

//Member Function to graph exponential graph
void Signal::fillExponentialArray(double TC, double initial)
{
    for (unsigned int i = 0; i < numSample; i++)
    {
        signal[i] = initial * exp(-(time[i] - initialTime) / TC);
    }

    //If-else loop to determine sign of the expression
    expression = textNum(initial) + " exp( -";
    if (initialTime == 0)
    {
        expression+="t ";
    }
    else if (initialTime<0)
    {
        expression += "(t + " + textNum(fabs(initialTime)) + ") ";
    }
    else
    {
        expression += "(t - " + textNum(fabs(initialTime)) + ") ";
    }
    
    if (TC == 1)
    {
        expression += ")";
    }
    else
    {
        expression += "/ " + textNum(TC) + " )";
    }
}

void Signal::fillCritDamp(double slope, double time2, double b)
{
    for (unsigned int i = 0; i < numSample; i++)
    {
        signal[i] = slope * (time[i] - time2) + b;
    }

    //If-else loop to determine sign of the expression
    if (slope > 0 && time2 > 0 && b > 0)
    {
        expression = textNum(slope) + " (t + " + textNum(fabs(time2)) + ") + " + textNum(fabs(b));
    }

    if (slope > 0 && time2 > 0 && b < 0)
    {
        expression = textNum(slope) + " (t + " + textNum(fabs(time2)) + ") - " + textNum(fabs(b));
    }
    else
    {
        expression = textNum(slope) + " (t + " + textNum(fabs(time2)) + ") - " + textNum(fabs(b));
    }

    if (time2 == 0)
        expression = textNum(slope) + " t - " + textNum(fabs(b));
}

//Copy and Pasted the given function by the instructor
string Signal::textNum(double x) const
{
    if (x >= 100)
    {
        // large numbers truncated as int -> string

        return std::to_string(int(x));
    }
    else
    {
        // small numbers will get 3 digits
        string x_exp = std::to_string(x);

        // return 4 characters, or 5 if x<0
        return x_exp.substr(0, 4 + (x<0));
    }
}

//Member Function that sets the signal vector to all one number
void Signal::setConstant(double K)
{
    //writes the value of the parameter to all elements of the signal vector
    for (unsigned int i = 0; i < numSample; i++)
    {
        signal[i] = K;
    }

    //Sets the mathematical expression to the constant value
    setExpression(textNum(K));
}

//Rounding all of the value in the signal vector
void Signal::roundSignalRound()
{
    for (unsigned int i = 0; i < numSample; i++)
    {
        signal[i] = round(signal[i]);
    }
}

//Member Function that displays the numbers in each of the pointer array to the output file
void Signal::outFile() const
{
    //Declaring a string variable that concatenates the filename given with .txt
    string name = filename + ".txt";

    //Declaring a output file
    ofstream out2;
    out2.open(name);

    //Displaying the number and statements in the matter that is required by us by the instructions
    out2 << "Time-Domain Signal Samples\n";
    out2 << "N = " << numSample << endl;
    out2 << "fs = " << sampleRate << "\n";
    out2 << "t0 = " << initialTime << "\n";
    out2 << "Signal label: " << function << endl;
    out2 << "Mathematical expression" << endl;
    out2 << getFunction() + "(t) = " << expression << endl;
    out2 << "Time and signal samples in .csv format" << endl;
    out2 << "t, " + getFunction() + "(t)\n-------" << endl;

    //For-Loop to displaying both the timeptr and signalptr pointer arrays to the output file
    for (unsigned int i = 0; i < numSample; i++)
    {
        out2 << time[i] << ", " << signal[i] << endl;
    }

    //Closing output file
    out2.close();
}

//Equals operator function
const Signal Signal::operator=(const Signal& computer)
{
    // Checking for self-reference
    if (this != &computer)
    {
        // Copying variables over to reference variable
        numSample = computer.numSample;
        sampleRate = computer.sampleRate;
        initialTime = computer.initialTime;
        expression = computer.expression;
        signal = computer.signal;
        time = computer.time;
    }
    return *this;
}

//Overload the + operator by writing an operator function for the class
const Signal Signal::operator+(const Signal& computer)
{
    //If the input signal and calling signal have the same number of samples, sampling frequency and initial time
	if(numSample == computer.numSample && sampleRate == computer.sampleRate && initialTime == computer.initialTime)
	{
		//Creating an object from the singal class
		Signal final3(numSample, sampleRate, initialTime);
        
        //Form the mathematical expression string for the returned signal, by concatenating the expressions for the calling 
        //signal and the input signal, with “ + ” inserted between them
        final3.setExpression("(" + expression + ") + (" + computer.expression + ")");
		
        //the signal vector that is returned must be the sum of the input signal vector and the calling signal vector
		for (unsigned int i = 0; i < numSample; i++)
		{
			final3.signal[i] = signal[i] + computer.signal[i];
		}

        //returns an object from the signal class
		return final3;
		
	}
	else
	{
        //Displaying an error message if the two signals cannot be added together with and exiting with a failure code
		cout << "ERROR! Attempt to add incompatible signals" << endl;
		exit(EXIT_FAILURE);

	}	
}

//SAME AS THE ADDING OPERATOR BUT INTSEAD OF ADDING IN THE FOR-LOOP, I MULTIPLED THE TWO ARRAYS TOGETHER
const Signal Signal::operator*(const Signal& computer)
{
    if (numSample == computer.numSample && sampleRate == computer.sampleRate && initialTime == computer.initialTime)
    {
        Signal final4(numSample, sampleRate, initialTime);
        
        final4.setExpression("(" + expression + ")(" + computer.expression + ")");
        
        for (unsigned int i = 0; i < numSample; i++)
        {
            //Multiplying the two arrays together
            final4.signal[i] = signal[i] * computer.signal[i];
        }
        return final4;
    }
    else
    {
        //Displaying an error message if the two signals cannot be added together with and exiting with a failure code
        cout << "ERROR! Attempt to multiply incompatible signals" << endl;
        exit(EXIT_FAILURE);
    }
}