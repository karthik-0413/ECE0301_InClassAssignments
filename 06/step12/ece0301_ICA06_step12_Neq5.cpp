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

int convertToInteger(std::ifstream & in, ofstream & out, string intro, string before, string A1);
double getDet(double aMatrix[][DIM], int dim);
void Minor(double aMatrix[][DIM], double newMatrix[][DIM], int i, int j, int n);
double determinant(double aMatrix[][DIM], int n);

int main()
{
	ifstream in;
	
	in.open("ECE0301_ICA06_Axeqb_problem.txt");
	
	ofstream out;
	
	out.open("ECE0301_ICA06_Axeqb_solution.txt");
	
	string intro, before, A1;
	double aMatrix[DIM][DIM];
	
	int y; 
	double deter;
	
	y = convertToInteger(in, out, intro, before, A1);
	
	for(int i = 0; i < DIM; i++)
	{
		for (int j = 0; j < DIM; j++)
		{
			in >> aMatrix[i][j];
		}
	}
	
	for (int w = 0; w < y; w++)
	{
		out <<  "[ " << setw(10) << aMatrix[w][0] << setw(10) << aMatrix[w][1] << setw(10) << aMatrix[w][2] << setw(10) << aMatrix[w][3] << setw(10) << aMatrix[w][4]<< " ]\n";
	}
	
	int i = 1, j = 1, n = DIM;
	
	string bline, bline2;
	getline(in, bline);
	getline(in, bline2);
	
	if(bline2 != "b = ")
	{
		cout << "ERROR Input file format error.";
		return -1;
	}
	
	double newMatrix[DIM][DIM];

	Minor(aMatrix, newMatrix, i, j, n);
	
	deter = determinant(aMatrix, n);
	
	out << "det(A) = " << deter;
	
	return 0;
}


int convertToInteger(std::ifstream & in, ofstream & out, string intro, string before, string A1)
{
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
	
	if(y != DIM)
	{
		cout << "ERROR! Dimension mismatch, N != DIM" << endl;
		return -1;
	}
	
	getline(in, A1);
	
	if (A1 != "A = ")
	{
		cout << "ERROR Input file format error.";
		return -1;
	}
	return y;
}

void Minor(double aMatrix[][DIM], double newMatrix[][DIM], int i, int j, int n)
{
	int q = 0;

		for (int b = 0; b < n; b++)
		{
			
			if(b != 0)
			{
					for (int g = 0; g < n; g++)
					{
						if(g != j)
						{
							newMatrix[b-1][q] = aMatrix[b][g];
							q++;
						}
					}
					q = 0;
			}
		}
}

double determinant(double aMatrix[][DIM], int n)
{	
	double deter = 0, newMatrix2[DIM][DIM], det1 =  0;
	
	if (n == 1)
	{
		return aMatrix[0][0];
	}
	
	for (int t = 0; t < n; t++)
	{
		Minor(aMatrix, newMatrix2, 0, t, n);
		
		det1 = determinant(newMatrix2, (n-1));
		
		deter += pow(-1, t) * det1 * aMatrix[0][t];
	}
	
	return deter;
}