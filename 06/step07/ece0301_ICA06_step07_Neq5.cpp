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
const int DIM = 5;

//Function Prototypes
int convertToInteger(std::ifstream & in, ofstream & out, string intro, string before, string A1);

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
	for (int w = 0; w < y; w++)
	{
		out <<  "[ " << setw(10) << aMatrix[w][0] << setw(10) << aMatrix[w][1] << setw(10) << aMatrix[w][2] << setw(10) << aMatrix[w][3] << setw(10) << aMatrix[w][4]<< " ]\n";
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
	
	//Displaying "b = " and then the values in bMatrix
	out << "b = \n";
	
	for(int i = 0; i < DIM; i++)
	{
		in >> bMatrix[i][0];
	}
	
	for (int y = 0; y < DIM; y++)
	{
		out << "[ " << setw(10) << bMatrix[y][0] << " ]\n";
	}
	
	//Ending the program if it gets to this point
	return 0;
}

//Functino Definition
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