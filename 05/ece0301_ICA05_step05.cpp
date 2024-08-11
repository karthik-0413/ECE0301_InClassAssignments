//Karthik Raja
//ECE 0301
//In-Class Assignment 5

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
using namespace std;

//Function Prototypes
void minTerm(std::ifstream &in, std::ofstream &out,  string t[][3], int d);
void maxTerm(std::ifstream &in, std::ofstream &out,  string p[][3], int d);

int main()
{	
	//Defining an ofstream file to transfer values to a .txt file
	ofstream out;
	
	//Naming the .txt file I would like to write values in
	out.open("Bool_func_3var_CSOP_CPOS.txt");
	
	//Defining an ofstream file to transfer values to a .txt file
	ifstream in;
	
	//Naming the .txt file I would like to get values from
	in.open("Bool_func_3var.txt");
	
	//Declaring an integer variable to read the first line of the input file
	int d;
	
	//Reading the first line of the input file
	in >> d;
	
	// ERROR CHECKING to see if the number in the first line is between 0-7
	if (d > 7 || d < 0)
	{
		//Displaying error message along with an error exit code
		cout << "ERROR! Invalid minterm index." << endl;
		return -1;
	}
	
	//Displaying Introductory message to users
	out << "ECE 0301: Boolean Functions of 3 Variables.\nRealization in Canonical Forms.\n\n";
	
	//Declaring string variables for the POS and SOP values of each line of the truth table
	string t[8][3];
	string p[8][3];
	
	//Function Calls to display minterm and maxterm of the row desired
	minTerm(in, out, t, d);
	maxTerm(in, out, p, d);

	////If program makes it to this, then it ends the program returning 0 to main function
	return 0;
}

//Function definition for the function to display the minterm of the desired row of the truth table
void minTerm(std::ifstream &in, std::ofstream &out,  string t[][3], int d)		
{
	//Declaring variables to iterate the rows and the columns of the 2-D matrix containing the POS correctly
	int v = 0, n = 0;
	
	//Using nested for loop to obtain to different values of x, y, z for the truth table
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int g = 0; g < 2; g++)
			{
				//Resetting the columns to the 0 every iteration
				n = 0;
				//Assigning each element of the 2-D matrix to the correct value depending on what the value of x, y, z is in the truth table
				if (i == 0)
				{
					t[v][n] = "x'";
				}
				else
				{
					t[v][n] = "x";
				}
				//Adding 1 to n every time to move to the next column
				n++;

				if (j == 0)
				{
					t[v][n] = "y'";
				}
				else
				{
					t[v][n] = "y";
				}
				//Adding 1 to n every time to move to the next column
				n++;
				
				if (g == 0)
				{
					t[v][n] = "z'";
				}
				else
				{
					t[v][n] = "z";
				}
				//Adding 1 to v every iteration to move to the next row
				v++;
				
			}
		}
	}
	//Using a switch to determine which case to follow depending on the number in the first line of the input file and displaying the corresponding minterm value 
	switch (d)
		{
		case 0:
			out << "m0 = " << t[0][0] << t[0][1] << t[0][2] << endl;
			break;
		case 1:
			out << "m1 = " << t[1][0] << t[1][1] << t[1][2] << endl;
			break;
		case 2:
			out << "m2 = " << t[2][0] << t[2][1] << t[2][2] << endl;
			break;
		case 3:
			out << "m3 = " << t[3][0] << t[3][1] << t[3][2] << endl;
			break;
		case 4:
			out << "m4 = " << t[4][0] << t[4][1] << t[4][2] << endl;
			break;
		case 5:
			out << "m5 = " << t[5][0] << t[5][1] << t[5][2] << endl;
			break;
		case 6:
			out << "m6 = " << t[6][0] << t[6][1] << t[6][2] << endl;
			break;
		case 7:
			out << "m7 = " << t[7][0] << t[7][1] << t[7][2] << endl;
			break;
		}

}

//Function definition for the function to display the minterm of the desired row of the truth table
void maxTerm(std::ifstream &in, std::ofstream &out,  string p[][3], int d)		
{
	//Declaring variables to iterate the rows and the columns of the 2-D matrix containing the POS correctly
	int v = 0, n = 0;
	
	//Using nested for loop to obtain to different values of x, y, z for the truth table
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int g = 0; g < 2; g++)
			{
				//Resetting the columns to the 0 every iteration
				n = 0;
				//Assigning each element of the 2-D matrix to the correct value depending on what the value of x, y, z is in the truth table
				if (i == 0)
				{
					p[v][n] = "x";
				}
				else
				{
					p[v][n] = "x'";
				}
				//Adding 1 to n every time to move to the next column
				n++;
				
				if (j == 0)
				{
					p[v][n] = "y";
				}
				else
				{
					p[v][n] = "y'";
				}
				//Adding 1 to n every time to move to the next column
				n++;
				
				if (g == 0)
				{
					p[v][n] = "z";
				}
				else
				{
					p[v][n] = "z'";
				}
				//Adding 1 to v every iteration to move to the next row
				v++;
				
			}
		}
	}
//Using a switch to determine which case to follow depending on the number in the first line of the input file and displaying the corresponding minterm value
	switch (d)
		{
		case 0:
			out << "M0 = " << p[0][0] << " + " << p[0][1] << " + " << p[0][2] << endl;
			break;
		case 1:
			out << "M1 = " << p[1][0] << " + " << p[1][1] << " + " << p[1][2] << endl;
			break;
		case 2:
			out << "M2 = " << p[2][0] << " + " << p[2][1] << " + " << p[2][2] << endl;
			break;
		case 3:
			out << "M3 = " << p[3][0] << " + " << p[3][1] << " + " << p[3][2] << endl;
			break;
		case 4:
			out << "M4 = " << p[4][0] << " + " << p[4][1] << " + " << p[4][2] << endl;
			break;
		case 5:
			out << "M5 = " << p[5][0] << " + " << p[5][1] << " + " << p[5][2] << endl;
			break;
		case 6:
			out << "M6 = " << p[6][0] << " + " << p[6][1] << " + " << p[6][2] << endl;
			break;
		case 7:
			out << "M7 = " << p[7][0] << " + " << p[7][1] << " + " << p[7][2] << endl;
			break;
		}

}