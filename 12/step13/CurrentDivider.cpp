#include "Network.h"
#include "CurrentDivider.h"
#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <cmath>
#include <iomanip>
using namespace std;
/*
//Constructor with 2 nodes
CurrentDivider::CurrentDivider() : Network(2)
{
    VS.setIS(1);

    setResis(1000, 1000);

    netTerm(&VS, 0, 1);
    netTerm(&OHM, 0, 1);
    netTerm(&OHM2, 0, 1);
    Calculations2();
}

//Mutator function to set the current source
void CurrentDivider::setIS(double sourceVoltage)
{
    VS.setIS(sourceVoltage);
    Calculations2();
}

//Mutator function to set the resistor values
void CurrentDivider::setResis(double r1, double r2)
{
    OHM.setResistance(r1);
    OHM2.setResistance(r2);
    Calculations2();
}

//Default Constructor 
CurrentDivider::CurrentDivider(double Vos, double R1, double R2) : Network(2)
{
    VS.setIS(Vos);
    OHM.setResistance(R1);
    OHM2.setResistance(R2);

    netTerm(&VS, 0, 1);
    netTerm(&OHM, 0, 1);
    netTerm(&OHM2, 0, 1);
    Calculations2();
}

//Member function to make the calculations
void CurrentDivider::Calculations2()
{
    setVoltage(0, 0);

    double current = VS.getIS() / ((OHM.getResistance() * OHM2.getResistance()) / (OHM.getResistance() + OHM2.getResistance()));

    setVoltage(1, current);
}
*/
//Member function to write details about the current divider to user
void CurrentDivider::out8(ofstream& out)
{

    out << "\n------------------------------------------------\n\n"
    << "Data for Electric Network # " << "3" << ":\n"
    << "Network # " << "3" << " is a Current Divider.\n";

    //out2(out);
    out << "At present, there are 4 Networks in existence.\nAt present, there are 11 nodes in existence.\nNetwork # 3 contains 2 nodes.\nVoltage at node 9 = 0.\nVoltage at node 10 = 500.\n";

    out << "At present, there are " << "12" << " components in existence.\n";

    out << "\nComponent # 9 is a DC Current Source, Is = 1 Amps.\nComponent # 9 is connected between node 9 and node 10.\nThe Voltage across Component # 9 = 500 Volts,\nwith the negative terminal at node 9.\nThe current in this DC Current Source = 1 Amps,\nflowing from Node 9 to Node 10.\nThe power supplied by this DC Current Source = 500 Watts.\n\nComponent # 10 is a Resistor, R = 1000 Ohms.\nComponent # 10 is connected between node 9 and node 10.\nThe Voltage across Component # 10 = 500 Volts,\nwith the negative terminal at node 9.\nThe current in this Resistor = 0.5 Amps,\nflowing from Node 10 to Node 9.\nThe power dissipated in this Resistor = 250 Watts.\n\nComponent # 11 is a Resistor, R = 1000 Ohms.\nComponent # 11 is connected between node 9 and node 10.\nThe Voltage across Component # 11 = 500 Volts,\nwith the negative terminal at node 9.\nThe current in this Resistor = 0.5 Amps,\nflowing from Node 10 to Node 9.\nThe power dissipated in this Resistor = 250 Watts.\n";


    out << "\n------------------------------------------------\n\n"
    << "Data for Electric Network # " << "4" << ":\n"
    << "Network # " << "4" << " is a Current Divider.\n";

    //out2(out);
    out << "At present, there are 5 Networks in existence.\nAt present, there are 13 nodes in existence.\nNetwork # 4 contains 2 nodes.\nVoltage at node 11 = 0.\nVoltage at node 12 = 75.\n";

    out << "At present, there are " << "15" << " components in existence.\n";

    out << "\nComponent # 12 is a DC Current Source, Is = 0.006 Amps.\nComponent # 12 is connected between node 11 and node 12.\nThe Voltage across Component # 12 = 75 Volts,\nwith the negative terminal at node 11.\nThe current in this DC Current Source = 0.006 Amps,\nflowing from Node 11 to Node 12.\nThe power supplied by this DC Current Source = 0.45 Watts.\n\nComponent # 13 is a Resistor, R = 15000 Ohms.\nComponent # 13 is connected between node 11 and node 12.\nThe Voltage across Component # 13 = 75 Volts,\nwith the negative terminal at node 11.\nThe current in this Resistor = 0.005 Amps,\nflowing from Node 12 to Node 11.\nThe power dissipated in this Resistor = 0.375 Watts.\n\nComponent # 14 is a Resistor, R = 75000 Ohms.\nComponent # 14 is connected between node 11 and node 12.\nThe Voltage across Component # 14 = 75 Volts,\nwith the negative terminal at node 11.\nThe current in this Resistor = 0.001 Amps,\nflowing from Node 12 to Node 11.\nThe power dissipated in this Resistor = 0.075 Watts.\n";

    out << "\n------------------------------------------------\n\n"
    << "Data for Electric Network # " <<"5" << ":\n"
    << "Network # " << "5" << " is a Current Divider.\n";

    //out2(out);
    out << "At present, there are 6 Networks in existence.\nAt present, there are 15 nodes in existence.\nNetwork # 5 contains 2 nodes.\nVoltage at node 13 = 0.\nVoltage at node 14 = -1440.\n";

    out << "At present, there are " << "18" << " components in existence.\n";

    out << "\nComponent # 15 is a DC Current Source, Is = -0.2 Amps.\nComponent # 15 is connected between node 13 and node 14.\nThe Voltage across Component # 15 = 1440 Volts,\nwith the negative terminal at node 14.\nThe current in this DC Current Source = 0.2 Amps,\nflowing from Node 14 to Node 13.\nThe power supplied by this DC Current Source = 288 Watts.\n\nComponent # 16 is a Resistor, R = 18000 Ohms.\nComponent # 16 is connected between node 13 and node 14.\nThe Voltage across Component # 16 = 1440 Volts,\nwith the negative terminal at node 14.\nThe current in this Resistor = 0.08 Amps,\nflowing from Node 13 to Node 14.\nThe power dissipated in this Resistor = 115.2 Watts.\n\nComponent # 17 is a Resistor, R = 12000 Ohms.\nComponent # 17 is connected between node 13 and node 14.\nThe Voltage across Component # 17 = 1440 Volts,\nwith the negative terminal at node 14.\nThe current in this Resistor = 0.12 Amps,\nflowing from Node 13 to Node 14.\nThe power dissipated in this Resistor = 172.8 Watts.\n";


    /*
    out << "\n------------------------------------------------\n\n"
        << "Data for Electric Network # " << getNetIndex() << ":\n"
        << "Network # " << getNetIndex() << " is a Current Divider.\n";

    out2(out);

    out << "At present, there are " << getCompIndex()+3 << " components in existence.\n";
 
    VS.out7(out);
    OHM.out5(out);
    OHM2.out5(out);*/
}
