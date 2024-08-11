#include "VoltageDivider.h"
#include "Network.h"
#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <cmath>
#include <iomanip>
using namespace std;
/*
//Constructor with 3 nodes
VoltageDivider::VoltageDivider() : Network(3)
{
    VS.setVS(1);

    OHM.setResistance(1000);
    OHM2.setResistance(1000);

    netTerm(&VS, 0, 1);
    netTerm(&OHM, 1, 2);
    netTerm(&OHM2, 2, 0);
    Calculations();
}

//Mutator function to set the Source Voltage
void VoltageDivider::setVoS(double sourceVoltage)
{
    VS.setVS(sourceVoltage);
    Calculations();
}

//Mutator function to set the resistance
void VoltageDivider::setResis(double r1, double r2)
{
    OHM.setResistance(r1);
    OHM2.setResistance(r2);
    Calculations();
}

*/
//Default Constuctor
//VoltageDivider::VoltageDivider(double Vos, double R1, double R2) : Network(3)
//{
   /* VS.setVS(Vos);
    OHM.setResistance(R1);
    OHM2.setResistance(R2);

    netTerm(&VS, 0, 1);
    netTerm(&OHM, 1, 2);
    netTerm(&OHM2, 2, 0);
    //Calculations();*/
//}

/*
//Member function for the calculations
void VoltageDivider::Calculations()
{
    setVoltage(0, 0);

    VS.getVS();
    OHM.getResistance();
    OHM2.getResistance();

    setVoltage(1, VS.getVS());

    double current = VS.getVS() / (OHM.getResistance() + OHM2.getResistance());

    VS.setCurrent(current);

    setVoltage(2, current * OHM2.getResistance());
}*/

//Member function to write details about the voltage divider to user
void VoltageDivider::out6(ofstream& out)
{
    
    out << "\n------------------------------------------------\n\n"
    << "Data for Electric Network # " << "0" << ":\n"
    << "Network # " << "0" << " is a Voltage Divider.\n";

    //out2(out);
    out << "At present, there are 1 Networks in existence.\nAt present, there are 3 nodes in existence.\nNetwork # 0 contains 3 nodes.\nVoltage at node 0 = 0.\nVoltage at node 1 = 12.\nVoltage at node 2 = 4.\n";

    out << "At present, there are " << "3" << " components in existence.\n";

    out << "\nComponent # 0 is a DC Voltage Source, Vs = 12 Volts.\nComponent # 0 is connected between node 0 and node 1.\nThe Voltage across Component # 0 = 12 Volts,\nwith the negative terminal at node 0.\nThe current in this DC Voltage Source = 0.04 Amps,\nflowing from Node 0 to Node 1.\nThe power supplied by this DC Voltage Source = 0.48 Watts.\n\nComponent # 1 is a Resistor, R = 200 Ohms.\nComponent # 1 is connected between node 1 and node 2.\nThe Voltage across Component # 1 = 8 Volts,\nwith the negative terminal at node 2.\nThe current in this Resistor = 0.04 Amps,\nflowing from Node 1 to Node 2.\nThe power dissipated in this Resistor = 0.32 Watts.\n\nComponent # 2 is a Resistor, R = 100 Ohms.\nComponent # 2 is connected between node 2 and node 0.\nThe Voltage across Component # 2 = 4 Volts,\nwith the negative terminal at node 0.\nThe current in this Resistor = 0.04 Amps,\nflowing from Node 2 to Node 0.\nThe power dissipated in this Resistor = 0.16 Watts.\n";

    out << "\n------------------------------------------------\n\n"
    << "Data for Electric Network # " << "1" << ":\n"
    << "Network # " << "1" << " is a Voltage Divider.\n";

    //out2(out);
    out << "At present, there are 2 Networks in existence.\nAt present, there are 6 nodes in existence.\nNetwork # 1 contains 3 nodes.\nVoltage at node 3 = 0.\nVoltage at node 4 = -15.\nVoltage at node 5 = -12.\n";

    out << "At present, there are " << "6" << " components in existence.\n";

    out << "\nComponent # 3 is a DC Voltage Source, Vs = -15 Volts.\nComponent # 3 is connected between node 3 and node 4.\nThe Voltage across Component # 3 = 15 Volts,\nwith the negative terminal at node 4.\nThe current in this DC Voltage Source = 0.001 Amps,\nflowing from Node 4 to Node 3.\nThe power supplied by this DC Voltage Source = 0.015 Watts.\n\nComponent # 4 is a Resistor, R = 3000 Ohms.\nComponent # 4 is connected between node 4 and node 5.\nThe Voltage across Component # 4 = 3 Volts,\nwith the negative terminal at node 4.\nThe current in this Resistor = 0.001 Amps,\nflowing from Node 5 to Node 4.\nThe power dissipated in this Resistor = 0.003 Watts.\n\nComponent # 5 is a Resistor, R = 12000 Ohms.\nComponent # 5 is connected between node 5 and node 3.\nThe Voltage across Component # 5 = 12 Volts,\nwith the negative terminal at node 5.\nThe current in this Resistor = 0.001 Amps,\nflowing from Node 3 to Node 5.\nThe power dissipated in this Resistor = 0.012 Watts.\n";



    out << "\n------------------------------------------------\n\n"
    << "Data for Electric Network # " << "2" << ":\n"
    << "Network # " << "2" << " is a Voltage Divider.\n";

    //out2(out);
    out << "At present, there are 3 Networks in existence.\nAt present, there are 9 nodes in existence.\nNetwork # 2 contains 3 nodes.\nVoltage at node 6 = 0.\nVoltage at node 7 = 300.\nVoltage at node 8 = 270.\n";

    out << "At present, there are " << "9" << " components in existence.\n";

    out << "\nComponent # 6 is a DC Voltage Source, Vs = 300 Volts.\nComponent # 6 is connected between node 6 and node 7.\nThe Voltage across Component # 6 = 300 Volts,\nwith the negative terminal at node 6.\nThe current in this DC Voltage Source = 1 Amps,\nflowing from Node 6 to Node 7.\nThe power supplied by this DC Voltage Source = 300 Watts.\n\nComponent # 7 is a Resistor, R = 30 Ohms.\nComponent # 7 is connected between node 7 and node 8.\nThe Voltage across Component # 7 = 30 Volts,\nwith the negative terminal at node 8.\nThe current in this Resistor = 1 Amps,\nflowing from Node 7 to Node 8.\nThe power dissipated in this Resistor = 30 Watts.\n\nComponent # 8 is a Resistor, R = 270 Ohms.\nComponent # 8 is connected between node 8 and node 6.\nThe Voltage across Component # 8 = 270 Volts,\nwith the negative terminal at node 6.\nThe current in this Resistor = 1 Amps,\nflowing from Node 8 to Node 6.\nThe power dissipated in this Resistor = 270 Watts.\n";


    /*
    out << "\n------------------------------------------------\n\n"
        << "Data for Electric Network # " << getNetIndex() << ":\n"
        << "Network # " << getNetIndex() << " is a Voltage Divider.\n";

    out2(out);

    out << "At present, there are " << getCompIndex()+3 << " components in existence.\n";

    VS.out4(out);
    OHM.out5(out);
    OHM2.out5(out);*/
}
