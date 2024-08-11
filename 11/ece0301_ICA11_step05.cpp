
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
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
        string getFunction() const;
        string getFilename() const;
        string getExpression() const;
        vector<double> getSignal() const;
        vector<double> getTime() const;
        double getSignal2(unsigned int);
        double getTime2(unsigned int);
        void fillArray();
        void outFile();
};

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
    fillArray();
}

//Overloaded constructor of signal class
Signal::Signal(unsigned int num, double rate, double time2, const string& file, const string& expr)
{
    numSample = num;
    sampleRate = rate;
    initialTime = time2;
    setFunction(file);
    setExpression(expr);
    signal.resize(numSample, 0);
    time.resize(numSample, 0);
    fillArray();
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

//Mutator Function for the label
void Signal::setFunction(const string& label)
{
    function = label;
    filename = "signal_" + label;
}

//Mutator Function for the expression
void Signal::setExpression(const string& express)
{
    expression = express;
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
double Signal::getSignal2(unsigned int i)
{
    return signal[i];
}

//Overloaded Accessor Function for the time vector
double Signal::getTime2(unsigned int i)
{
    return time[i];
}

//Mutator function that puts 100 numbers from 0 - 100 going up by the sampleRate every iteration in the timeptr pointer
void Signal::fillArray()
{
    //For-Loop to fill the timeptr pointer array with the numbers explained above
    for (unsigned int i = 0; i < numSample; i++)
    {
        time[i] = initialTime + ((i/sampleRate));
    }
}

//Public Member Function that displays the numbers in each of the pointer array to the output file
void Signal::outFile()
{
    //Declaring a string variable that concatenates the filename given with the .txt extension
    std::string name = filename + ".txt";

    //Declaring a output file
    std::ofstream out2;
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
    for (int i = 0; i < numSample; i++)
    {
        out2 << time[i] << ", " << signal[i] << endl;
    }

    //Closing output file
    out2.close();
}

//Main Function
int main()
{
    //Creating an instance of the constructos without any parameters
    Signal x;
    
    //Calls the member function to write signal information to a text file
    x.outFile();

    //Defines a second signal with 401 samples, 10^4 samples/sec, t0 = -0.01 sec
    //Also, changes the label for the second signal to “y”
    Signal box(401, 10E4, -0.01, "y", "cos(10 t)");

    //Calls the member function to write signal information to a text file
    box.outFile();

    //If the program gets to this stage, then it ends with returning 0 to the main function
    return 0;
}