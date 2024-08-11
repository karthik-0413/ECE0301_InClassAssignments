#include "Signal.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <iomanip>
//#include <mgl2/mgl.h>

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
    
    //Calling MATHGL function
   // box2.MATHGL();

    //Exiting the program if it get to this part of the program
    return 0;
}