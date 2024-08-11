#include "Signal.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

//Constructor of Signal class
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

//Overloaded constructor of signal class
Signal::Signal(unsigned int num, double rate, double time2)
{
    numSample = num;
    sampleRate = rate;
    initialTime = time2;
    signal.resize(numSample, 0);
    time.resize(numSample, 0);
    fillTimeArray();
}

void Signal::setNumSample(unsigned int num)
{
    numSample = num;
    
    time.resize(numSample);
    signal.resize(numSample);

    fillTimeArray();
}

void Signal::setSampleRate(double num)
{
    sampleRate = num;

    fillTimeArray();
}

void Signal::setInitialTime(double num)
{
    initialTime = num;

    fillTimeArray();
}

void Signal::setFunction(const string& label)
{
    function = label;
    filename = "diff_eqn_soln_" + label;
}

void Signal::setExpression(const string& express)
{
    expression = express;
}

unsigned int Signal::getNumSample() const
{
    return numSample;
}

double Signal::getSampleRate() const
{
    return sampleRate;
}

//Accessor Function for initialTime
double Signal::getInitialTime() const
{
    return initialTime;
}

//Accessor Function for function
string Signal::getFunction() const
{
    return function;
}

//Accessor Function for filename
string Signal::getFilename() const
{
    return filename;
}

//Accessor Function for the expression
string Signal::getExpression() const
{
    return expression;
}

//Accessor Function for the signal vector
vector<double> Signal::getSignal() const
{
    return signal;
}

//Accessor Function for the time vector
vector<double> Signal::getTime() const
{
    return time;
}

//Overloaded Accessor Function for the signal vector
double Signal::getSignal2(unsigned int i) const
{
    return signal[i];
}

//Overloaded Accessor Function for the time vector
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

//Function to graph sine graph with the provided equations
void Signal::fillSignalArray(double amp, double freq, double phase)
{
    for (unsigned int i = 0; i < numSample; i++)
    {
        signal[i] = amp * cos((freq * time[i]) + phase);
    }
}

void Signal::fillExponentialArray(double TC, double initial)
{
    for (unsigned int i = 0; i < numSample; i++)
    {
        signal[i] = initial * exp(-(time[i] - initialTime) / TC);
    }

    expression = textNum(initial) + " exp( -";
    if (initialTime == 0)
    {
        expression+="t  ";
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

void Signal::setConstant(double K)
{
    //writes the value of the parameter to all elements of the signal vector
    for (unsigned int i = 0; i < numSample; i++)
    {
        signal[i] = K;
    }

    //sets the mathematical expression to the value of the parameter, converted to a string
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

//Public Member Function that displays the numbers in each of the pointer array to the output file
void Signal::outFile() const
{
    //Declaring a string variable that concatenates the filename given with the .txt extension
    string name = filename + ".txt";

    //Declaring a output file
    ofstream out2;
    out2.open(name);

    //Displaying the number and statements in the matter that is required by us by the instructions
    out2 << "Default Signal:\n";
    out2 << "N: " << numSample << endl;
    out2 << "fs: " << sampleRate << "\n";
    out2 << "t0: " << initialTime << "\n";
    out2 << "Signal label: " << function << endl;
    out2 << "Matehmatical Expression: " << endl;
    out2 << "x(t): " << expression << endl;
    out2 << "Time and signal samples in .csv format" << endl;
    out2 << "t, x(t)\n-------" << endl;

    //For-Loop to displaying both the timeptr and signalptr pointer arrays to the output file
    for (unsigned int i = 0; i < numSample; i++)
    {
        out2 << time[i] << ", " << signal[i] << endl;
    }

    //Closing output file
    out2.close();
}

/*void Signal::MATHGL() const
{
	//Declaring needed variables
	double t_min = -0.05;
	double t_max = 0.15;
	
	// Create mglGraph object
	mglGraph gr;
	
	// MathGL objects from the mglData class for plotting
	mglData x(numSample); //Time
	mglData y(numSample); //Signal
	
	// Copy time and signal samples into mglData objects
    for (unsigned int i = 0; i < numSample; i++)
    {
        x.a[i] = time[i];
        y.a[i] = signal[i];
    }
    
    //Title of graph
    gr.Title("Signal Graph");
    
    // Set axis ranges as (x start, x end, y start, y end)
	gr.SetRanges(t_min, t_max, -3, 3);
	
	// Set the origin of the graph
	gr.SetOrigin(0, 0);
	
	// Create axis
	gr.Axis();
	
	// Put a string at (start point, end point, string value)
	gr.Puts(mglPoint(0,3), mglPoint(0,3), "Time");
	
	gr.Puts(mglPoint(0.15,0), mglPoint(0.15,0), "Signal");
	
	//Plotting the graph
	gr.Plot(x,y);
	
	// Write the plot to eps & png files
	//Creating strings so that I can create filename with the same name as before
	std::string first, second;
	first = expression + ".eps";
	second = expression + ".png";
	
	// Convert the filenames to C-strings
    const char* epsFile = first.c_str();
    const char* pngFile = second.c_str();
	
	gr.WriteEPS(epsFile);
	gr.WritePNG(pngFile);

}*/

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