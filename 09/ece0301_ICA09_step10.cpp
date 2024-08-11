#include "SortableArray.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Merge Function
void merge(double* arr, unsigned int i0, unsigned int i1, unsigned int i2)
{
    unsigned int i = i0;    //Starting element for first part of array
    unsigned int j = i1 + 1;       //Starting element for second part of array and adding 1 to avoid overlapping
    unsigned int k = i0;    //Starting part of final merge sorted array

    //Declaring the final sorted merged array
    double array[i2];

    //As long as there are more elements in both sub-arrays, compare the first elements in each sub-array
    while (i <= i1 && j <= i2)
    {
        //Copy the smaller element into the first open element of the lower array
        if (*(arr + i) <= *(arr + j))
        {
            *(array + k) = *(arr + i);
            i++;
        }
        else
        {
            *(array + k) = *(arr + j);
            j++;
        }
        k++;
     //Go back to the top of this loop
    }

    //Copy the remaining elements from the other sub-array to the lower array
    while (i <= i1)
    {
        *(array + k) = *(arr + i);
        i++;
        k++;
    }

    //Copy the remaining elements from the other sub-array to the lower array
    while (j <= i2)
    {
        *(array + k) = *(arr + j);
        j++;
        k++;
    }

    //Copying all of the elements of the array declared in the function into the array that was in the parameter of the function
    for (int e = i0; e <= i2; e++)
    {
        *(arr + e) = *(array + e);
    }
}

//Split function as demonstrated in class
void split(double* arr, unsigned int i0, unsigned int i2)
{
    if (i0 < i2)
    {
        //Getting midpoint of the array
        unsigned int i1 = (i0 + i2) / 2;

        //Recursively calling the split function with the unsigned int values changing
        split(arr, i0, i1);
        split(arr, i1 + 1, i2);

        //Calling the merge function with the psuedocode that was provided for us
        merge(arr, i0, i1, i2);
    }
}

//Main Function
int main()
{
    //Declaring variables to know where to start and stop sorting in the split function
    int i = 0;
    int j = (i+1);

    //Declaring input and output files
    ofstream out;
    out.open("ece0301_merge_sort_results.txt");

    //Creating an instance of SortableArray to 
    SortableArray box(256);

    //Calling the random member function to give me numbers for my data array
    box.random();

    //Displaying the unsorted array
    box.textFile(out, false);    

    //Calling the split function with the correct parameters
    split(box.getData(), i, box.getSize() - j);     //Subtracting j because C++ counts arrays starting from 0

    //Displaying the sorted array
    box.textFile(out, true);

    //Closing the input and output files
    out.close();

    //If the program gets to this part, then it ends with returning 0 to the main function
    return 0;
}