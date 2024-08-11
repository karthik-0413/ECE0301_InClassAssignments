//Karthik Raja
//ECE 0301
//In-Class Assignment 5

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

//Function Prototypes
void CPOS(std::ofstream &out, int y, int bin[]);
void CSOP(std::ofstream &out, int y, int bin[]);

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
	
	string intro;
	string before;
	
	//ERROR checking to see if the input file has the correct first line
	getline(in, intro);
	if (intro != "Boolean function of three variables")
	{
		return -1;
	}
	
	//Getting the second line from the input file
	getline(in, before);
	
	//Checking that the number in the input file is either a single, double, or a triple digit number
	if(before.length() != 18 && before.length() != 19 && before.length() != 20)
	{
		return -1;
	}
	
	
	int w = before.length();	//stores the length of the string 'before' in w;
	string num;
	string g = before.substr(17,2);	//Using substr to get the specific part of the second line I need
	string h = before.substr(17,3);	//Using substr to get the specific part of the second line I need
	
	//Else-if statements to either read in a single, double, triple digit number
	if (w == 18)
	{
		num = before[17];
	}

	else if (w == 19)
	{
		num = g;
	}
	
	else if (w == 20)
	{
		num = h;
	}
	
	//Converting the string number value into an integer value
	int y = stoi(num);
	
	// ERROR CHECKING to see if the number in the first line is between 0-7
	if (y > 255 || y < 0)
	{
		//Displaying error message along with an error exit code
		cout << "ERROR! Functin index out of range." << endl;
		return -1;
	}
	
	//Displaying Introductory message to users
	out << "ECE 0301: Boolean Functions of 3 Variables.\nRealization in Canonical Forms.\n\n";
	
	//Calling Function
	CPOS(out, y, bin);
	CSOP(out, y, bin);
	
	return 0;
}

//Function Definition for making a SOP for the truth table
void CPOS(std::ofstream &out, int y, int bin[])
{
	int a = y;		//since num changes when converting to binary, I don't have a num to show it
	int status[8];	//Last row of the truth table
	string t[8][3];	//The 2-D array of the SOP stored in this string  array
	int f = 7;		//Variable used iterate you the status array and the bin array the opposite directions to assign the binary digit to the correct row in the truth table
	
			//For loop to turn decimal to binary
			for (int g = 0; g < 8; g++)
				{
					bin[g] = y % 2;
					status[f] = bin[g];
					y /= 2;
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
					//Count variable to see how many terms I have to display in the output
					count++;
				}
				//Adding 1 to r every iteration to move on to the next result value in the result column of the truth table
				r++;
				}
			
			}
		}
			//If the number read from the file is 0, then the function is for function 0.
			if (a == 0)
			{
				out << "CSOP: f0 = 0";
			}
			else
			{
				out << "CSOP: f" << a << " = ";
			}
			
				//Using a for loop to display the values of the SOP result
				for (int e = 0; e < count; e++)
				{
					//Since the last value does not need an addition value after it, I created an if-else loop to make sure it does not 
					if (e == count - 1)
					{
						out << t[e][0] << t[e][1] << t[e][2];
					}
					else
					{
						out << t[e][0] << t[e][1] << t[e][2] << " + ";
					}
				}
				//Formatting the output file how the instructions tell me to 
				out << "\n\nTruth table for CPOS form of function " << a << "." << endl << endl;
				r = 0;
				out << "x\ty\tz\tf(x,y,z)\n";
				out << "--------------------------------\n";
				
				//Using a for loop to display the truth table values to the output file and the corresponding function values. 
				for (int i = 0; i < 2; i++)
					{
						for (int j = 0; j < 2; j++)
						{
							for (int g = 0; g < 2; g++)
							{
								//Displaying the value of x, y, z for each row of the table
								out << i << "\t" << j << "\t" << g << "\t";
								out << status[r] << endl;
								r++;
							}
						}
					}
}

//Function Definition for making a POS for the truth table
void CSOP(std::ofstream &out, int y, int bin[])
{
				
	int b = y;
	int status2[8];
	string t[8][3];
	int f = 7;
			//For loop to turn decimal to binary
			for (int g = 0; g < 8; g++)
				{
					bin[g] = y % 2;
					status2[f] = bin[g];
					y /= 2;
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
				//For maxterm, we are only focused on when the result column is equal to 0
				if (status2[r] == 0)
				{
					//Resetting the column the variable to 0 every variable since we have only three rows
				 	n = 0;
				 	//Assigning values to each of the minterm values depending on their value on the truth table
					if (i == 0)
					{
						t[v][n] = "x";
					}
					else
					{
						t[v][n] = "x'";
					}
					
					//Adding 1 to n every time to move to the next column
					n++;

					if (j == 0)
					{
						t[v][n] = "y";
					}
					else
					{
						t[v][n] = "y'";
					}
					
					//Adding 1 to n every time to move to the next column
					n++;
					
					if (g == 0)
					{
						t[v][n] = "z";
					}
					else
					{
						t[v][n] = "z'";
					}
					
					//Adding 1 to v every iteration to move to the next row
					v++;
					//Count variable to see how many terms I have to display in the output
					count++;
				}
				//Adding 1 to r every iteration to move on to the next result value in the result column of the truth table
				r++;
				}
			
			}
		}
		
		//If the number read in from the input file is 255, then the CPOS is 1
		if (b == 255)
		{
			out << "CPOS: f255 = 1";
		}
		else if (b == 0)
		{
			out << "CPOS: f0 = 0";
		}
		else if (b != 255)
		{
			out << "CPOS: f" << b << " = ";
		}
			//Using a for loop to display the values of the POS result	
			for (int e = 0; e < count; e++)
			{
				out << "(" << t[e][0] << " + " << t[e][1] << " + " << t[e][2] << ")";
			}
			//Formatting the output file how the instructions tell me to 
			out << "\n\nTruth table for CPOS form of function " << b << "." << endl << endl;
			r = 0;
			out << "x\ty\tz\tf(x,y,z)\n";
			out << "--------------------------------\n";
			
			//Using a for loop to display the truth table values to the output file and the corresponding function values. 
			for (int i = 0; i < 2; i++)
				{
					for (int j = 0; j < 2; j++)
					{
						for (int g = 0; g < 2; g++)
						{
							//Displaying the value of x, y, z for each row of the table
							out << i << "\t" << j << "\t" << g << "\t";
							out << status2[r] << endl;
							r++;
						}
					}
				}
}