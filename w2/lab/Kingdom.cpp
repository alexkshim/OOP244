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
	void display(Kingdom& King) {
		cout << King.m_name << ", population " << King.m_population << endl;
	} 
}