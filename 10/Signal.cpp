#include "Signal.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <iomanip>
//#include <mgl2/mgl.h>

//Default Constructor of Signal Class that assigns values to variables
Signal::Signal()
{
	numSample = 101;
	sampleRate = 100;
	initialTime = 0;
    signalptr = new double[numSample];
    zeroArray();
    timeptr = new double[numSample];
    fillArray();
    out = "tdsig";
}

//Overloading Constructor 
Signal::Signal(unsigned int samp, double rate, double time2)
{
    numSample = samp;
    sampleRate = rate;
    initialTime = time2;
    signalptr = new double[numSample];
    zeroArray();
    timeptr = new double[numSample];
    fillArray();
    out = "tdsig";
}

//Destructor of Signal Class to delete memory of allocated arrays
Signal::~Signal()
{
    delete signalptr;
    delete timeptr;
}

//Mutator Function for numSample
void Signal::setNumSample(unsigned int num)
{
	numSample = num;
}

//Mutator Function for sampleRate
void Signal::setSampleRate(double rate)
{
	sampleRate = rate;
}

//Mutator Function for initialTime
void Signal::setInitialTime(double time)
{
	initialTime = time;
}

//Accessor Function for numSample
unsigned int Signal::getNumSample() const
{
    return numSample;
}

//Accessor Function for sampleRate
double Signal::getSampleRate() const
{
    return sampleRate;
}

//Accessor Function for initialTime
double Signal::getInitialTime() const
{
    return initialTime;
}

//Accessor Function for signalPtr
double* Signal::getSignalPtr() const
{
    return signalptr;
}

//Accessor Function for timePtr
double* Signal::getTimePtr() const
{
    return timeptr;
}

//Mutator Function for setOut to get filename
void Signal::setOut(std::string& file)
{
    out = file;
}

//Mutator function that puts zeroes in the signalptr pointer
void Signal::zeroArray()
{
    //For-Loop to fill the signalptr pointer array with all zero values
    for (unsigned int i = 0; i < numSample; i++)
    {
        *(signalptr + i) = 0;
    }
}

//Mutator function that puts 100 numbers from 0 - 100 going up by 0.01 every iteration in the timeptr pointer
void Signal::fillArray()
{
    //For-Loop to fill the timeptr pointer array with the numbers explained above
    for (unsigned int i = 0; i < numSample; i++)
    {
        *(timeptr + i) = initialTime + (i * (1.0/sampleRate));
    }
}

//Function to graph sine graph with the provided equations
void Signal::graph(double amp, double freq, double phase)
{
    for (unsigned int i = 0; i < numSample; i++)
    {
        *(signalptr + i) = (amp * cos(((2 * M_PI * freq * (*(timeptr + i))) + phase)));
    }
}

//Rounding the signal pointer array to be intergers between -3 and 3
void Signal::round()
{
    for (unsigned int i = 0; i < numSample; i++)
    {
        *(signalptr + i) = std::round((*(signalptr + i)));
    }
}


/*void Signal::MATHGL()
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
        x.a[i] = *(timeptr + i);
        y.a[i] = *(signalptr + i);
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
	first = out + ".eps";
	second = out + ".png";
	
	// Convert the filenames to C-strings
    const char* epsFile = first.c_str();
    const char* pngFile = second.c_str();
	
	gr.WriteEPS(epsFile);
	gr.WritePNG(pngFile);

}*/

//Public Member Function that displays the numbers in each of the pointer array to the output file
void Signal::outFile()
{
    //Declaring a string variable that concatenates the filename given with the .txt extension
    std::string name = out + ".txt";

    //Declaring a output file
    std::ofstream out2;
    out2.open(name);

    //Displaying the number and statements in the matter that is required by us by the instructions
    out2 << "ECE 0301: Time-Domain Signal Samples" << std::endl;
    out2 << "The number of samples is " << numSample << std::endl;
    out2 << "The sample rate is " << sampleRate << std::endl;
    out2 << "The initial time is " << initialTime <<  std::endl;
    out2 << "Here is your signal: " << std::endl;
    out2 << "t, s(t)" << std::endl;

    //For-Loop to displaying both the timeptr and signalptr pointer arrays to the output file
    for (unsigned int i = 0; i < numSample; i++)
    {
        out2 << *(timeptr + i) << ", " << std::fixed << std::setprecision(3) << *(signalptr + i) << std::endl;
    }

    //Closing output file
    out2.close();
}