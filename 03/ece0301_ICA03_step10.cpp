#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	//Declaring needed variables
	double num1, num2, num3, num4, Radius, Theta, Radius2, Theta2, x, y, x2, y2;
	string user, user2, user5;
	
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
		
		//The following if-else loop is for the different situations to find theta depend on what the entered x and y values were.
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
		x2 = num3 * (cos(num4));
		y2 = num3 * (sin(num4));
		cout << "The equivalent Cartesian coordinates are: \nx = " << fixed << setprecision(3) << x2 << ", y = " << y2 << endl;
		
	}
	else
	{
		
		//If angle is between -pi and +pi, then the program continues to calculate the equivalent cartesian coordinate for the entered polar values.
		cout << "You entered Cartesian coordinates." << endl;
		Radius2 = sqrt((num3 * num3) + (num4 * num4));
		
		//The following if-else loop is for the different situations to find theta depend on what the entered x and y values were and displaying it to user.
		if (num3 >=0)
		{
			Theta2 = atan(num4 / num3);
		}
		else if (num3 < 0 && num4 >=0)
		{
			Theta2 = atan(num4 / num3) + 3.14159;
		}
		else
		{
			Theta2 = atan(num4 / num3) - 3.14159;
		}
		cout << "The equivalent Polar coordinates are: \n" << "R = " << fixed << setprecision(3) << Radius2 << ", theta = " << Theta2 << endl << endl;
	}

	
	//Declaring another string variable to allow to user to choose if they want vectors or complex numbers.
	string user7;
	
	//Asking users if they want vectors or complex numbers.
	cout << "Do the values you entered represent vectors (v) or complex numbers (c)?\nPlease enter a single character as your choice." << endl;
	cin >> user7;
	
	//Error checking if the user entered the correct character corresponding with the question asked and displaying error message if wrong value was entered
	if (user7 != "v" && user7 != "V" && user7 != "c" && user7 != "C")
		{
			cout << "ERROR! Invalid selection, exiting." << endl;
			
			//Ending the program if the user entered invalid character
			return -1;
		}
	
	//Declaring an integer variable to allow to users to choose which operation they wish to do.
	int user3;
	
	//Making an if-else statement to see if the user entered numbers for a polar coordinate or cartesian coordinate both times and to see if they want to represent vector or complex numbers.
	if((user7 == "v" || user7 == "V") && (user == "P" || user == "p") && (user2 == "c" || user2 == "C"))
	{
		//Displaying both pairs of numbers in both cartesian and polar form formatted for vectors
		cout << "Cartesian:\tv1 = (" << fixed << setprecision(3) << x << ", " << y << ")" << endl;
		cout << "Polar:\t\tv1 = (" << fixed << setprecision(3) << num1 << ", " << num2 << ")" << endl;

		cout << "\nCartesian:\tv2 = (" << fixed << setprecision(3) << num3 << ", " << num4 << ")" << endl;
		cout << "Polar:\t\tv2 = (" << fixed << setprecision(3) << Radius2 << ", " << Theta2 << ")" << endl;
		
		//Asking the user which operation they want to perform and reading their answer in the variable user3.
		cout << "\nWhich of the following vector sums or differences\nwould you life to compute?" << endl;
		cout << "1. v1 + v2" << endl;
		cout << "2. v1 - v2" << endl;
		cout << "3. v2 - v1" << endl;
		cout << "4. -v1 - v2\n" << endl;
		cin >> user3;
		
		//Error checking That the user entered the correct number value corresponding to the operation number.
		if (user3 > 4 || user3 < 1)
		{
			cout << "ERROR! Invalid selection, exiting." << endl;
			
			//Ending the program if the user entered invalid character
			return -1;
		}
		
		//Declaring four variables for the four separate operation we have to do for each case.
		double sum1, sum2, sum3, sum4;
		
		//Making a switch case for each case of the operation using the user3 variable
		switch (user3)
		{
			//First case is v1 + v2
			case 1:
				sum1 = num3 + x;
				sum2 = num4 + y;
				sum3 = num1 + Radius;
				sum4 = num2 + Theta;
				cout <<"Sum, Cartesian:\tv_sum = (" << sum1 << ", " << sum2  << ")" << endl;
				cout <<"Sum, Polar:\tv_sum = (" <<  sum3 << ", " << sum4  << ")" << endl;
				break;
			//Second case is v1 - v2
			case 2:
				sum1 = x - num3;
				sum2 = y - num4;
				sum3 = num1 - Radius;
				sum4 = num2 - Theta;
				cout <<"Sum, Cartesian:\tv_sum = (" << sum1 << ", " << sum2  << ")" << endl;
				cout <<"Sum, Polar:\tv_sum = (" <<  sum3 << ", " << sum4  << ")" << endl;
				break;
			//Third case is v2 - v1
			case 3:
				sum1 = num3 - x;
				sum2 = num4 - y;
				sum3 = Radius - num1;
				sum4 = Theta - num2;
				cout <<"Sum, Cartesian:\tv_sum = (" << sum1 << ", " << sum2  << ")" << endl;
				cout <<"Sum, Polar:\tv_sum = (" <<  sum3 << ", " << sum4  << ")" << endl;
				break;
			//Fourth case is -v1 - v2
			case 4:
				sum1 = -x - num3;
				sum2 = -y - num4;
				sum3 = -num1 - Radius;
				sum4 = -num2 - Theta;
				cout <<"Sum, Cartesian:\tv_sum = (" << sum1 << ", " << sum2  << ")" << endl;
				cout <<"Sum, Polar:\tv_sum = (" <<  sum3 << ", " << sum4  << ")" << endl;
				break;
		}
	}
	//Making an if-else statement to see if the user entered numbers for a polar coordinate or cartesian coordinate both times and to see if they want to represent vector or complex numbers.
	else if (((user7 == "v" || user7 == "V") && (user == "P" || user == "p") && (user2 == "p" || user2 == "P")))
	{
		//Displaying both pairs of numbers in both cartesian and polar form formatted for vectors
		cout << "Cartesian:\tv1 = (" << fixed << setprecision(3) << x << ", " << y << ")" << endl;
		cout << "Polar:\t\tv1 = (" << fixed << setprecision(3) << num1 << ", " << num2 << ")" << endl;

		cout << "\nCartesian:\tv2 = (" << fixed << setprecision(3) << x2 << ", " << y2 << ")" << endl;
		cout << "Polar:\t\tv2 = (" << fixed << setprecision(3) << num3 << ", " << num4 << ")" << endl;
		
		//Asking the user which operation they want to perform and reading their answer in the variable user3.
		cout << "\nWhich of the following vector sums or differences\nwould you life to compute?" << endl;
		cout << "1. v1 + v2" << endl;
		cout << "2. v1 - v2" << endl;
		cout << "3. v2 - v1" << endl;
		cout << "4. -v1 - v2\n" << endl;
		cin >> user3;
		
		//Error checking That the user entered the correct number value corresponding to the operation number.
		if (user3 > 4 || user3 < 1)
		{
			cout << "ERROR! Invalid selection, exiting." << endl;
			
			//Ending the program if the user entered invalid character
			return -1;
		}
		
		//Declaring four variables for the four separate operation we have to do for each case.
		double sum1, sum2, sum3, sum4;
		
		//Making a switch case for each case of the operation using the user3 variable
		switch (user3)
		{
			//First case is v1 + v2
			case 1:
				sum1 = x2 + x;
				sum2 = y2 + y;
				sum3 = num1 + num3;
				sum4 = num2 + num4;
				cout <<"Sum, Cartesian:\tv_sum = (" << sum1 << ", " << sum2  << ")" << endl;
				cout <<"Sum, Polar:\tv_sum = (" <<  sum3 << ", " << sum4  << ")" << endl;
				break;
			//Second case is v1 - v2
			case 2:
				sum1 = x - x2;
				sum2 = y - y2;
				sum3 = num1 - num3;
				sum4 = num2 - num4;
				cout <<"Sum, Cartesian:\tv_sum = (" << sum1 << ", " << sum2  << ")" << endl;
				cout <<"Sum, Polar:\tv_sum = (" <<  sum3 << ", " << sum4  << ")" << endl;
				break;
			//Third case is v2 - v1
			case 3:
				sum1 = x2 - x;
				sum2 = y2 - y;
				sum3 = num3 - num1;
				sum4 = num4 - num2;
				cout <<"Sum, Cartesian:\tv_sum = (" << sum1 << ", " << sum2  << ")" << endl;
				cout <<"Sum, Polar:\tv_sum = (" <<  sum3 << ", " << sum4  << ")" << endl;
				break;
			//Fourth case is -v1 - v2
			case 4:
				sum1 = -x - x2;
				sum2 = -y - y2;
				sum3 = -num1 - num3;
				sum4 = -num2 - num4;
				cout <<"Sum, Cartesian:\tv_sum = (" << sum1 << ", " << sum2  << ")" << endl;
				cout <<"Sum, Polar:\tv_sum = (" <<  sum3 << ", " << sum4  << ")" << endl;
				break;
		}
	}
	
	//Making an if-else statement to see if the user entered numbers for a polar coordinate or cartesian coordinate both times and to see if they want to represent vector or complex numbers.
	
	else if (((user7 == "v" || user7 == "V") && (user == "C" || user == "c") && (user2 == "p" || user2 == "P")))
	{
		//Displaying both pairs of numbers in both cartesian and polar form formatted for vectors
		cout << "Cartesian:\tv1 = (" << fixed << setprecision(3) << num1 << ", " << num2 << ")" << endl;
		cout << "Polar:\t\tv1 = (" << fixed << setprecision(3) << Radius << ", " << Theta << ")" << endl;

		cout << "\nCartesian:\tv2 = (" << fixed << setprecision(3) << x2 << ", " << y2 << ")" << endl;
		cout << "Polar:\t\tv2 = (" << fixed << setprecision(3) << num3 << ", " << num4 << ")" << endl;
		
		//Asking the user which operation they want to perform and reading their answer in the variable user3.
		cout << "\nWhich of the following vector sums or differences\nwould you life to compute?" << endl;
		cout << "1. v1 + v2" << endl;
		cout << "2. v1 - v2" << endl;
		cout << "3. v2 - v1" << endl;
		cout << "4. -v1 - v2\n" << endl;
		cin >> user3;
		
		//Error checking That the user entered the correct number value corresponding to the operation number.
		if (user3 > 4 || user3 < 1)
		{
			cout << "ERROR! Invalid selection, exiting." << endl;
			
			//Ending the program if the user entered invalid character
			return -1;
		}
		
		//Declaring four variables for the four separate operation we have to do for each case.
		double sum1, sum2, sum3, sum4;
		
		//Making a switch case for each case of the operation using the user3 variable
		switch (user3)
		{
			//First case is v1 + v2
			case 1:
				sum1 = num1 + x2;
				sum2 = y2 + num2;
				sum3 = Radius + num3;
				sum4 = Theta + num4;
				cout <<"Sum, Cartesian:\tv_sum = (" << sum1 << ", " << sum2  << ")" << endl;
				cout <<"Sum, Polar:\tv_sum = (" <<  sum3 << ", " << sum4  << ")" << endl;
				break;
			//Second case is v1 - v2
			case 2:
				sum1 = num1 - x2;
				sum2 = num2 - y2;
				sum3 = Radius - num3;
				sum4 = Theta - num4;
				cout <<"Sum, Cartesian:\tv_sum = (" << sum1 << ", " << sum2  << ")" << endl;
				cout <<"Sum, Polar:\tv_sum = (" <<  sum3 << ", " << sum4  << ")" << endl;
				break;
			//Third case is v2 - v1
			case 3:
				sum1 = x2 - num1;
				sum2 = y2 - num2;
				sum3 = num3 - Radius;
				sum4 = num4 - Theta;
				cout <<"Sum, Cartesian:\tv_sum = (" << sum1 << ", " << sum2  << ")" << endl;
				cout <<"Sum, Polar:\tv_sum = (" <<  sum3 << ", " << sum4  << ")" << endl;
				break;
			//Fourth case is -v1 - v2
			case 4:
				sum1 = -num1 - x2;
				sum2 = -num2 - y2;
				sum3 = -Radius - num3;
				sum4 = -Theta - num4;
				cout <<"Sum, Cartesian:\tv_sum = (" << sum1 << ", " << sum2  << ")" << endl;
				cout <<"Sum, Polar:\tv_sum = (" <<  sum3 << ", " << sum4  << ")" << endl;
				break;
		}
	}
	
	
	//Making an if-else statement to see if the user entered numbers for a polar coordinate or cartesian coordinate both times and to see if they want to represent vector or complex numbers.
	
	else if (((user7 == "v" || user7 == "V") && (user == "C" || user == "c") && (user2 == "c" || user2 == "C")))
	{
		//Displaying both pairs of numbers in both cartesian and polar form formatted for vectors
		cout << "Cartesian:\tv1 = (" << fixed << setprecision(3) << num1 << ", " << num2 << ")" << endl;
		cout << "Polar:\t\tv1 = (" << fixed << setprecision(3) << Radius << ", " << Theta << ")" << endl;

		cout << "\nCartesian:\tv2 = (" << fixed << setprecision(3) << num3 << ", " << num4 << ")" << endl;
		cout << "Polar:\t\tv2 = (" << fixed << setprecision(3) << Radius2 << ", " << Theta2 << ")" << endl;
		
		//Asking the user which operation they want to perform and reading their answer in the variable user3.
		cout << "\nWhich of the following vector sums or differences\nwould you life to compute?" << endl;
		cout << "1. v1 + v2" << endl;
		cout << "2. v1 - v2" << endl;
		cout << "3. v2 - v1" << endl;
		cout << "4. -v1 - v2\n" << endl;
		cin >> user3;
		
		//Error checking That the user entered the correct number value corresponding to the operation number.
		if (user3 > 4 || user3 < 1)
		{
			cout << "ERROR! Invalid selection, exiting." << endl;
			
			//Ending the program if the user entered invalid character
			return -1;
		}
		
		//Declaring four variables for the four separate operation we have to do for each case.
		double sum1, sum2, sum3, sum4;
		
		//Making a switch case for each case of the operation using the user3 variable
		switch (user3)
		{
			//First case is v1 + v2
			case 1:
				sum1 = num1 + num3;
				sum2 = num4 + num2;
				sum3 = Radius + Radius2;
				sum4 = Theta + Theta2;
				cout <<"Sum, Cartesian:\tv_sum = (" << sum1 << ", " << sum2  << ")" << endl;
				cout <<"Sum, Polar:\tv_sum = (" <<  sum3 << ", " << sum4  << ")" << endl;
				break;
			//Second case is v1 - v2
			case 2:
				sum1 = num1 - num3;
				sum2 = num2 - num4;
				sum3 = Radius - Radius2;
				sum4 = Theta - Theta2;
				cout <<"Sum, Cartesian:\tv_sum = (" << sum1 << ", " << sum2  << ")" << endl;
				cout <<"Sum, Polar:\tv_sum = (" <<  sum3 << ", " << sum4  << ")" << endl;
				break;
			//Third case is v2 - v1
			case 3:
				sum1 = num3 - num1;
				sum2 = num4 - num2;
				sum3 = Radius2 - Radius;
				sum4 = Theta2 - Theta;
				cout <<"Sum, Cartesian:\tv_sum = (" << sum1 << ", " << sum2  << ")" << endl;
				cout <<"Sum, Polar:\tv_sum = (" <<  sum3 << ", " << sum4  << ")" << endl;
				break;
			//Fourth case is -v1 - v2
			case 4:
				sum1 = -num1 - num3;
				sum2 = -num2 - num4;
				sum3 = -Radius - Radius2;
				sum4 = -Theta - Theta2;
				cout <<"Sum, Cartesian:\tv_sum = (" << sum1 << ", " << sum2  << ")" << endl;
				cout <<"Sum, Polar:\tv_sum = (" <<  sum3 << ", " << sum4  << ")" << endl;
				break;
		}
	}
	
	//Making an if-else statement to see if the user entered numbers for a polar coordinate or cartesian coordinate both times and to see if they want to represent vector or complex numbers.
	else if (((user7 == "c" || user7 == "C") && (user == "C" || user == "c") && (user2 == "c" || user2 == "C")))
	{
		//Displaying both pairs of numbers in both cartesian and polar form formatted for vectors
		if (num2 > 0)
		{
			cout << "Cartesian:\tz1 = " << fixed << setprecision(3) << num1 << " + j " << num2 << endl;
		}
		else
		{
			cout << "Cartesian:\tz1 = " << fixed << setprecision(3) << num1 << " - j " << abs(num2) << endl;
		}
		if (Theta > 0)
		{
			cout << "Polar:\t\tz1 = " << fixed << setprecision(3) << Radius << " exp(j " << Theta << ")" << endl;
		}
		else
		{
			cout << "Polar:\t\tz1 = " << fixed << setprecision(3) << Radius << " exp(-j " << abs(Theta) << ")" << endl;
		}

		//Displaying both pairs of numbers in both cartesian and polar form formatted for vectors
		if (num4 > 0)
		{
			cout << "Cartesian:\tz1 = " << fixed << setprecision(3) << num3 << " + j " << num4 << endl;
		}
		else
		{
			cout << "Cartesian:\tz1 = " << fixed << setprecision(3) << num3 << " - j " << abs(num4) << endl;
		}
		if (Theta2 > 0)
		{
			cout << "Polar:\t\tz1 = " << fixed << setprecision(3) << Radius2 << " exp(j " << Theta2 << ")" << endl;
		}
		else
		{
			cout << "Polar:\t\tz1 = " << fixed << setprecision(3) << Radius2 << " exp(-j " << abs(Theta2) << ")" << endl;
		}
		
		//Asking the user which operation they want to perform and reading their answer in the variable user3.
		cout << "\nWhich of the following sums or differences\nwould you life to compute?" << endl;
		cout << "1. z1 + z2" << endl;
		cout << "2. z1 - z2" << endl;
		cout << "3. z2 - z1" << endl;
		cout << "4. -z1 - z2\n" << endl;
		cin >> user3;
		
		//Error checking That the user entered the correct number value corresponding to the operation number.
		if (user3 > 4 || user3 < 1)
		{
			cout << "ERROR! Invalid selection, exiting." << endl;
			
			//Ending the program if the user entered invalid character
			return -1;
		}
		
		//Declaring four variables for the four separate operation we have to do for each case.
		double sum1, sum2, sum3, sum4;
		
		//Making a switch case for each case of the operation using the user3 variable
		switch (user3)
		{
			//First case is v1 + v2
			case 1:
				sum1 = num1 + num3;
				sum2 = num4 + num2;
				sum3 = Radius + Radius2;
				sum4 = Theta + Theta2;
				cout <<"Sum, Cartesian:\tz_sum = " << sum1 << " + j " << sum2 << endl;
				cout <<"Sum, Polar:\tz_sum = (" <<  sum3 << " exp(j " << sum4  << ")" << endl;
				break;
			//Second case is v1 - v2
			case 2:
				sum1 = num1 - num3;
				sum2 = num2 - num4;
				sum3 = Radius - Radius2;
				sum4 = Theta - Theta2;
				cout <<"Sum, Cartesian:\tz_sum = " << sum1 << " + j " << sum2 << endl;
				cout <<"Sum, Polar:\tz_sum = (" <<  sum3 << " exp(j " << sum4  << ")" << endl;
				break;
			//Third case is v2 - v1
			case 3:
				sum1 = num3 - num1;
				sum2 = num4 - num2;
				sum3 = Radius2 - Radius;
				sum4 = Theta2 - Theta;
				cout <<"Sum, Cartesian:\tz_sum = " << sum1 << " + j " << sum2 << endl;
				cout <<"Sum, Polar:\tz_sum = (" <<  sum3 << " exp(j " << sum4  << ")" << endl;
				break;
			//Fourth case is -v1 - v2
			case 4:
				sum1 = -num1 - num3;
				sum2 = -num2 - num4;
				sum3 = -Radius - Radius2;
				sum4 = -Theta - Theta2;
				cout <<"Sum, Cartesian:\tz_sum = " << sum1 << " + j " << sum2 << endl;
				cout <<"Sum, Polar:\tz_sum = (" <<  sum3 << " exp(j " << sum4  << ")" << endl;
				break;
		}
	}
	//Making an if-else statement to see if the user entered numbers for a polar coordinate or cartesian coordinate both times and to see if they want to represent vector or complex numbers.	
	
	else if (((user7 == "c" || user7 == "C") && (user == "P" || user == "p") && (user2 == "c" || user2 == "C")))
	{
		//Displaying both pairs of numbers in both cartesian and polar form formatted for vectors
		if (y > 0)
		{
			cout << "Cartesian:\tz1 = " << fixed << setprecision(3) << x << " + j " << y << endl;
		}
		else
		{
			cout << "Cartesian:\tz1 = " << fixed << setprecision(3) << x << " - j " << abs(y) << endl;
		}
		if (num2 > 0)
		{
			cout << "Polar:\t\tz1 = " << fixed << setprecision(3) << num1 << " exp(j " << num2 << ")" << endl;
		}
		else
		{
			cout << "Polar:\t\tz1 = " << fixed << setprecision(3) << num1 << " exp(-j " << abs(num2) << ")" << endl;
		}

		//Displaying both pairs of numbers in both cartesian and polar form formatted for vectors
		if (num4 > 0)
		{
			cout << "Cartesian:\tz1 = " << fixed << setprecision(3) << num3 << " + j " << num4 << endl;
		}
		else
		{
			cout << "Cartesian:\tz1 = " << fixed << setprecision(3) << num3 << " - j " << abs(num4) << endl;
		}
		if (Theta2 > 0)
		{
			cout << "Polar:\t\tz1 = " << fixed << setprecision(3) << Radius2 << " exp(j " << Theta2 << ")" << endl;
		}
		else
		{
			cout << "Polar:\t\tz1 = " << fixed << setprecision(3) << Radius2 << " exp(-j " << abs(Theta2) << ")" << endl;
		}
		
		//Asking the user which operation they want to perform and reading their answer in the variable user3.
		cout << "\nWhich of the following sums or differences\nwould you life to compute?" << endl;
		cout << "1. z1 + z2" << endl;
		cout << "2. z1 - z2" << endl;
		cout << "3. z2 - z1" << endl;
		cout << "4. -z1 - z2\n" << endl;
		cin >> user3;
		
		//Error checking That the user entered the correct number value corresponding to the operation number.
		if (user3 > 4 || user3 < 1)
		{
			cout << "ERROR! Invalid selection, exiting." << endl;
			
			//Ending the program if the user entered invalid character
			return -1;
		}
		
		//Declaring four variables for the four separate operation we have to do for each case.
		double sum1, sum2, sum3, sum4;
		
		//Making a switch case for each case of the operation using the user3 variable
		switch (user3)
		{
			//First case is v1 + v2
			case 1:
				sum1 = x + num3;
				sum2 = y + num4;
				sum3 = sqrt((sum1 * sum1) + (sum2 * sum2));
				if (sum1 >=0)
				{
					sum4 = atan(sum2 / sum1);
				}
				else if (sum1 < 0 && sum2 >=0)
				{
					sum4 = atan(sum2 / sum1) + M_PI;
				}
				else
				{
					sum4 = atan(sum2 / sum1) - M_PI;
				}
				cout <<"Sum, Cartesian:\tz_sum = " << sum1 << " + j " << sum2 << endl;
				cout <<"Sum, Polar:\tz_sum = " <<  sum3 << " exp(j " << sum4  << ")" << endl;
				break;
			//Second case is v1 - v2
			case 2:
				sum1 = x - num3;
				sum2 = y - num4;
				sum3 = sqrt((sum1 * sum1) + (sum2 * sum2));
				if (sum1 >=0)
				{
					sum4 = atan(sum2 / sum1);
				}
				else if (sum1 < 0 && sum2 >=0)
				{
					sum4 = atan(sum2 / sum1) + M_PI;
				}
				else
				{
					sum4 = atan(sum2 / sum1) - M_PI;
				}
				cout <<"Sum, Cartesian:\tz_sum = " << sum1 << " + j " << sum2 << endl;
				cout <<"Sum, Polar:\tz_sum = " <<  sum3 << " exp(j " << sum4  << ")" << endl;
				break;
			//Third case is v2 - v1
			case 3:
				sum1 = num3 - x;
				sum2 = num4 - y;
				sum3 = sqrt((sum1 * sum1) + (sum2 * sum2));
				if (sum1 >=0)
				{
					sum4 = atan(sum2 / sum1);
				}
				else if (sum1 < 0 && sum2 >=0)
				{
					sum4 = atan(sum2 / sum1) + M_PI;
				}
				else
				{
					sum4 = atan(sum2 / sum1) - M_PI;
				}
				cout <<"Sum, Cartesian:\tz_sum = " << sum1 << " + j " << sum2 << endl;
				cout <<"Sum, Polar:\tz_sum = " <<  sum3 << " exp(j " << sum4  << ")" << endl;
				break;
			//Fourth case is -v1 - v2
			case 4:
				sum1 = -x - num3;
				sum2 = -y - num4;
				sum3 = sqrt((sum1 * sum1) + (sum2 * sum2));
				if (sum1 >=0)
				{
					sum4 = atan(sum2 / sum1);
				}
				else if (sum1 < 0 && sum2 >=0)
				{
					sum4 = atan(sum2 / sum1) + M_PI;
				}
				else
				{
					sum4 = atan(sum2 / sum1) - M_PI;
				}
				cout <<"Sum, Cartesian:\tz_sum = " << sum1 << " + j " << sum2 << endl;
				cout <<"Sum, Polar:\tz_sum = " <<  sum3 << " exp(j " << sum4  << ")" << endl;
				break;
		}
	}
	//Making an if-else statement to see if the user entered numbers for a polar coordinate or cartesian coordinate both times and to see if they want to represent vector or complex numbers.
	
	else if (((user7 == "c" || user7 == "C") && (user == "P" || user == "p") && (user2 == "p" || user2 == "P")))
	{
		//Displaying both pairs of numbers in both cartesian and polar form formatted for vectors
		if (y > 0)
		{
			cout << "Cartesian:\tz1 = " << fixed << setprecision(3) << x << " + j " << y << endl;
		}
		else
		{
			cout << "Cartesian:\tz1 = " << fixed << setprecision(3) << x << " - j " << abs(y) << endl;
		}
		if (num2 > 0)
		{
			cout << "Polar:\t\tz1 = " << fixed << setprecision(3) << num1 << " exp(j " << num2 << ")" << endl;
		}
		else
		{
			cout << "Polar:\t\tz1 = " << fixed << setprecision(3) << num1 << " exp(-j " << abs(num2) << ")" << endl;
		}

		//Displaying both pairs of numbers in both cartesian and polar form formatted for vectors
		if (y2 > 0)
		{
			cout << "Cartesian:\tz1 = " << fixed << setprecision(3) << x2 << " + j " << y2 << endl;
		}
		else
		{
			cout << "Cartesian:\tz1 = " << fixed << setprecision(3) << x2 << " - j " << abs(y2) << endl;
		}
		if (num4 > 0)
		{
			cout << "Polar:\t\tz1 = " << fixed << setprecision(3) << num3 << " exp(j " << num4 << ")" << endl;
		}
		else
		{
			cout << "Polar:\t\tz1 = " << fixed << setprecision(3) << num3 << " exp(-j " << abs(num4) << ")" << endl;
		}
		
		//Asking the user which operation they want to perform and reading their answer in the variable user3.
		cout << "\nWhich of the following sums or differences\nwould you life to compute?" << endl;
		cout << "1. z1 + z2" << endl;
		cout << "2. z1 - z2" << endl;
		cout << "3. z2 - z1" << endl;
		cout << "4. -z1 - z2\n" << endl;
		cin >> user3;
		
		//Error checking That the user entered the correct number value corresponding to the operation number.
		if (user3 > 4 || user3 < 1)
		{
			cout << "ERROR! Invalid selection, exiting." << endl;
			
			//Ending the program if the user entered invalid character
			return -1;
		}
		
		//Declaring four variables for the four separate operation we have to do for each case.
		double sum1, sum2, sum3, sum4;
		
		//Making a switch case for each case of the operation using the user3 variable
		switch (user3)
		{
			//First case is v1 + v2
			case 1:
				sum1 = x + x2;
				sum2 = y + y2;
				sum3 = num1 + num3;
				sum4 = num2 + num4;
				cout <<"Sum, Cartesian:\tz_sum = " << sum1 << " + j " << sum2 << endl;
				cout <<"Sum, Polar:\tz_sum = (" <<  sum3 << " exp(j " << sum4  << ")" << endl;
				break;
			//Second case is v1 - v2
			case 2:
				sum1 = x - x2;
				sum2 = y - y2;
				sum3 = num1 - num3;
				sum4 = num2 - num4;
				cout <<"Sum, Cartesian:\tz_sum = " << sum1 << " + j " << sum2 << endl;
				cout <<"Sum, Polar:\tz_sum = (" <<  sum3 << " exp(j " << sum4  << ")" << endl;
				break;
			//Third case is v2 - v1
			case 3:
				sum1 = x2 - x;
				sum2 = y2 - y;
				sum3 = num3 - num1;
				sum4 = num4 - num2;
				cout <<"Sum, Cartesian:\tz_sum = " << sum1 << " + j " << sum2 << endl;
				cout <<"Sum, Polar:\tz_sum = (" <<  sum3 << " exp(j " << sum4  << ")" << endl;
				break;
			//Fourth case is -v1 - v2
			case 4:
				sum1 = -x - x2;
				sum2 = -y - y2;
				sum3 = -num1 - num3;
				sum4 = -num2 - num4;
				cout <<"Sum, Cartesian:\tz_sum = " << sum1 << " + j " << sum2 << endl;
				cout <<"Sum, Polar:\tz_sum = (" <<  sum3 << " exp(j " << sum4  << ")" << endl;
				break;
		}
	}
	//Making an if-else statement to see if the user entered numbers for a polar coordinate or cartesian coordinate both times and to see if they want to represent vector or complex numbers.
	
	else if (((user7 == "c" || user7 == "C") && (user == "C" || user == "c") && (user2 == "p" || user2 == "P")))
	{
		x = sqrt((num1 * num1) + (num2 * num2));
		y =  atan(num2 / num1);
		//Displaying both pairs of numbers in both cartesian and polar form formatted for vectors
		if (num2 > 0)
		{
			cout << "Cartesian:\tz1 = " << fixed << setprecision(3) << num1 << " + j " << num2 << endl;
		}
		else
		{
			cout << "Cartesian:\tz1 = " << fixed << setprecision(3) << num1 << " - j " << abs(num2) << endl;
		}
		if (y > 0)
		{
			cout << "Polar:\t\tz1 = " << fixed << setprecision(3) << x << " exp(j " << y << ")" << endl;
		}
		else
		{
			cout << "Polar:\t\tz1 = " << fixed << setprecision(3) << x << " exp(-j " << abs(y) << ")" << endl;
		}

		//Displaying both pairs of numbers in both cartesian and polar form formatted for vectors
		if (y2 > 0)
		{
			cout << "Cartesian:\tz1 = " << fixed << setprecision(3) << x2 << " + j " << y2 << endl;
		}
		else
		{
			cout << "Cartesian:\tz1 = " << fixed << setprecision(3) << x2 << " - j " << abs(y2) << endl;
		}
		if (num4 > 0)
		{
			cout << "Polar:\t\tz1 = " << fixed << setprecision(3) << num3 << " exp(j " << num4 << ")" << endl;
		}
		else
		{
			cout << "Polar:\t\tz1 = " << fixed << setprecision(3) << num3 << " exp(-j " << abs(num4) << ")" << endl;
		}
		
		//Asking the user which operation they want to perform and reading their answer in the variable user3.
		cout << "\nWhich of the following sums or differences\nwould you life to compute?" << endl;
		cout << "1. z1 + z2" << endl;
		cout << "2. z1 - z2" << endl;
		cout << "3. z2 - z1" << endl;
		cout << "4. -z1 - z2\n" << endl;
		cin >> user3;
		
		//Error checking That the user entered the correct number value corresponding to the operation number.
		if (user3 > 4 || user3 < 1)
		{
			cout << "ERROR! Invalid selection, exiting." << endl;
			
			//Ending the program if the user entered invalid character
			return -1;
		}
		
		//Declaring four variables for the four separate operation we have to do for each case.
		double sum1, sum2, sum3, sum4;
		
		//Making a switch case for each case of the operation using the user3 variable
		switch (user3)
		{
			//First case is v1 + v2
			case 1:
				sum1 = num1 + x2;
				sum2 = num2 + y2;
				sum3 = x + num3;
				sum4 = y + num4;
				cout <<"Sum, Cartesian:\tz_sum = " << sum1 << " + j " << sum2 << endl;
				cout <<"Sum, Polar:\tz_sum = (" <<  sum3 << " exp(j " << sum4  << ")" << endl;
				break;
			//Second case is v1 - v2
			case 2:
				sum1 = num1 - x2;
				sum2 = num2 - y2;
				sum3 = x - num3;
				sum4 = y - num4;
				cout <<"Sum, Cartesian:\tz_sum = " << sum1 << " + j " << sum2 << endl;
				cout <<"Sum, Polar:\tz_sum = (" <<  sum3 << " exp(j " << sum4  << ")" << endl;
				break;
			//Third case is v2 - v1
			case 3:
				sum1 = x2 - num1;
				sum2 = y2 - num2;
				sum3 = num3 - x;
				sum4 = num4 - y;
				cout <<"Sum, Cartesian:\tz_sum = " << sum1 << " + j " << sum2 << endl;
				cout <<"Sum, Polar:\tz_sum = (" <<  sum3 << " exp(j " << sum4  << ")" << endl;
				break;
			//Fourth case is -v1 - v2
			case 4:
				sum1 = -num1 - x2;
				sum2 = -num2 - y2;
				sum3 = -x - num3;
				sum4 = -y - num4;
				cout <<"Sum, Cartesian:\tz_sum = " << sum1 << " + j " << sum2 << endl;
				cout <<"Sum, Polar:\tz_sum = (" <<  sum3 << " exp(j " << sum4  << ")" << endl;
				break;
		}
	}
	
	//If program make it to this, it exits the program with 0
	return 0;
}