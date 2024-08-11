#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <iomanip>

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
        *(timeptr + i) = initialTime + (i * (1.0/sampleRate));
    }
}

//Function to graph sine graph with the provided equations
void Signal::graph(double amp, double freq, double phase)
{
    for (int i = 0; i < numSample; i++)
    {
        *(signalptr + i) = (amp * cos(((2 * M_PI * freq * (*(timeptr + i))) + phase)));
    }
}

//Rounding the signal pointer array to be intergers between -3 and 3
void Signal::round()
{
    for (int i = 0; i < numSample; i++)
    {
        *(signalptr + i) = std::round((*(signalptr + i)));
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
        out2 << *(timeptr + i) << ", " << std::fixed << std::setprecision(3) << *(signalptr + i) << std::endl;
    }

    //Closing output file
    out2.close();
}

//Function outside of Signal class to get the specification of the sine graph from the input file
unsigned int FileNumbers(std::string& filename, double& sampleRate, double& initialTime, double& amp, double& freq, double& phase)
{
    //Getting the number of samples with ERROR checking
    unsigned int samples;

    std::ifstream in;
    in.open(filename);

    std::string first, first2, samp;
    std::getline(in, first);

    first2 = first.substr(0,19);

    //ERROR-CHECKING the first line of the input file
    if (first2 != "Number of samples: ")
    {
        std::cout << "ERROR! Invalid input file header." << std::endl;
        exit(EXIT_FAILURE);
    }

    samp = first.substr(19,24);

    //Using stod to turn a string into a double
    samples = std::stod(samp);
//***************//***************//***************//***************//***************//***************//***************

     //Getting the sample rate with ERROR checking

    std::string second, second2, rate;  
    
    std::getline(in, second);

    second2 = second.substr(0,20);

    //ERROR-CHECKING the first line of the input file
    if (second2 != "Sampling frequency: ")
    {
        std::cout << "ERROR! Invalid input file header." << std::endl;
        exit(EXIT_FAILURE);
    }

    rate = second.substr(20,27);

    //Using stod to turn a string into a double
    sampleRate = std::stod(rate);
//***************//***************//***************//***************//***************//***************//***************

    //Getting the initial time with ERROR checking

    std::string third, third2, time;  
    
    std::getline(in, third);

    third2 = third.substr(0,14);

    //ERROR-CHECKING the first line of the input file
    if (third2 != "Initial time: ")
    {
        std::cout << "ERROR! Invalid input file header." << std::endl;
        exit(EXIT_FAILURE);
    }

    time = third.substr(14,19);

    //Using stod to turn a string into a double
    initialTime = std::stod(time);
//***************//***************//***************//***************//***************//***************//***************

    //Getting the amplitude with ERROR checking

    std::string four, four2, amp2;  
    
    std::getline(in, four);

    four2 = four.substr(0,11);

    //ERROR-CHECKING the first line of the input file
    if (four2 != "Amplitude: ")
    {
        std::cout << "ERROR! Invalid input file header." << std::endl;
        exit(EXIT_FAILURE);
    }

    amp2 = four.substr(11,16);

    //Using stod to turn a string into a double
    amp = std::stod(amp2);   
//***************//***************//***************//***************//***************//***************//***************

    //Getting the frequency with ERROR checking

    std::string five, five2, freq2;  
    
    std::getline(in, five);

    five2 = five.substr(0,11);

    //ERROR-CHECKING the first line of the input file
    if (five2 != "Frequency: ")
    {
        std::cout << "ERROR! Invalid input file header." << std::endl;
        exit(EXIT_FAILURE);
    }

    freq2 = five.substr(11,16);

    //Using stod to turn a string into a double
    freq = std::stod(freq2);
//***************//***************//***************//***************//***************//***************//***************

    //Getting the phase with ERROR checking

    std::string six, six2, phase2;  
    
    std::getline(in, six);

    six2 = six.substr(0,7);

    //ERROR-CHECKING the first line of the input file
    if (six2 != "Phase: ")
    {
        std::cout << "ERROR! Invalid input file header." << std::endl;
        exit(EXIT_FAILURE);
    }

    phase2 = six.substr(7,13);

    //Using stod to turn a string into a double
    phase = std::stod(phase2);

    return samples;
}

// ***************
// Main Function *
// ***************

int main()
{
    //Declaring needed variables
    unsigned int numSample;
    double sampleRate, initialTime, amp, freq, phase;

    //Declaring a string variable to the desired filenames
    std::string filename = "time_domain_signal_samples";
    std::string filename2 = "sine_wave_specification.txt";

    //Declaring a input file variable
    std::ifstream in;
    in.open("sine_wave_specification.txt");

    //Calling the function that inputs all of the sine graph specifications
    numSample = FileNumbers(filename2, sampleRate, initialTime, amp, freq, phase);

    //Creating an instance of the overloaded constructor with the inputted values
    Signal box2(numSample, sampleRate, initialTime);

    //Calling the graph member function to obtain the values of the signalptr pointer array
    box2.graph(amp, freq, phase);

    //Calling the rounding member function to round the values in the signalptr pointer array
    box2.round();

    //Calling the setOut accessor function
    box2.setOut(filename);

    //Calling the public member function to display the numbers to the output file
    box2.outFile();

    //Exiting the program if it get to this part of the program
    return 0;
}