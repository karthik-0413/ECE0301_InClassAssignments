#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	//Declaring needed variables
	double num1, num2, num3, num4, Radius, Theta, x, y;
	string user, user2;
	
	//Displaying introductory statement to user and asking them to enter two numbers
	cout << "ECE 0301 - Vectors in R2 and Complex Numbers\nPlease enter two numbers, seperated by a space,\nthat will represent a vector or a complex number.\n\n";
	cin >> num1 >> num2;
	
	//Telling the user what numbers they entered with three decimal places
	cout << "You entered "<< fixed << setprecision(3) << num1 << " and " << num2 << "." << endl;
	
	//Asking the user if the numbers they entered represent polar or cartesian coordinates
	cout << "\nAre these numbers in Cartesian (C) or polar (p) coordinates?\nPlease enter a single character as your choice." << endl;
	cin >> user;
	
	//Error checking if the user entered the correct character corresponding with the question asked and displaying error message if wrong value was entered
	if (user != "p" && user != "P" && user != "c" && user != "C")
		{
			cout << "ERROR! Invalid selection, exiting." << endl;
			
			//Ending the program if the user entered invalid character
			return -1;
		}
	
	//Making an if-else statement to see if the user entered numbers for a polar coordinate or cartesian coordinate
	if(user == "p" || user == "P")
	{
		//Checking that if the radius is less than zero then the program has to end
		if (num1 < 0)
		{
			cout << "You entered Polar coordinates." << endl;
			cout << "\nERROR! Invalid polar coordinates, exiting." << endl;
			return -1;
		}
		//Checking that if the theta value that the user entered is between -pi and +pi. If not, then program ends
		if (num2 > 3.14159 || num2 < -3.14159)
		{
			cout << "You entered Polar coordinates." << endl;
			cout << "ERROR! Invalid polar coordinates, exiting." << endl;
			return -1;
		}
		
		//If the radius is greater than or equal to zero, then the program continues by calculating what the equivalent cartesian coordinates are for the entered polar coorindates
		cout << "You entered Polar coordinates." << endl;
		x = num1 * (cos(num2));
		y = num1 * (sin(num2));
		cout << "The equivalent Cartesian coordinates are: \nx = " << fixed << setprecision(3) << x << ", y = " << y << endl;
		
	}
	else
	{
		
		//If angle is between -pi and +pi, then the program continues to calculate the equivalent cartesian coordinate for the entered polar values.
		cout << "You entered Cartesian coordinates." << endl;
		Radius = sqrt((num1 * num1) + (num2 * num2));
		
		//The following if-else loop is for the different situations to find theta depend on what the entered x and y values were and displaying it to user.
		if (num1 >=0)
		{
			Theta = atan(num2 / num1);
		}
		else if (num1 < 0 && num2 >=0)
		{
			Theta = atan(num2 / num1) + 3.14159;
		}
		else
		{
			Theta = atan(num2 / num1) - 3.14159;
		}
		cout << "The equivalent Polar coordinates are: \n" << "R = " << fixed << setprecision(3) << Radius << ", theta = " << Theta << endl;
	}
	
	
	
	// Second round of asking users numbers
	cout << "Please enter another pair of number, spearated by a\nspace, to represent a second vector or complex number.\n\n";
	cin >> num3 >> num4;
	
	//Telling the user what numbers they entered with three decimal places
	cout << "You entered "<< fixed << setprecision(3) << num3 << " and " << num4 << "." << endl;
	
	//Asking the user if the numbers they entered represent polar or cartesian coordinates
	cout << "\nAre these numbers in Cartesian (C) or polar (p) coordinates?\nPlease enter a single character as your choice." << endl;
	cin >> user2;
	
	//Error checking if the user entered the correct character corresponding with the question asked and displaying error message if wrong value was entered
	if (user2 != "p" && user2 != "P" && user2 != "c" && user2 != "C")
		{
			cout << "ERROR! Invalid selection, exiting." << endl;
			
			//Ending the program if the user entered invalid character
			return -1;
		}
	
	//Making an if-else statement to see if the user entered numbers for a polar coordinate or cartesian coordinate
	if(user2 == "p" || user2 == "P")
	{
		//Checking that if the radius is less than zero then the program has to end
		if (num3 < 0)
		{
			cout << "You entered Polar coordinates." << endl;
			cout << "ERROR! Invalid polar coordinates, exiting." << endl;
			return -1;
		}
		//Checking that if the theta value that the user entered is between -pi and +pi. If not, then program ends
		if (num4 > 3.14159 || num4 < -3.14159)
		{
			cout << "You entered Polar coordinates." << endl;
			cout << "ERROR! Invalid polar coordinates, exiting." << endl;
			return -1;
		}
		
		//If the radius is greater than or equal to zero, then the program continues by calculating what the equivalent cartesian coordinates are for the entered polar coorindates
		cout << "You entered Polar coordinates." << endl;
		x = num3 * (cos(num4));
		y = num3 * (sin(num4));
		cout << "The equivalent Cartesian coordinates are: \nx = " << fixed << setprecision(3) << x << ", y = " << y << endl;
		
	}
	else
	{
		
		//If angle is between -pi and +pi, then the program continues to calculate the equivalent cartesian coordinate for the entered polar values.
		cout << "You entered Cartesian coordinates." << endl;
		Radius = sqrt((num3 * num3) + (num4 * num4));
		
		//The following if-else loop is for the different situations to find theta depend on what the entered x and y values were and displaying it to user. 
		if (num3 >=0)
		{
			Theta = atan(num4 / num3);
		}
		else if (num3 < 0 && num4 >=0)
		{
			Theta = atan(num4 / num3) + 3.14159;
		}
		else
		{
			Theta = atan(num4 / num3) - 3.14159;
		}
		cout << "The equivalent Polar coordinates are: \n" << "R = " << fixed << setprecision(3) << Radius << ", theta = " << Theta << endl << endl;
	}

	return 0;
}