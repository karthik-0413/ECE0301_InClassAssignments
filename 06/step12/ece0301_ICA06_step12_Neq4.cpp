//Karthik Raja
//ECE 0301
//In-Class Assignment 6

#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <cmath>
#include <iomanip>
using namespace std;

//Declaring a constant integer variable
const int DIM = 4;

//Function Prototypes
int convertToInteger(std::ifstream & in, ofstream & out, string intro, string before, string A1);
double getDet(double aMatrix[][DIM], int dim);
void Minor(double aMatrix[][DIM], double newMatrix[][DIM], int i, int j, int n);
double determinant(double aMatrix[][DIM], int n);

int main()
{
	//Declaring and opening the file I am reading values from
	ifstream in;
	in.open("ECE0301_ICA06_Axeqb_problem.txt");
	
	//Declaring and opening the file I want to write value to 
	ofstream out;
	out.open("ECE0301_ICA06_Axeqb_solution.txt");
	
	//Declaring variables
	string intro, before, A1;
	double aMatrix[DIM][DIM];
	int y; 
	double deter;
	
	//Calling function to check if dimension read in is equal to the dimension wanted
	y = convertToInteger(in, out, intro, before, A1);
	
	//Nested for loop to read in the values for aMatrix
	for(int i = 0; i < DIM; i++)
	{
		for (int j = 0; j < DIM; j++)
		{
			in >> aMatrix[i][j];
		}
	}
	
	//Displaying aMatrix values
	for (int i = 0; i < DIM; i++)
	{
		out <<  "[ " << setw(10) << aMatrix[i][0] << setw(10) << aMatrix[i][1] << setw(10) << aMatrix[i][2] << setw(10) << aMatrix[i][3] << " ]\n";
	}
	
	//Declaring variables to help find the determinant
	int i = 0, j = 0, n = DIM;
	double newMatrix[DIM][DIM];

	//Calling the Minor function so that it makes the minors properly
	Minor(aMatrix, newMatrix, i, j, n);
	
	//Calling the determinant to get the determinant into the main
	deter = determinant(aMatrix, n);
	
	//Displaying the determinant to the output file
	out << "det(A) = " << deter;

	//Ending the program if it gets to this point
	return 0;
}

//Function Definition
int convertToInteger(std::ifstream & in, ofstream & out, string intro, string before, string A1)
{
	//ERROR checking to make sure that the next line is "ECE 0301: Ax = b Problem"
	getline(in, intro);
	
	if (intro != "ECE 0301: Ax = b Problem")
	{
		cout << "ERROR! Input file format error." << endl;
		return -1;
	}
	
	//Getting the second line from the input file
	getline(in, before);
	
	//Checking that the number in the input file is either a single, double, or a triple digit number
	if(before.length() != 5)
	{
		return -1;
	}
	
	
	int w = before.length();	//stores the length of the string 'before' in w;
	string num;
	
	//Else-if statements to either read in a single, double, triple digit number
	if (w == 5)
	{
		num = before[4];
	}
	
	//Converting the string number value into an integer value
	int y = stoi(num);
	
	//ERROR checking to make sure that the dimension read is equal to the cons int declared on top
	if(y != DIM)
	{
		cout << "ERROR! Dimension mismatch, N != DIM" << endl;
		return -1;
	}
	
	//ERROR checking to make sure that the next line of code is "A = "
	getline(in, A1);
	
	if (A1 != "A = ")
	{
		cout << "ERROR Input file format error.";
		return -1;
		
	}
	return y;
}

//Function definition
void Minor(double aMatrix[][DIM], double newMatrix[][DIM], int i, int j, int n)
{
	//Declare variable to run through the columns
	int q = 0;

		//Nested for loop to go through all of the rows and columns and assign them to a new matrix
		for (int b = 0; b < n; b++)
		{
			//Does not enter the for loop if the row is 0
			if(b != 0)
			{
					for (int g = 0; g < n; g++)
					{
						//Does not enter the for loop if the column is equal to the j value initialized in the main
						if(g != j)
						{
							//Assigns the minor to the corresponding value in the aMatrix
							newMatrix[b-1][q] = aMatrix[b][g];
							//Adds one to q every time to go through every column
							q++;
						}
					}
					//Set q back to 0, because we have to go back to the first column after the program reaches the end
					q = 0;
			}
		}
}

//Function Definition
double determinant(double aMatrix[][DIM], int n)
{	
	//Declare Variables
	double deter, newMatrix2[DIM][DIM], det1 =  0;
	
	//If the matrix is a 1x1, then it returns the only element in the matrix
	if (n == 1)
	{
		return aMatrix[0][0];
	}
	
	//Else, initialize determinant to zero
	deter = 0;
	
	//For loop over the elements in row 0 of aMatrix
	for (int t = 0; t < n; t++)
	{
		//Calling Minor function to get the minor of aMatrix
		Minor(aMatrix, newMatrix2, 0, t, n);
		
		//Calling determinant function to get the determinant of the minor
		det1 = determinant(newMatrix2, (n-1));
		
		//Finding the total determinant by using the given formula
		deter += pow(-1, t) * det1 * aMatrix[0][t];
	}
	
	//Returning the determinant value back to the main
	return deter;
}