
//Karthik Raja
//ECE 0301
//In-Class Assignment 5

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
using namespace std;

//Function Prototype
void CSOP(std::ofstream &out, int num, int bin[]);

int main()
{
	//Declaring an int array to store the values for binary digits
	int bin[8];
	
	//Defining an ofstream file to transfer values to a .txt file
	ofstream out;
	
	//Naming the .txt file I would like to write values in
	out.open("Bool_func_3var_CSOP_CPOS.txt");
	
	//Defining an ofstream file to transfer values to a .txt file
	ifstream in;
	
	//Naming the .txt file I would like to get values from
	in.open("Bool_func_3var.txt");
	
	//Delcaring an interger to input that into the program
	int num;
	in >> num;
	
	// ERROR CHECKING to see if the number in the first line is between 0-7
	if (num > 255 || num < 0)
	{
		//Displaying error message along with an error exit code
		cout << "ERROR! Function index out of range." << endl;
		return -1;
	}
	
	//Displaying Introductory message to users
	out << "ECE 0301: Boolean Functions of 3 Variables.\nRealization in Canonical Forms.\n\n";
	
	//Function Calling
	CSOP(out, num, bin);
	
	//If program makes it to this, then it ends with returning an interger back to the main
	return 0;
}

//Function Definition for making a SOP for the truth table
void CSOP(std::ofstream &out, int num, int bin[])
{
	//If the integer read is 0, then the f0 = 0
	if (num == 0)
	{
		out << "CSOP: f0 = 0";
	}
	//If the integer read is a normal number, then the function is numbered based on the number read in.
	else if (num != 0)
	{
		out << "CSOP: f" << num << " = ";
	}
	
	int a = num;	//since num changes when converting to binary, I don't have a num to show it
	int status[8];	//Last row of the truth table
	string p[8][3];	//The 2-D array of the SOP stored in this string  array
	int f = 7;		//Variable used iterate you the status array and the bin array the opposite directions to assign the binary digit to the correct row in the truth table
	
			//For loop to turn decimal to binary
			for (int g = 0; g < 8; g++)
				{
					bin[g] = num % 2;
					status[f] = bin[g];
					num /= 2;
					f--;
				}
	//Declaring variables iterate the loop properly
	int r = 0, v = 0, n = 0, count = 0;
	
	//Declaring 3 nested for-loop to create the truth table values
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int g = 0; g < 2; g++)
			{
				//For minterm, we are only focused on when the result column is equal to 1
				if (status[r] == 1)
				{
					//Resetting the column the variable to 0 every variable since we have only three rows
				 	n = 0;
				 	//Assigning values to each of the minterm values depending on their value on the truth table
					if (i == 0)
					{
						p[v][n] = "x'";
					}
					else
					{
						p[v][n] = "x";
					}
					
					//Adding 1 to n every time to move to the next column
					n++;

					if (j == 0)
					{
						p[v][n] = "y'";
					}
					else
					{
						p[v][n] = "y";
					}
					
					//Adding 1 to n every time to move to the next column
					n++;
					
					if (g == 0)
					{
						p[v][n] = "z'";
					}
					else
					{
						p[v][n] = "z";
					}
					
					//Adding 1 to v every iteration to move to the next row
					v++;
					
					count++;
				}
				//Adding 1 to r every iteration to move on to the next result value in the result column of the truth table
				r++;
				}
			}
		}
	
	//Using a for loop to display the values of the SOP result			
	for (int e = 0; e < count; e++)
	{
		//Since the last value does not need an addition value after it, I created an if-else loop to make sure it does not 
		if (e == count - 1)
		{
			out << p[e][0] << p[e][1] << p[e][2];
		}
		else
		{
			out << p[e][0] << p[e][1] << p[e][2] << " + ";
		}
	}
	
	//If the number read from the file is 0, then the function is for function 0.
	if (a == 0)
	{
		out << "\n\nTruth table for CSOP form of function 0." << endl << endl;
	}
	//If the number read from the file is normal, then the function depends on the num read in.
	else if (a != 0)
	{
		out << "\n\nTruth table for CSOP form of function " << a << "." << endl << endl;
	}
	
	//Re-initializing r since we are reusing it
	r = 0;
	//Formatting the output file how the instructions tell me to 
	out << "x\ty\tz\tf(x,y,z)\n";
	out << "--------------------------------\n";
	
	//Using a for loop to display the truth table values to the output file and the corresponding function values. 
	for (int x = 0; x < 2; x++)
		{
			for (int y = 0; y < 2; y++)
			{
				for (int z = 0; z < 2; z++)
				{
					//Displaying the value of x, y, z for each row of the table
					out << x << "\t" << y << "\t" << z << "\t";
					out << status[r] << endl;
					r++;
				}
			}
		}
}