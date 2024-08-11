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
	int R1, R2;
	
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
		
		//Closing the inputFile as good practice
		inputFile.close();
		
		//Defining an ofstream file to transfer values to a .txt file
		ofstream outputFile;
		
		//Naming the .txt file I would like to write values in 
		outputFile.open("divider_wheatstone_solutions.txt");
		
		//Displaying the introductory statement to the user
		outputFile <<"ECE 0301: Circuit Solver for Voltage Divider\nand Wheatstone bridge example circuits.\n";
		
		//Setting up the .txt file as instructed by the instructions
		outputFile << "-----\nCircuit #1 (Voltage Divider)\n---" << endl;
		
		//Displaying the value of the voltage source and each resistor
		outputFile << "Source Voltage: Vs = " << Vs << " Volts.\n";
		outputFile << "Resistor: R1 = " << R1 << " Ohms.\n";
		outputFile << "Resistor: R2 = " << R2 << " Ohms.\n\n";
		
		//Declaring variables to find the current and the voltage in each resistor
		double current;
		double V1, V2;
		
		//Solving for the current and the voltage in each resistor
		current = Vs / (R1 + R2);
		V1 = R1 * current;
		V2 = R2 * current;
		
		//Displaying the value of the current and the voltage in each resistor
		outputFile << "Loop current: I = " << current << " Amperes." << endl;
		outputFile << "Resistor voltage: V1 = " << V1 << " Volts." << endl;
		outputFile << "Resistor voltage: V2 = " << V2 << " Volts." << endl;
		
		//Closing the outputFile as good practice
		outputFile.close();
	}
	
	//Making an if-else statement to see if the first word is Divider or Wheatstone
	else
	{
		//Declaring variables in order to read in numbers from a .txt file
		double R1, R2, R3, R4, R5;
		double Vs, Is;
		
		//Reading in values from a .txt file line by line and putting them declared variables
		inputFile >> Vs;
		inputFile >> Is;
		inputFile >> R1;
		inputFile >> R2;
		inputFile >> R3;
		inputFile >> R4;
		inputFile >> R5;
		
		//Closing the inputFile as good practice
		inputFile.close();
		
		//Defining an ofstream file to transfer values to a .txt file
		ofstream outputFile;
	
		//Naming the .txt file I would like to write values in 
		outputFile.open("divider_wheatstone_solutions.txt");
		
		//Displaying the introductory statement to the user
		outputFile <<"ECE 0301: Circuit Solver for Voltage Divider\nand Wheatstone bridge example circuits.\n";
		
		//Setting up the .txt file as instructed by the instructions
		outputFile << "-----\nCircuit #1 (Wheatstone Bridge)\n---" << endl;
	
		//Displaying the value of the voltage source, current source, and each resistor
		outputFile << "Source voltage: Vs = " << Vs << " Volts.\n";
		outputFile << "Source current: Is = " << Is << " Amperes.\n";
		outputFile << "Resistor: R1 = " << R1 << " Ohms.\n";
		outputFile << "Resistor: R2 = " << R2 << " Ohms.\n";
		outputFile << "Resistor: R3 = " << R3 << " Ohms.\n";
		outputFile << "Resistor: R4 = " << R4 << " Ohms.\n";
		outputFile << "Resistor: R5 = " << R5 << " Ohms.\n\n";
		
		//Declaring variables to calculate the voltage and current in each of the resistors
		double V1, I1, V2, I2, V3, I3, V4, I4, V5, I5;
		
		double a, b, c, d, e, f, w, x, y, z;
		
		//Using the formulas given to us to find voltage and current in each of the resistors
		a = 1 + (R4/R2);
		b = Vs - (Is * R4);
		c = 1 + (R5/R3);
		d = Vs + (Is * R5);
		e = R1 / R2;
		f = R1 / R3;
		
		//Solving for w, x, y, z using values of a, b, c, d, e, f
		w = (a + e) / b;
		x = f / b;
		y = e / d;
		z = (c + f) / d;
		
		//Calculating the voltage and current in each of the resistors
		V3 = (y - w) / ((x * y) - (w * z));
		I3 = V3 / R3;
		V2 = (1 - (x * V3)) / w;
		I2 = V2 / R2;
		V1 = (e * V2) + (f * V3);
		I1 = V1 / R1;
		V4 = Vs - V1 - V2;
		I4 = V4 / R4;
		V5 = Vs - V1 - V3;
		I5 = V5 / R5;
		
		//ERROR CHECKING to see if any of the given situations are met to be a divide-by-zero error and ending the program if any of the situations are met
		if (R2 == 0 || R3 == 0)
		{
			cout << "ERROR! Unstable floating-point division.\n";
			return -1;
		}

		//Declaring new variables to make calculations easier
		double h = Is * R4;
		double r = Is * R5;
		double j = Vs - h;
		double k = Vs + r;
		
		if (j > -exp(-13) && j < exp(-13))
		{
			cout << "ERROR! Unstable floating-point division.\n";
			return -1;
		}
		
		if (k > -exp(-13) && k < exp(-13))
		{
			cout << "ERROR! Unstable floating-point division.\n";
			return -1;
		}
		
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
	
		//Closing the outputFile as good practice
		outputFile.close();
	
	}
	//If program comes to this, then it ends with returning 0 back to the main function
	return 0;
}