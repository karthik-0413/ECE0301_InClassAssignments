#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <cmath>
#include <iomanip>
#include "Network.h"
#include "Node.h"
#include "Component.h"


int main()
{
    //Declaring output file
    ofstream out;
    out.open("ECE 0301 - Electrical Network Reports.txt");

    //Displaying Introductory Statement
    out << "ECE 0301 - Electrical Network Simulation\n";

    //Define a network with 3 nodes
    Network net(3);

    //Define 3 components
    Terminal Term1;
    Terminal Term2;
    Terminal Term3;

    //Call the member functoin from the netwrok class to connect it with the Terminal Class
    net.netTerm(&Term1, 0, 1);
    net.netTerm(&Term2, 1, 2);
    net.netTerm(&Term3, 2, 0);

    //Setting voltage at each node
    net.setVoltage(1, -5.0);
    net.setVoltage(2, 1.25);

    //Output File from Network Class
    net.out2(out);

    //Output Files from the Terminal Class
    Term1.out3(out);
    Term2.out3(out);
    Term3.out3(out);

    //Close the output file
    out.close();

    //Ending the program with returning 0 to main
    return 0;
}