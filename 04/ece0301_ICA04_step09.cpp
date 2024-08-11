//Karthik Raja
//ECE 0301
//In-Class Assignment 4

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
using namespace std;

int main()
{	
	//Declaring variables to check if the do-while loop would repeat or not.
	char again = 'y';
	
	//Variable to change the circuit number each iteration.
	int q = 0;
	
	//Defining an instream file to get values from a .txt file
		ifstream inputFile;
	
	//Opening the .txt file I would like to get values from
		inputFile.open("divider_wheatstone_circuits.txt");
	
	//Defining an ofstream file to transfer values to a .txt file
		ofstream outputFile;
		
	//Naming the .txt file I would like to write values in 
		outputFile.open("divider_wheatstone_solutions.txt");
	
	//Declaring variables as needed for the program
		string word;
	
	//Displaying the introductory statement to the user
		outputFile <<"ECE 0301: Circuit Solver for Voltage Divider\nand Wheatstone bridge example circuits.\n";

	//Delcaring all variables needed for the do-while loop
		double Vs, R1E;
		double R1, R2, user, user2, Is, Vs2, R1W, R2W, R3W, R4W, R5W;
		double j, g, h, s;
		double R5N, R4N, R3N, R2N, R1N;
		double V1, I1, V2, I2, V3, I3, V4, I4, V5, I5;
		double a, b, c, d, e, f, w, x, y, z;
		int n, TR, R2ND;
		double I, V1N, V2N;
		
	//Making a while that runs the program until again != 'y'
	while (again == 'y')
	{
		//This if statement checks to see if this input value is empty or not. If it is empty then it returns 0 and ends the program.
		if (inputFile >> word)
		{
			again = 'y';
		}
		else 
		{
			return 0;
		}
		
	

	//As instructed, if the word line does not say either DIVIDER or WHEATSTONE, then end the program with returning -1
	if(word != "Divider" && word != "Wheatstone")
	{
		cout << "ERROR! Invalid header." << endl;
		return -1;
	}

	//Making an if-else statement to see if the first word is Divider or Wheatstone
	if (word == "Divider")
		{
			
		//Adding q for every iteration
		q++;
		
		//Setting up the .txt file as instructed by the instructions
		outputFile << "-----\nCircuit #" << q << " (Voltage Divider)" << endl;
		
		//Inputting all of the values needed for Divider Circuit
		inputFile >> Vs;
		inputFile >> R1;
		inputFile >> R2;
		inputFile >> user;
		
		//Since, there are 2 resistors, we need 2 for loops to change each of them each iteration. 
		for (int i = 1; i <= user; i++)
		{
			//Multiplying R1 by i each iteration until it is equal to the user value.
			R1E = R1 * i;
			
			for (n = 1; n <= user; n++)
				{
					//Multiplies R2 value by j each iteration until it is equal to the user value.
					R2ND = R2 * n;
					
					//Displays Vs, R1, and R2 to the output file
					outputFile << "---\n";
					outputFile << "Source Voltage: Vs = " << Vs << " Volts." << endl;
					outputFile << "Resistor: R1 = " << R1E << " Ohms." << endl;
					outputFile << "Resistor: R2 = " << R2ND << " Ohms.\n" << endl;
					
					//Calculates total resistance, current, V1N, and V2N
					TR = R1E + R2ND;
					I = Vs / TR;
					V1N = R1E * I;
					V2N = R2ND * I;
					
					//Displaying the value of the current and the voltage in each resistor
					outputFile << "Loop current: I = " << I << " Amperes." << endl;
					outputFile << "Resistor voltage: V1 = " << V1N << " Volts." << endl;
					outputFile << "Resistor voltage: V2 = " << V2N << " Volts." << endl;
					
				}
		}
	}
	
	//Making an if-else statement to see if the first word is Divider or Wheatstone
	else
		{
		//Adding q every iteration
		q++;
		
		//Formatting on the instructions told us to
		outputFile << "-----\nCircuit #" << q << " (Wheatstone Bridge)" << endl;
		
		//Inputting all of the values needed for Wheatstone
		inputFile >> Vs2;
		inputFile >> Is;
		inputFile >> R1W;
		inputFile >> R2W;
		inputFile >> R3W;
		inputFile >> R4W;
		inputFile >> R5W;
		inputFile >> user2;	
		
	//Since, there are 5 resistors, we need 5 for loops to change each of them each iteration.
	for (int i = 1; i <= user2; i++)
	{
		//Multiplying R1E by the i value until it is equal to the user value.
		R1N = R1W * i;
		
		for (j = 1; j <= user2; j++)
		{
			//Multiplying R2E by the j value until it is equal to the user value.
			R2N = R2W * j;
			
			for (g = 1; g <= user2; g++)
			{
				//Multiplying R3 by the g value until it is equal to the user value.
				R3N = R3W * g;
				
				for (h = 1; h <= user2; h++)
				{
					//Multiplying R4 by the h value until it is equal to the user value.
					R4N = R4W * h;
					
					for (s = 1; s <= user2; s++)
					{
						//Multiplying R5 by the s value until it is equal to the user value.
						R5N = R5W * s;
						//cout << R1N << " " << R2N << " " << R3N << " " << R4N << " " << R5N << " " << endl; (Used this line to check if my for loop worked properly)
						
						//ERROR CHECKING to see if any of the given situations are met to be a divide-by-zero error and ending the program if any of the situations are met
						if (R2N == 0 || R3N == 0)
						{
							cout << "ERROR! Unstable floating-point division.\n";
							return -1;
						}
						
						//Declaring new variables to make calculations easier
						double t = Is * R4N;
						double o = Is * R5N;
						double l = Vs2 - t;
						double u = Vs2 + o;
						
						if (l > -exp(-13) && l < exp(-13))
						{
							cout << "ERROR! Unstable floating-point division.\n";
							return -1;
						}
						
						if (u > -exp(-13) && u < exp(-13))
						{
							cout << "ERROR! Unstable floating-point division.\n";
							return -1;
						}
						
						//Displaying the value for Vs, Is, and all of the resistors
						outputFile << "---\n";
						outputFile << "Source voltage: Vs = " << Vs2 << " Volts." << endl;
						outputFile << "Source current: Is = " << Is << " Amperes." << endl;
						outputFile << "Resistor: R1 = " << R1N << " Ohms.\n";
						outputFile << "Resistor: R2 = " << R2N << " Ohms.\n";
						outputFile << "Resistor: R3 = " << R3N << " Ohms.\n";
						outputFile << "Resistor: R4 = " << R4N << " Ohms.\n";
						outputFile << "Resistor: R5 = " << R5N << " Ohms.\n\n";
						
						//Used the given formulas to calculate for the voltage and current in each of the resistors
						a = 1 + (R4N/R2N);
						b = Vs2 - (Is * R4N);
						c = 1 + (R5N/R3N);
						d = Vs2 + (Is * R5N);
						e = R1N / R2N;
						f = R1N / R3N;
						
						//Solving for w, x, y, z using values of a, b, c, d, e, f
						w = (a + e) / b;
						x = f / b;
						y = e / d;
						z = (c + f) / d;
						
						//Calculating the voltage and current in each of the resistors
						V3 = (y - w) / ((x * y) - (w * z));
						I3 = V3 / R3N;
						V2 = (1 - (x * V3)) / w;
						I2 = V2 / R2N;
						V1 = (e * V2) + (f * V3);
						I1 = V1 / R1N;
						V4 = Vs2 - V1 - V2;
						I4 = V4 / R4N;
						V5 = Vs2 - V1 - V3;
						I5 = V5 / R5N;
						
						
						
						//Displaying the value for the calculated voltage and current in each resistor
						outputFile << "Resistor voltage: V1 = " << V1 << " Volts." << endl;
						outputFile << "Resistor current: I1 = " << I1 << " Amperes." << endl;
						
						outputFile << "Resistor voltage: V2 = " << V2 << " Volts." << endl;
						outputFile << "Resistor current: I2 = " << I2 << " Amperes." << endl;
					
						outputFile << "Resistor voltage: V3 = " << V3 << " Volts." << endl;
						outputFile << "Resistor current: I3 = " << I3 << " Amperes." << endl;
					
						outputFile << "Resistor voltage: V4 = " << V4 << " Volts." << endl;
						outputFile << "Resistor current: I4 = " << I4 << " Amperes." << endl;
					
						outputFile << "Resistor voltage: V5 = " << V5 << " Volts." << endl;
						outputFile << "Resistor current: I5 = " << I5 << " Amperes." << endl;
					}			
				}
			}
		}
		}
	}

		
	}
	
	//Closing the input file and the output file for good practice
	inputFile.close();
	outputFile.close();
	
	//If program comes to this, then it ends with returning 0 back to the main function
	return 0;
}