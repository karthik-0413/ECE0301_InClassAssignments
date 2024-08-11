#include <iostream>
#include <fstream>
using namespace std;

//Declaring Class for SortableArray
class SortableArray
{
private:
    double* data;
    unsigned int size;

public:
    SortableArray();
    SortableArray(unsigned int);
    ~SortableArray();
    double* getData() const;
    unsigned int getSize() const;
    void zeroArray();
    void textFile(ofstream&, bool);
};

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

//Merge Function
void merge(double* arr, unsigned int i0, unsigned int i1, unsigned int i2)
{
    unsigned int i = i0;    //Starting element for first part of array
    unsigned int j = i1 + 1;       //Starting element for second part of array and adding 1 to avoid overlapping
    unsigned int k = i;    //Starting part of final merge sorted array

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

//Function to make sure that the first line is "LENGTH = " and obtaining the number after the equal sign
SortableArray readArray(ifstream& in)
{
   // Declaring needed variables for the function
    unsigned int size;
    string intro, intro2;

    //Getting the first line of the input file
    getline(in, intro);

    //Setting a string variable equal to the first 9 characters in the intro string
    intro2 = intro.substr(0,9);

    //ERROR-CHECKING the first line of the input file
    if (intro2 != "LENGTH = ")
    {
        cout << "ERROR! Invalid input file header." << endl;
        exit(EXIT_FAILURE);
    }

    //Converting the number after the equal sign form a string to an integer
    string w = intro.substr(9);
    size = stoi(w);

    //Creating an instance of the SortableArray class to get the size initialized above
    SortableArray box(size);

    //Inputting numbers from the input file to the data array
    for (int i = 0; i < size; i++)
    {
        in >> *(box.getData() + i);
    }

    //Returning the instance created
    return box;
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
    ifstream in;
    in.open("ece0301_unsorted_array.txt");

    //Creating an instance of SortableArray to 
    SortableArray box = readArray(in);

    //Displaying the unsorted array
    box.textFile(out, false);    

    //Calling the split function with the correct parameters
    split(box.getData(), i, box.getSize() - j);

    //Displaying the sorted array
    box.textFile(out, true);

    //Closing the input and output files
    out.close();
    in.close();

    //If the program gets to this part, then it ends with returning 0 to the main function
    return 0;
}