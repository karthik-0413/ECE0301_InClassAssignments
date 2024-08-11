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
	
	//If program comes to this, then it ends with returning 0 back to the main function
	return 0;
}