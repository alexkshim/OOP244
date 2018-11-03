/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.cpp
// Version 1.0
// Date 25/05/2017
// Author Chris Szalwinski
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

// TODO: include the necessary headers
#include <iostream>
#include "Kingdom.h"
// TODO: the sict namespace
using namespace std;

namespace sict {
	// TODO:definition for display(...)
	void display(const Kingdom& King) {
		cout << King.m_name << ", population " << King.m_population << endl;
	} 
	void display(const Kingdom* king, int count) {
		int totalPpl = 0;
		cout << "------------------------------" << endl;
		cout << "Kingdoms of SICT" << endl;
		cout << "------------------------------" << endl;
		for (int i = 0; i < count; i++) {
			cout << i + 1 << ". ";
			//cout << king[i].m_name << ", population " << king[i].m_population << endl;
			sict::display(king[i]);
			totalPpl += king[i].m_population;
		}
		cout << "------------------------------" << endl;
		cout << "Total population of SICT: " << totalPpl << endl;
		cout << "------------------------------" << endl;
	}
}