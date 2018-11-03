// Final Project Milestone 5
// Version 1.0
// Date	2017-07-??
// Author	Fardad Soleimanloo
// Streamable.h
// Code the Streamable class in a file called Streamable.h.
// 
//
//
// Revision History
// -----------------------------------------------------------
// Name   Kyuyoung Shim   Date  2017-07-27  Reason
/////////////////////////////////////////////////////////////////
#ifndef SICT_STREAMABLE_H
#define SICT_STREAMABLE_H
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

namespace sict {

	class Streamable {
	public:
		virtual std::fstream& store(fstream& file, bool addNewLine = true)const = 0;
		virtual std::fstream& load(std::fstream& file) = 0;
		virtual std::ostream& write(ostream& os, bool linear)const = 0;
		virtual std::istream& read(istream& is) = 0;
	};


}
#endif