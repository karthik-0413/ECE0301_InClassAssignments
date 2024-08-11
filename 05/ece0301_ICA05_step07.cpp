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
		
		//Declaring bool to fill last column of truth table
		bool status;
		
			//Displaying the minterm value for the desired rwo and Formatting the output file how the instructions told me to
			out << "m0 = " << t[0][0] << t[0][1] << t[0][2] << endl;
			out << "\nTruth table for minterm 0\n\n";
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
									if(x == 0 && y == 0 && z == 0)
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
			break;
		case 1:
			//Displaying the minterm value for the desired rwo and Formatting the output file how the instructions told me to
			out << "m1 = " << t[1][0] << t[1][1] << t[1][2] << endl;
			out << "\nTruth table for minterm 1\n\n";
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
									if(x == 0 && y == 0 && z == 1)
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
			break;
		case 2:
			//Displaying the minterm value for the desired rwo and Formatting the output file how the instructions told me to
			out << "m2 = " << t[2][0] << t[2][1] << t[2][2] << endl;
			out << "\nTruth table for minterm 2\n\n";
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
									if(x == 0 && y == 1 && z == 0)
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
			break;
		case 3:
			//Displaying the minterm value for the desired rwo and Formatting the output file how the instructions told me to
			out << "m3 = " << t[3][0] << t[3][1] << t[3][2] << endl;
			out << "\nTruth table for minterm 3\n\n";
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
									if(x == 0 && y == 1 && z == 1)
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
			break;
		case 4:
			//Displaying the minterm value for the desired rwo and Formatting the output file how the instructions told me to
			out << "m4 = " << t[4][0] << t[4][1] << t[4][2] << endl;
			out << "\nTruth table for minterm 4\n\n";
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
									if(x == 1 && y == 0 && z == 0)
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
			break;
		case 5:
			//Displaying the minterm value for the desired rwo and Formatting the output file how the instructions told me to
			out << "m5 = " << t[5][0] << t[5][1] << t[5][2] << endl;
			out << "\nTruth table for minterm 5\n\n";
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
									if(x == 1 && y == 0 && z == 1)
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
			break;
		case 6:
			//Displaying the minterm value for the desired rwo and Formatting the output file how the instructions told me to
			out << "m6 = " << t[6][0] << t[6][1] << t[6][2] << endl;
			out << "\nTruth table for minterm 6\n\n";
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
									if(x == 1 && y == 1 && z == 0)
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
			break;
		case 7:
			//Displaying the minterm value for the desired rwo and Formatting the output file how the instructions told me to
			out << "m7 = " << t[7][0] << t[7][1] << t[7][2] << endl;
			out << "\nTruth table for minterm 7\n\n";
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
									if(x == 1 && y == 1 && z == 1)
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
		
		//Declaring bool variable to fill out last column of truth table
		bool status2;
		
			//Displaying the minterm value for the desired rwo and Formatting the output file how the instructions told me to
			out << "\nM0 = " << p[0][0] << " + " << p[0][1] << " + " << p[0][2] << endl;
			out << "\nTruth table for maxterm 0\n\n";
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
									if(x == 1 || y == 1 || z == 1)
									{
										status2 = true;
									}
									else
									{
										status2 = false;
									}
									//Displaying the value of the last column of the OR table for each row
									out << status2 << endl;
									
									
								}
						}
				}
			break;
		case 1:
			//Displaying the minterm value for the desired rwo and Formatting the output file how the instructions told me to
			out << "\nM1 = " << p[1][0] << " + " << p[1][1] << " + " << p[1][2] << endl;
			out << "\nTruth table for maxterm 1\n\n";
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
									if(x == 1 || y == 1 || z == 0)
									{
										status2 = true;
									}
									else
									{
										status2 = false;
									}
									//Displaying the value of the last column of the OR table for each row
									out << status2 << endl;
									
									
								}
						}
				}
			break;
		case 2:
			//Displaying the minterm value for the desired rwo and Formatting the output file how the instructions told me to
			out << "\nM2 = " << p[2][0] << " + " << p[2][1] << " + " << p[2][2] << endl;
			out << "\nTruth table for maxterm 2\n\n";
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
									bool a = i;
									bool b = j;
									bool c = g;
									
									//If-Else statement to meet the conditions of an OR gate
									if(a == 1 || b == 0 || c == 1)
									{
										status2 = true;
									}
									else
									{
										status2 = false;
									}
									//Displaying the value of the last column of the OR table for each row
									out << status2 << endl;
									
									
								}
						}
				}
			break;
		case 3:
			//Displaying the minterm value for the desired rwo and Formatting the output file how the instructions told me to
			out << "\nM3 = " << p[3][0] << " + " << p[3][1] << " + " << p[3][2] << endl;
			out << "\nTruth table for maxterm 3\n\n";
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
									if(x == 1 || y == 0 || z == 0)
									{
										status2 = true;
									}
									else
									{
										status2 = false;
									}
									//Displaying the value of the last column of the OR table for each row
									out << status2 << endl;
									
									
								}
						}
				}
			break;
		case 4:
			//Displaying the minterm value for the desired rwo and Formatting the output file how the instructions told me to
			out << "\nM4 = " << p[4][0] << " + " << p[4][1] << " + " << p[4][2] << endl;
			out << "\nTruth table for maxterm 4\n\n";
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
									if(x == 0 || y == 1 || z == 1)
									{
										status2 = true;
									}
									else
									{
										status2 = false;
									}
									//Displaying the value of the last column of the OR table for each row
									out << status2 << endl;
									
									
								}
						}
				}
			break;
		case 5:
			//Displaying the minterm value for the desired rwo and Formatting the output file how the instructions told me to
			out << "\nM5 = " << p[5][0] << " + " << p[5][1] << " + " << p[5][2] << endl;
			out << "\nTruth table for maxterm 5\n\n";
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
									if(x == 0 || y == 1 || z == 0)
									{
										status2 = true;
									}
									else
									{
										status2 = false;
									}
									//Displaying the value of the last column of the OR table for each row
									out << status2 << endl;
									
									
								}
						}
				}
			break;
		case 6:
			//Displaying the minterm value for the desired rwo and Formatting the output file how the instructions told me to
			out << "\nM6 = " << p[6][0] << " + " << p[6][1] << " + " << p[6][2] << endl;
			out << "\nTruth table for maxterm 6\n\n";
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
									if(x == 0 || y == 0 || z == 1)
									{
										status2 = true;
									}
									else
									{
										status2 = false;
									}
									//Displaying the value of the last column of the OR table for each row
									out << status2 << endl;
									
									
								}
						}
				}
			break;
		case 7:
			//Displaying the minterm value for the desired rwo and Formatting the output file how the instructions told me to
			out << "\nM7 = " << p[7][0] << " + " << p[7][1] << " + " << p[7][2] << endl;
			out << "\nTruth table for maxterm 7\n\n";
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
									if(x == 0 || y == 0 || z == 0)
									{
										status2 = true;
									}
									else
									{
										status2 = false;
									}
									//Displaying the value of the last column of the OR table for each row
									out << status2 << endl;
									
									
								}
						}
				}
			break;
		}

}