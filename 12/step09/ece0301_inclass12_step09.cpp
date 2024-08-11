#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <cmath>
#include <iomanip>
#include "Network.h"
#include "Node.h"
#include "Component.h"
#include "DCVoltageSource.h"
#include "Resistor.h"
using namespace std;

int main()
{
    //Declaring output file
    ofstream out;
    out.open("ECE 0301 - Electrical Network Reports.txt");

    //Displaying Introductory Statement
    out << "ECE 0301 - Electrical Network Simulation\n";

    //Define a network with 3 nodes
    Network net(3);

    //Define a DC Voltage Source and set VS = 12V
    DCVoltageSource DC;
    DC.setVS(12.0);

    //Connecting DC Voltage Source between nodes 0 and 1
    net.netTerm(&DC, 0, 1);

    //Define a resisotr, and set the resistance to 200
    Resistor OHM;
    OHM.setResistance(200.0);

    //Connecting Resistor 1 between nodes 1 and 2
    net.netTerm(&OHM, 1, 2);

    //Define a resisotr, and set the resistance to 100
    Resistor OHM2;
    OHM2.setResistance(100.0);

    //Compute the current drawn from the voltage source (SERIES = ADD RESISTORS)
    double current = DC.getVS() / (OHM.getResistance() + OHM2.getResistance());

    //Call member functino from the DCVOltageSource to set current to the above value
    DC.setCurrent(current);
  
    //Connecting Resistor 2 between nodes 1 and 2
    net.netTerm(&OHM2, 2, 0);

    //Set voltage at node 1 to VS, and voltage at node 2 to VS/3
    net.setVoltage(1, DC.getVS());
    net.setVoltage(2, DC.getVS() / 3);

    //Call network output file
    net.out2(out);

    //Call DCVoltageSource output file
    DC.out4(out);

    //Call both resistor output files
    OHM.out5(out);
    OHM2.out5(out);

    //Close output file
    out.close();

    //Ending the program with returning 0 to main function
    return 0;
}