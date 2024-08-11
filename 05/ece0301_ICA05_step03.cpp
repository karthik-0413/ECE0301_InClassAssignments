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
void truthTable(std::ofstream &out);
void truthTable2(std::ofstream &out);


int main()
{	
	//Defining an ofstream file to transfer values to a .txt file
	ofstream out;
	
	//Naming the .txt file I would like to write values in
	out.open("Bool_func_3var_CSOP_CPOS.txt");
	
	//Calling function to display OR truth table
	truthTable(out);
	
	//Calling function to display AND truth table
	truthTable2(out);

	//If program makes it to this, then it ends the program returning 0 to main function
	return 0;
}

//Function for OR truth table
void truthTable(std::ofstream &out)
{
	//Declaring a bool variable to get the values of the end column of the truth table
	bool status;
	
	//Displaying Introductory message to users
	out << "ECE 0301: Boolean Functions of 3 Variables.\nRealization in Canonical Forms.\n";
	
	//Formatting the truth table how the instructions wanted us to
	out << "\nTruth table for OR gate.\n\n";
	
	out << "x\ty\tz\tf(x,y,z)\n";
	out << "--------------------------------\n";
	
	//Using nested for loop to obtain to different values of x, y, z for the truth table
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int g = 0; g < 2; g++)
			{
				//Displaying the value of x, y, z for each row of the table
				out << i << "\t" << j << "\t" << g << "\t";
				
				//Assigning BOOL values to each of the integers used in the truth table
				bool x = i;
				bool y = j;
				bool z = g;
				
				//If-Else statement to meet the conditions of an OR gate
				if(x == 1 || y == 1 || z ==1)
				{
					status = true;
				}
				else
				{
					status = false;
				}
				//Displaying the value of the last column of the OR table for each row
				out << status << endl;
			}
		}
	}
}

//Function for AND truth table
void truthTable2(std::ofstream &out)
{
	//Declaring a bool variable to get the values of the end column of the truth table
	bool status2;

	//Formatting the truth table how the instructions wanted us to
	out << "\nTruth table for AND gate.\n\n";
	
	out << "x\ty\tz\tf(x,y,z)\n";
	out << "--------------------------------\n";
	
	//Using nested for loop to obtain to different values of x, y, z for the truth table
	for (int a = 0; a < 2; a++)
	{
		for (int b = 0; b < 2; b++)
		{
			for (int c = 0; c < 2; c++)
			{
				//Displaying the value of x, y, z for each row of the table
				out << a << "\t" << b << "\t" << c << "\t";
				
				//Assigning BOOL values to each of the integers used in the truth table
				bool e = a;
				bool f = b;
				bool h = c;
				
				//If-Else statement to meet the conditions of an AND gate
				if(e == 1 && f == 1 && h == 1)
				{
					status2 = true;
				}
				else
				{
					status2 = false;
				}
				//Displaying the value of the last column of the AND table for each row
				out << status2 << endl;
			}
		}
	}
}