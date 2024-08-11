#include <iostream>
#include <cmath>
#include <random>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	//Telling the user what the program is going to be about.
	cout << "ECE 0301 Propositional Logic Example\n" << endl;
	
	//Declaring the string variables for the logic statements.
	string P1, P2, P3;
	
	//Telling the users what statements we are going to use for the examples.
	cout << "P1: Pigs can fly.\nP2: Earth is flat.\nP3: The moon is cheese.\n" << endl;
	
	//Declaring Bool variables to assign each variable to either a 0 or a 1.
	bool P1B, P2B, P3B;
	
	//First statement's value is being obtained from the user.
	cout << "Enter P1 truth value: ";
	cin >> P1B;
	
	//Second statement's value is being obtained from the user.
	cout << "Enter P2 truth value: ";
	cin >> P2B;

	//Third statement's value is being obtained from the user.
	cout << "Enter P3 truth value: ";
	cin >> P3B;
	
	//Telling the users what the number they entered above translates to in Boolean language.
	cout << "\nYou entered: P1 = " << boolalpha << P1B << ", P2 = " << boolalpha << P2B << ", P3 = " << boolalpha << P3B << "." << endl;

	//Declaring another variable for a given statement.
	bool P4B;
	
			//Setting up an if-else loop for the statement given compared to the P1, P2, P3 statement.
			if(P1B == 1 && P2B == 0 && P3B == 1)
			{
				P4B = 1;
			}
			else
			{
				P4B = 0;
			}
	
	//Making an organized table with all of the Propositions and the corresponding Truth Values.
	cout << "\nTruth Table:\nProposition\tTruth Value\n-----------\t-----------\nP1\t\t" << boolalpha << P1B << "\nP2\t\t" << boolalpha << P2B << "\nP3\t\t" << boolalpha << P3B << "\nP4\t\t" << boolalpha << P4B << endl;

	//Declaring another variable for a given statement.
	bool P5B;
	
			//Setting up an if-else loop for the statement given compared to the P1, P2, P3 statement.
			if(P1B == 0 || P2B == 1 || P3B == 1)
			{
				P5B = 1;
			}
			else 
			{
				P5B = 0;
			}
			
	//Adding another row to the table for P5.
	cout << "P5\t\t" << boolalpha << P5B << endl;
	
	return 0;
}