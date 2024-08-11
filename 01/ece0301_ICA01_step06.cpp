// Karthik Raja
// In-Class Assignment 1

#include <iostream>
using namespace std;

int main()
{
	//Typing the statement that is going to be in the beginning of the program.
	cout << "ECE 0301 DC Resistive Circuit Simulation\nModeled after www.falstad.com/circuit/\nCircuits -> Basics -> Ohm's Law\n";
	
	//Declaring my variables my the voltage and the two resistors.
	double V = 120, R1 = 10, R2 = 15;
	
	//Showing the user what the value of the voltage source is.
	cout << "Vs = " << V << " Volts" << endl;
	
	//Showing the user what the value of the two resistors are.
	cout << "R1 = " << R1 << " Ohms" << "\nR2 = " << R2 << " Ohms" << endl;
	
	//Declaring the variables that will calculate the current and the power of the circuit with the first resistor.
	double I1 = V / R1, P1 = (V * V) / R1;
	
	//Showing the user what the current and power are.
	cout << "I1 = " << I1 << " Amperes" << endl;
	cout << "P1 = " << P1 << " Watts" << endl;
	
	//Declaring the variables that will calculate the current and the power of the circuit with the second resistor.
	double I2 = V / R2, P2 = (V * V) / R2;
	
	//Showing the user what the current and power are.
	cout << "I2 = " << I2 << " Amperes" << endl;
	cout << "P2 = " << P2 << " Watts" << endl;
	
	//Declaring the time (in seconds) and the amount of energy supplied variables.
	double T1 = 1, T2 = 3600, T3 = 3600 * 24, T4 = 3600 * 365 * 24,
			J1 = (P1+P2) * T1, J2 = (P1+P2) * T2, J3 = (P1+P2) * T3, J4 = (P1+P2) * T4;
	
	//Showing the user how much energy was supplied in one second, one hour, one day, and in one year.
	cout << "Energy supplied in one second = " << J1 << " Joules" << endl;
	cout << "Energy supplied in one hour = " << J2 << " Joules" << endl;
	cout << "Energy supplied in one day = " << J3 << " Joules" << endl;
	cout << "Energy supplied in one year = " << J4 << " Joules" << endl;
	
	//Declaring the variables, which will help us calculate how much electricty is used every second, every hour, every day, and every year.
	double kWsec1 = J1 / 3600000 * 0.10;
	// 3600000 is used due to the fact that 1000*3600 is 3600000. I used 1000 to convert W to KW and 3600 to convert hours to seconds. 
	double kWhour2 = J2 / 3600000 * 0.10;
	double kWday3 = J3 / 3600000 * 0.10;
	double kWyear4 = J4 / 3600000 * 0.10;
	
	//Showing the user how much electricty is used every second, every hour, every day, and every year.
	cout << "Cost of supplying energy for one second at $0.10/kWh = $" << kWsec1 << endl;
	cout << "Cost of supplying energy for one hour at $0.10/kWh = $" << kWhour2 << endl;
	cout << "Cost of supplying energy for one day at $0.10/kWh = $" << kWday3 << endl;
	cout << "Cost of supplying energy for one year at $0.10/kWh = $" << kWyear4 << endl;
	
	//Telling the program to exit the program if reached to this stage.
	return 0;
}