/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File w2_in_lab.cpp
// Version 1.0
// Date 25/05/2017
// Author Christopher Szalwinski
// Description
// Workshop 2 lab
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// Kyuyoung Shim 102562162
///////////////////////////////////////////////////////////
***********************************************************/

#include <iostream>
#include "Kingdom.h"

using namespace std;
using namespace sict;

void read(sict::Kingdom&);

int main() {
    int count = 0; // the number of kingdoms in the array

	sict::Kingdom* pKingdom;
	pKingdom = nullptr;
    // TODO: declare the pKingdom pointer here (don't forget to initialize it)
    cout << "==========\n"
         << "Input data\n"
         << "==========\n"
         << "Enter the number of kingdoms: ";
    cin >> count;
	
    cin.ignore();

	if (count < 1) return 1;
	pKingdom = new Kingdom[count];
    // TODO: allocate dynamic memory here for the pKingdom pointer

    for (int i = 0; i < count; ++i) {
        cout << "Kingdom #" << i + 1 << ": " << endl;
		cout << "Enter the name of the kingdom: ";
		cin >> pKingdom[i].m_name;
		cout << "Enter the number people living in "<<pKingdom[i].m_name<<": ";
		cin >> pKingdom[i].m_population;
		// TODO: add code to accept user input for Kingdom i
    }
    cout << "==========" << endl << endl;

    // testing that "display(...)" works
    cout << "------------------------------" << endl
        << "The first kingdom entered is" << endl
        << "------------------------------" << endl;
    sict::display(pKingdom[0]);
    cout << "------------------------------" << endl << endl;

    // TODO: deallocate the dynamic memory here
	delete[] pKingdom;
	pKingdom = nullptr;
	return 0;
}

// read accepts data for a Kingdom from standard input
//
void read(Kingdom& kingdom) {

    cout << "Enter the name of the kingdom: ";
    cin.get(kingdom.m_name, 32, '\n');
    cin.ignore(2000, '\n');
    cout << "Enter the number people living in " << kingdom.m_name << ": ";
    cin >> kingdom.m_population;
    cin.ignore(2000, '\n');
}