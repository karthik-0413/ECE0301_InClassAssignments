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
	string P1 = "Pigs can fly.", P2 = "Earth is flat.", P3 = "The moon is cheese.";
	
	//Telling the users what statements we are going to use for the examples.
	cout << "P1: " << P1 << "\nP2: " << P2 << "\nP3: " << P3 << "\n" << endl;
	
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
			
	//Adding a row to the truth table for P5B.		
	cout << "P5\t\t" << boolalpha << P5B << endl;
	
	//Declaring another bool variable for another statement given.
	bool P6B;
	
			//Since the statement given said that P6B would be true only if one of the statements above are true, the Boolean values would have to add up to 1.
			if(P1B + P2B + P3B == 1)
			{
				P6B = 1;
			}
			else 
			{
				P6B = 0;
			}	
	
	//Adding a row to the truth table for P6B.
	cout << "P6\t\t" << boolalpha << P6B << endl;
	
	//Declaring another bool variable for another statement given.
	bool P7B;
			
			//Since the statement given said that P6B would be true only if none of the statements above are true, the Boolean Values would have to add up to 0.
			if(P1B + P2B + P3B == 0)
			{
				P7B = 1;
			}
			else 
			{
				P7B = 0;
			}	
	
	//Adding a row to the truth table for P7B.
	cout << "P7\t\t" << boolalpha << P7B << endl;
	
	//Declaring another bool variable for another statement given.
	bool P8B;
			
			//Since the statement given said that P6B would be true only if two of the statements above are true, the Boolean Values would have to add up to 2.
			if(P1B + P2B + P3B == 2 || P1B + P2B + P3B == 3)
			{
				P8B = 1;
			}
			else 
			{
				P8B = 0;
			}	
	
	//Adding a row to the truth table for P8B.
	cout << "P8\t\t" << boolalpha << P8B << endl;
	
	//Declaring another bool variable for another statement given.
	bool P9B;
	
			//Setting up an if-else loop to be the same as the statement given. 
			if(P1B == 0 && ((P2B == 1 && P3B == 0)||(P2B == 0 && P3B == 1)))
			{
				P9B = 1;
			}
			else
			{
				P9B = 0;
			}
	//Adding a row to the truth table for P9B.
	cout << "P9\t\t" << boolalpha << P9B << endl;
	
	return 0;
}