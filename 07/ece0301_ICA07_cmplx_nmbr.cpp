// This program demonstrates a simple class.
#include <iostream>
#include <cmath>
using namespace std;

// Complex class declaration.
class Complex
{
   private:
      double real;
      double imaginary;
   public:
      void setReal(double);
      void setImagine(double);
      double getReal() const;
      double getImagine() const;
      double getMag() const;
      double getPhase() const;
};

//**********************************************
// setReal assigns a value to the real member. *
//**********************************************

void Complex::setReal(double r)
{
   real = r;
}

//******************************************************
// setImagine assigns a value to the imaginary member. *
//******************************************************

void Complex::setImagine(double i)
{
   imaginary = i;
}


//************************************************
// getReal returns the value in the real member. *
//************************************************

double Complex::getReal() const
{
   return real;
}

//********************************************************
// getImagine returns the value in the imaginary member. *
//********************************************************

double Complex::getImagine() const
{
   return imaginary;
}

//******************************************************
// getMag returns the magnitude of the complex number. *
//******************************************************

double Complex::getMag() const
{
   return sqrt(pow(real,2) + pow(imaginary, 2));
}

//**********************************************************
// getPhase returns the phase angle of the complex number. *
//**********************************************************

double Complex::getPhase() const
{
   return atan(imaginary/real);
}


//*****************
// Main Function  *
//*****************

int main()
{
   //Defining an instance of the Complex class
   Complex box;

   //Declaring Variables
   double real, imagine;

   //Introductory statement to the user
   cout << "This program will calculate the magnitude and phase.\nangle of a complex number.\n\n";

   //Reading in value for real part of complex number
   cout << "What is the real part? What is the imaginary part? Here are the data on complex number z:\n";
   cin >> real >> imagine;

   //Store the value entered by the user to be used in the class
   box.setReal(real);
   box.setImagine(imagine); 

   // Display the complex number's data.
   cout << "Real part: " << box.getReal() << endl;
   cout << "Imaginary part: " << box.getImagine() << endl;
   cout << "Magnitude: " << box.getMag() << endl;
   cout << "Phase angle (radians): " << box.getPhase() << endl;

   //Program ends if it gets this far
   return 0;
}