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
const int DIM = 3;

//Function Prototypes
int convertToInteger(std::ifstream & in, ofstream & out, string intro, string before, string A1);
void Minor(double aMatrix[][DIM], double newMatrix[][DIM], int i, int j, int n);
double determinant(double aMatrix[][DIM], int n);
void Output(ofstream & out, double aMatrix[][3], double xValues[], double bValues[], double bMatrix[][1]);
void cramer(ofstream &out, double aMatrix[][DIM], double xValues[], double bMatrix[][1], double det, int n);
void mMult(ofstream & out, double aMatrix[][3], double xValues[], double bValues []);
void Output2(ofstream & out, double aMatrix[][3], double xValues[], double bValues[], double bMatrix[][1]);

int main()
{
	//Declaring and opening the file I am reading values from
	ifstream in;
	in.open("ECE0301_ICA06_Axeqb_problem.txt");
	
	//Declaring and opening the file I want to write value to 
	ofstream out;
	out.open("ECE0301_ICA06_Axeqb_solution.txt");
	
	//Displaying introductory message
	out << "ECE 0301 - Matrix-Vector Computations,\nDeterminants and Cramer's Rule.\n\n";
	
	//Showing users the dimension the matrix is
	out << "Global array dimension: DIM = " << DIM << endl;
	
	//Declaring variables
	string intro, before, A1;
	double aMatrix[DIM][DIM], bMatrix[DIM][1];
	int y; 
	
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
		out <<  "[ " << setw(10) << aMatrix[i][0] << setw(10) << aMatrix[i][1] << setw(10) << aMatrix[i][2] << " ]\n";
	}
	
	//ERROR checking to make sure that the next line is "b = "
	string bline, bline2;
	getline(in, bline);
	getline(in, bline2);
	
	if(bline2 != "b = ")
	{
		cout << "ERROR Input file format error.";
		return -1;
	}
	
	out << "b = \n";
	
	
	for(int i = 0; i < DIM; i++)
	{
		in >> bMatrix[i][0];
	}
	
	for (int j = 0; j < y; j++)
	{
		out << "[ " << setw(10) << bMatrix[j][0] << " ]\n";
	}
	
	//Declaring Variables
	double xValues[3], bValues[3], det, newMatrix[DIM][DIM];
	int i = 0, j = 0, n = DIM;

	//Calling Functions
	Minor(aMatrix, newMatrix,  i,  j,  n);
	det = determinant(aMatrix, n);
	Output(out, aMatrix, xValues, bValues, bMatrix);
	cramer(out, aMatrix, xValues, bMatrix, det, n);
	mMult(out, aMatrix, xValues, bValues);
	Output2(out, aMatrix, xValues, bValues, bMatrix);
	
	//Ending the program if it gets to this point
	return 0;
}

//Function Prototype
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
	
	//If everything is correct, then display the dimension read in
	out << "Input file: N = " << y << endl << endl;
		
	//Displaying "A = "
	out << A1 << endl;

	//Return integer
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
	double det = 0, newMatrix2[DIM][DIM], det1 =  0;
	
	//If the matrix is a 1x1, then it returns the only element in the matrix
	if (n == 1)
	{
		return aMatrix[0][0];
	}
	
	//Else, initialize determinant to zero
	for (int t = 0; t < n; t++)
	{
		//For loop over the elements in row 0 of aMatrix
		Minor(aMatrix, newMatrix2, 0, t, n);
		
		//Calling determinant function to get the determinant of the minor
		det1 = determinant(newMatrix2, (n-1));
		
		//Finding the total determinant by using the given formula
		det += pow(-1, t) * det1 * aMatrix[0][t];
	}
	
	//Returning the determinant value back to the main
	return det;
}

void Output(ofstream & out, double aMatrix[][3], double xValues[], double bValues[], double bMatrix[][1])
{
	out << "\nProblem: A * x = b\n";

	//Using a for loop to display the numbers and variables in an organized matter
	for (int g = 0; g < 3; g++)
	{
		//There is a * and a = only in the first row
		if(g == 1)
		{
			out << "[ " << setw(10) << aMatrix[g][0] << setw(10) << aMatrix[g][1] << setw(10) << aMatrix[g][2] << " ] * [ " <<  "x1" << " ] = [ " << setw(10) << bMatrix[g][0] << " ]\n";
		}
		else if (g == 0)
		{
			out << "[ " << setw(10) << aMatrix[g][0] << setw(10) << aMatrix[g][1] << setw(10) << aMatrix[g][2] << " ]   [ " <<  "x0" << " ]   [ " << setw(10) << bMatrix[g][0] << " ]\n";
		}
		else if (g == 2)
		{
			out << "[ " << setw(10) << aMatrix[g][0] << setw(10) << aMatrix[g][1] << setw(10) << aMatrix[g][2] << " ]   [ " <<  "x2" << " ]   [ " << setw(10) << bMatrix[g][0] << " ]\n";
		}
	}
	
}

//Function Definition
void cramer(ofstream &out, double aMatrix[][DIM], double xValues[], double bMatrix[][1], double det, int n)
{
	//Declares variables
	double newMatrix3[DIM][DIM], det2, det1, det3 = det;
	
			//Declares newMatrix3 to be equal to aMatrix
			for (int g = 0; g < DIM; g++)
				{
					for (int r = 0; r < DIM; r++)
					{
						newMatrix3[g][r] = aMatrix[g][r];
					}
				}
				
			//Nested for loop to replace each column by the b column vector
			for (int r =0; r < DIM; r++)
			{
				for (int y = 0; y < DIM; y++)
				{
					newMatrix3[y][r] = bMatrix[y][0];
				}
					//Finds the determinant when the b vector is replaced
					det1 = determinant(newMatrix3,  n);
					
					//By Cramer's Rule, the determinant found above should be divided by total determinant to solve for the variable
					det2 = det1/det3;
					
					//Assigning the variable found to a spot in the xValues matrix
					xValues[r] = det2;
				
					//Assigning the newMatrix3 back to aMatrix since it should get rid of the b values before going again
					for (int g = 0; g < DIM; g++)
					{
						for (int r = 0; r < DIM; r++)
							{
								newMatrix3[g][r] = aMatrix[g][r];
							}
					}
			}
	//Displaying the x values found in an organized matter			
	out << "\nSolution: x = \n";
	
	for (int i = 0; i < DIM; i++)
	{
		out <<"[ " << setw(10) << xValues[i] << " ]\n";
	}

}

void mMult(ofstream & out, double aMatrix[][3], double xValues[], double bValues [])
{
	//Finding it b vector values for multiplying the A matrix by x vector
	for (int i = 0; i < DIM; i++)
	{
		if (i == 1)
		{
			bValues[i] = aMatrix[i][0] * xValues[0] + aMatrix[i][i] * xValues[1] + aMatrix[i][2] * xValues[2];
		}
		else if (i == 2)
		{
			bValues[i] = aMatrix[i][0] * xValues[0] + aMatrix[i][1] * xValues[1] + aMatrix[i][2] * xValues[2];
		}
		else
		{
			bValues[i] = aMatrix[i][0] * xValues[0] + aMatrix[i][1] * xValues[1] + aMatrix[i][2] * xValues[2];
		}
	}
	
}

void Output2(ofstream & out, double aMatrix[][3], double xValues[], double bValues[], double bMatrix[][1])
{
	out << "\nChecking Solution: A * x = b\n";

	//Displaying the newly found b values with the aMatrix & xValues in an organized matter
	for (int g = 0; g < 3; g++)
	{
		if(g == 1)
		{
			out << "[ " << setw(10) << aMatrix[g][0] << setw(10) << aMatrix[g][1] << setw(10) << aMatrix[g][2] << " ] * [ " << setw(10) << xValues[g] << " ] = [ " << setw(10) << bMatrix[g][0] << " ]\n";
		}
		else if (g == 0)
		{
			out << "[ " << setw(10) << aMatrix[g][0] << setw(10) << aMatrix[g][1] << setw(10) << aMatrix[g][2] << " ]   [ " << setw(10) << xValues[g] << " ]   [ " << setw(10) << bMatrix[g][0] << " ]\n";
		}
		else if (g == 2)
		{
			out << "[ " << setw(10) << aMatrix[g][0] << setw(10) << aMatrix[g][1] << setw(10) << aMatrix[g][2] << " ]   [ " << setw(10) << xValues[g] << " ]   [ " << setw(10) << bMatrix[g][0] << " ]\n";
		}
	}
	
	out << "\nError in RHS values: \n";
	
	//Declaring an error array
	double error[3];
	
	//Finding the error values
	error[0] = bMatrix[0][0] - bValues[0];
	error[1] = bMatrix[1][0] - bValues[1];
	error[2] = bMatrix[2][0] - bValues[2];
	
	//Displaying error values
	for (int j = 0; j < DIM; j++)
	{
		out << "[ " << setw(10) << error[j] << " ]\n";
	}
	
}