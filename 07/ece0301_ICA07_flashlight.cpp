#include "Flashlight.h"
#include <iostream>
#include <cmath>
using namespace std;

//********************
// Display Function. *
//********************

void Display(Flashlight something)
{
    //Introductory message to users
    cout << "Here are the data on the Flashlight:\n";

    //Declaring variables
    bool state = something.getState();

    //Store the value for the voltage and the resistance


    //Displaying the data from the class to the users in the required format
    cout << "The battery voltage is " << something.getVolt() << " Volts." << endl;
    cout << "The bulb resistance is " << something.getRes() << " Ohms." << endl;

    //Switch State
    if(state == 0)
    {
        cout << "The switch is open.\nThe FlashLight is off.\n";
    }
    else if (state == 1)
    {
        cout << "The switch is closed.\nThe FlashLight is on.\n";
    }

    //Current State
    if(state == 0)
    {
         cout << "The bulb current is 0 Amperes.\n";
    }
    else
    {
        cout << "The bulb current is " << something.getCurrent() << " Amperes." << endl;
    }

    //Power State
    if(state == 0)
    {
         cout << "The bulb power is 0 Watts.\n";
    }
    else
    {
        cout << "The bulb power is " << something.getPower() << " Watts." << endl;
    }

}

//*****************
// Main Function. *
//*****************

int main()
{
    Flashlight box = Flashlight(3.0, 100.0, 0);

    //Calling function to display the needed statments
    Display(box);

    //Declaring variables
    int user;
    double newVolt, newResis;

    //Asking what option the user wants to pick
    while (user != 1 && user != 2 && user!= 3 && user!= 4)
        {
            cout << "What would you like to do with the FlashLight?\n(1) Change the battery voltage.\n(2) Change the bulb resistance.\n(3) Toggle the switch state.\n(4) Exit program.\n";
            cout << "Your selection?\n";
            cin >> user;
        }

    //Do-While loop to allow the users to change what they want to change depending on their choice
    do
    {   
        if(user == 1)
        {
            cout << "Enter the new battery voltage:";
            cin >> newVolt;
            //Inserting the new entered voltage as new voltage in display function
            box.setVolt(newVolt);
            Display(box);
        }

        if(user == 2)
        {
            cout << "Enter the new bulb resistance:";
            cin >> newResis;
            //Inserting the new entered resistance as new voltage in display function
            box.setResis(newResis);
            Display(box);
        }

        if(user == 3)
        {
			bool newState = box.getState();
            //Toggles the switch state on and off
            box.setMove(newState);
            Display(box);
        }

        if(user == 4)
        {
            //Exits the program if clicked
            break;
        }

        //Displays if the user entered a value that was not 1-4
		cout << "What would you like to do with the FlashLight?\n(1) Change the battery voltage.\n(2) Change the bulb resistance.\n(3) Toggle the switch state.\n(4) Exit program.\n";
        cout << "Your selection?\n";
        cin >> user;
            
    }while (user == 1 || user == 2 || user == 3);

    //Ending the program if it gets to this point
    return 0;
}