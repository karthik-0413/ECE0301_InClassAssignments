// This program demonstrates a simple class.
#include <iostream>
#include <cmath>
using namespace std;

// NOT gate class declaration.
class NOT
{
   private:
      string input;
      bool logic;
   public:
      void setInput(string);
      void setLogic(bool);  
      string getInput() const;
      string getOutput() const;
      bool getLog1() const;
      bool getLog2() const;
};

//***********************************************
// setInput assigns a value to the input member. *
//***********************************************

void NOT::setInput(string one)
{
   input = one;
}

//**************************************************
// setLogic assigns a value to the logic member. *
//**************************************************

void NOT::setLogic(bool two)
{
   logic = two;
}


//************************************************************
// getReal returns the value of the label given by the user. *
//************************************************************

string NOT::getInput() const
{
   return input;
}

//**********************************************************
// getOutput returns the value of the label with the _not. *
//**********************************************************

string NOT::getOutput() const
{
   return input + "_not";
}

//************************************************
// getLog1 returns the value of the bool, logic. *
//************************************************

bool NOT::getLog1() const
{
   return logic;
}

//**********************************************************
// getLog2 returns the opposite value of the bool, logic.  *
//**********************************************************

bool NOT::getLog2() const
{
   return !logic;
}


//*****************
// Main Function  *
//*****************

int main()
{
   //Defining an instance of the NOT class
   NOT box;

   //Declaring Variables
   string input;
   bool logic;

   //Introductory statement to the user
   cout << "This program will simulate a not gate.\n";

   //Reading in value for the label and the bool value of it
   cout << "What is the label for the gate input? What is the logic value at that input (0/1)? Here are the data on the not gate:\n";
   cin >> input >> logic;

   //Store the value entered by the user to be used in the class
   box.setInput(input);
   box.setLogic(logic); 

   // Display the NOT gate's data.
   cout << "Input label: " << box.getInput() << endl;
   cout << "Output label: " << box.getOutput() << endl;
   cout << "Logic value at input: " << box.getLog1() << endl;
   cout << "Logic value at output: " << box.getLog2() << endl;

   //Program ends if it gets this far
   return 0;
}