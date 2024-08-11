#include <iostream>
#include <fstream>
#include <string>

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
        void outFile();
};

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
    for (int i = 0; i < numSample; i++)
    {
        *(signalptr + i) = 0;
    }
}

//Mutator function that puts 100 numbers from 0 - 100 going up by 0.01 every iteration in the timeptr pointer
void Signal::fillArray()
{
    //For-Loop to fill the timeptr pointer array with the numbers explained above
    for (int i = 0; i < numSample; i++)
    {
        *(timeptr + i) = initialTime + (i * (1/sampleRate));
    }
}

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
    for (int i = 0; i < numSample; i++)
    {
        out2 << *(getTimePtr() + i) << ", " << *(getSignalPtr() + i) << std::endl;
    }

    //Closing output file
    out2.close();
}

// ***************
// Main Function *
// ***************

int main()
{
    //Creating an instance of the Signal Class
	Signal box;

    //Declaring a string variable to the desired filename
    std::string filename = "time_domain_signal_samples";
	
    //Calling the setOut accessor functoin
    box.setOut(filename);

    //Calling the public member function to display the numbers to the output file
    box.outFile();

    //Exiting the program if it get to this part of the program
    return 0;
}