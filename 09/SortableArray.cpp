#include "SortableArray.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Default Constructor to initialize variables
SortableArray::SortableArray()
{
    size = 10;
    data = new double[size];
    zeroArray();
}

//Constructor to initialize starting array
SortableArray::SortableArray(unsigned int num)
{
    size = num;
    data = new double[size];
    zeroArray();
}

//Destructor to delete allocated array
SortableArray::~SortableArray()
{
    delete[] data;
}

//Function to obtain the values in data array
double* SortableArray::getData() const
{
    return data;
}

//Function to obtain the value of the size
unsigned int SortableArray::getSize() const
{
    return size;
}

//Making all the array values initially equal to zero
void SortableArray::zeroArray()
{
    for (int i = 0; i < size; i++)
    {
        *(data + i) = 0;
    }
}

//Function that gives random numbers to sort
void SortableArray::random()
{
    //Setting current time
    srand(time(0));

    for (unsigned int a = 0; a < size; a++)
    {
        //Copying what was given in the instructions
        double rand_01 = static_cast<double>(rand()) / RAND_MAX;

        //Copying what was given in the instructions
        double rand_pm1 = 2 * rand_01 - 1;

        //Setting the 256 values that are being generated into the data array
        *(data + a) = rand_pm1;
    }
}

//Function to output the 
void SortableArray::textFile(ofstream& out, bool good)
{
    //If-Else Statement to know whether to display the unsorted array or the sorted array
    if (good == 0)  //Displaying Unsorted Array
    {
        out << "ECE 0301 - Sorting Arrays\n";
        out << "Unsorted Array:\n";
        for (int i = 0; i < size; i++)
        {
            out << *(data + i) << "\n";
        }
    }
    else if (good == 1)  //Displaying Sorted Array
    {
        out << "Sorted Array:\n";
        for (int i = 0; i < size; i++)
        {
            out << *(data + i) << "\n";
        }
    }
}