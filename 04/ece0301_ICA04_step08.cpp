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
	//Defining an instream file to get values from a .txt file
	ifstream inputFile;
	
	//Declaring variables as needed for the program
	string word;
	double Vs;
	int R1, R2, user;
	
	//Opening the .txt file I would like to get values from
	inputFile.open("divider_wheatstone_circuits.txt");
	
	//Obtaining the first line of the .txt file
	inputFile >> word;
	
	//As instructed, if the word line does not say either DIVIDER or WHEATSTONE, then end the program with returning -1
	if(word != "Divider" && word != "Wheatstone")
	{
		cout << "ERROR! Invalid header." << endl;
		return -1;
	}
	
	//Making an if-else statement to see if the first word is Divider or Wheatstone
	if (word == "Divider")
		{
		//Getting the second, third, and fourth line of the input file and putting them in already declared variables
		inputFile >> Vs;
		inputFile >> R1;
		inputFile >> R2;
		inputFile >> user;
		
		//Closing the inputFile as good practice
		inputFile.close();
		
		//Defining an ofstream file to transfer values to a .txt file
		ofstream outputFile;
		
		//Naming the .txt file I would like to write values in 
		outputFile.open("divider_wheatstone_solutions.txt");
		
		//Displaying the introductory statement to the user
		outputFile <<"ECE 0301: Circuit Solver for Voltage Divider\nand Wheatstone bridge example circuits.\n";
		
		//Setting up the .txt file as instructed by the instructions
		outputFile << "-----\nCircuit #1 (Voltage Divider)" << endl;
		
		//Declaring needed variables for DIVIDER for loop
		int B1 = R1, j, TR, R2N;
		double I, V1N, V2N;
		
		//Since, there are 2 resistors, we need 2 for loops to change each of them each iteration. 
		for (int i = 1; i <= user; i++)
		{
			for (j = 1; j <= user; j++)
				{
					//Multiplies R2 value by j each iteration until it is equal to the user value. 
					R2N = R2 * j;
					
					//Displays Vs, R1, and R2 to the output file
					outputFile << "---\n";
					outputFile << "Source Voltage: Vs = " << Vs << " Volts." << endl;
					outputFile << "Resistor: R1 = " << R1 << " Ohms." << endl;
					outputFile << "Resistor: R2 = " << R2N << " Ohms.\n" << endl;
					
					//Calculates total resistance, current, V1N, and V2N
					TR = R1 + R2N;
					I = Vs / TR;
					V1N = R1 * I;
					V2N = R2N * I;
					
					//Displaying the value of the current and the voltage in each resistor
					outputFile << "Loop current: I = " << I << " Amperes." << endl;
					outputFile << "Resistor voltage: V1 = " << V1N << " Volts." << endl;
					outputFile << "Resistor voltage: V2 = " << V2N << " Volts." << endl;
					
				}
					//Resetting R1 to be original value each time j == user, since that is when R1 is supposed to be multipled by i.
					R1 += B1;
					
					if (j == user)
					{
						R1 = B1;
					}
		}
		
		//Closing output file for good practice
		outputFile.close();
	
	}
	//Making an if-else statement to see if the first word is Divider or Wheatstone
	else
	{
		//Declaring variables in order to read in numbers from a .txt file
		double R1E, R2E, R3, R4, R5;
		double Vs, Is;
		
		//Reading in values from a .txt file line by line and putting them declared variables
		inputFile >> Vs;
		inputFile >> Is;
		inputFile >> R1E;
		inputFile >> R2E;
		inputFile >> R3;
		inputFile >> R4;
		inputFile >> R5;
		inputFile >> user;
		
		//Closing the inputFile as good practice
		inputFile.close();
		
		//Defining an ofstream file to transfer values to a .txt file
		ofstream outputFile;
	
		//Naming the .txt file I would like to write values in 
		outputFile.open("divider_wheatstone_solutions.txt");
		
		//Displaying the introductory statement to the user
		outputFile <<"ECE 0301: Circuit Solver for Voltage Divider\nand Wheatstone bridge example circuits.\n";
		
		//Setting up the .txt file as instructed by the instructions
		outputFile << "-----\nCircuit #1 (Wheatstone Bridge)" << endl;
	
	//Declaring needed variables to calculate the voltage and current in each resistor
	double j, g, h, s;
	double R5N = R5, R4N = R4, R3N = R3, R2N = R2E, R1N = R1E;
	double V1, I1, V2, I2, V3, I3, V4, I4, V5, I5;
		
	double a, b, c, d, e, f, w, x, y, z;
	
	//Since, there are 5 resistors, we need 5 for loops to change each of them each iteration. 
	for (int i = 1; i <= user; i++)
	{
		//Multiplying R1E by the i value until it is equal to the user value.
		R1N = R1E * i;
		
		for (j = 1; j <= user; j++)
		{
			//Multiplying R2E by the j value until it is equal to the user value.
			R2N = R2E * j;
			
			for (g = 1; g <= user; g++)
			{
				//Multiplying R3 by the g value until it is equal to the user value.
				R3N = R3 * g;
				
				for (h = 1; h <= user; h++)
				{
					//Multiplying R4 by the h value until it is equal to the user value.
					R4N = R4 * h;
					
					for (s = 1; s <= user; s++)
					{
						//Multiplying R5 by the s value until it is equal to the user value.
						R5N = R5 * s;
						//cout << R1N << " " << R2N << " " << R3N << " " << R4N << " " << R5N << " " << endl; (Used this line to check if my for loop worked properly)
						
						//Used the given formulas to calculate for the voltage and current in each of the resistors
						a = 1 + (R4N/R2N);
						b = Vs - (Is * R4N);
						c = 1 + (R5N/R3N);
						d = Vs + (Is * R5N);
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
						V4 = Vs - V1 - V2;
						I4 = V4 / R4N;
						V5 = Vs - V1 - V3;
						I5 = V5 / R5N;
						
						//Displaying the value for Vs, Is, and all of the resistors
						outputFile << "---\n";
						outputFile << "Source voltage: Vs = " << Vs << " Volts." << endl;
						outputFile << "Source current: Is = " << Is << " Amperes." << endl;
						outputFile << "Resistor: R1 = " << R1N << " Ohms.\n";
						outputFile << "Resistor: R2 = " << R2N << " Ohms.\n";
						outputFile << "Resistor: R3 = " << R3N << " Ohms.\n";
						outputFile << "Resistor: R4 = " << R4N << " Ohms.\n";
						outputFile << "Resistor: R5 = " << R5N << " Ohms.\n\n";
						
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
		
		//ERROR CHECKING to see if any of the given situations are met to be a divide-by-zero error and ending the program if any of the situations are met
		if (R2E == 0 || R3 == 0)
		{
			cout << "ERROR! Unstable floating-point division.\n";
			return -1;
		}
		
		//Declaring new variables to make calculations easier
		double t = Is * R4;
		double o = Is * R5;
		double l = Vs - t;
		double u = Vs + o;
		
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
	
		//Closing the outputFile as good practice
		outputFile.close();
	
	}
	//If program comes to this, then it ends with returning 0 back to the main function
	return 0;
}