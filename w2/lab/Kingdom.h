/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.h
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

// TODO: header safeguards
#ifndef SICT_KINGDOM_H_
#define SICT_KINGDOM_H_

// TODO: sict namespace
namespace sict {
	// TODO: define the structure Kingdom in the sict namespace
	struct Kingdom
	{
		char m_name[32];
		int m_population;
	};
	// TODO: declare the function display(...),
	//         also in the sict namespace
	void display(Kingdom& king);
}

#endif // SICT_KINGDOM_H_