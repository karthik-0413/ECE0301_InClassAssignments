#include "Flashlight.h"
#include <cmath>
#include <iostream>
using namespace std;

//***************************************************************************
// Flashlight Constructor assigns the value for the voltage and resistance. *
//***************************************************************************

Flashlight::Flashlight(double volt, double resis, bool bol)
{
    voltage = volt;
    resistance = resis;
    state = bol;
}

//*************************************************
// setVolt assigns a value to the voltage member. *
//*************************************************

void Flashlight::setVolt(double volt)
{
    voltage = volt;
}

//*****************************************************
// setResis assigns a value to the resistance member. *
//*****************************************************

void Flashlight::setResis(double resis)
{
    resistance = resis;
}

//************************************************
// setMove assigns a value to the switch member. *
//************************************************

void Flashlight::setMove(bool on)
{
    state = !(on);
}

//*************************************************
// getVolt assigns a value to the voltage member. *
//*************************************************

double Flashlight::getVolt() const
{
   return voltage;
}

//***************************************************
// getRes assigns a value to the resistance member. *
//***************************************************

double Flashlight::getRes() const
{
   return resistance;
}

//*************************************************
// getState assigns a value to the switch member. *
//*************************************************

bool Flashlight::getState() const
{
   return state;
}

//****************************************************
// getCurrent assigns a value to the current member. *
//****************************************************

double Flashlight::getCurrent() const
{
    return voltage/resistance;
}

//************************************************
// getPower assigns a value to the input member. *
//************************************************

double Flashlight::getPower() const
{
    return (pow(voltage, 2)) / resistance;
}