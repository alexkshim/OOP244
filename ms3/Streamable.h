// Final Project Milestone 3
// Version 1.0
// Date	2017-07-06
// Author	Fardad Soleimanloo
//
// Code the Streamable class in a file called Streamable.h.
// 
//
//
// Revision History
// -----------------------------------------------------------
// Name   Kyuyoung Shim   Date  12 July 2017   Reason
/////////////////////////////////////////////////////////////////
#ifndef SICT_STREAMABLE_H__
#define SICT_STREAMABLE_H__
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

namespace sict {

	class Streamable {
	public:
		virtual std::fstream& store(fstream& file, bool addNewLine = true)const { return file; }
		virtual std::fstream& load(std::fstream& file) { return file; }
		virtual std::ostream& write(ostream& os, bool linear)const { return os; }
		virtual std::istream& read(istream& is) { return is; }
	};


}
#endif