// Final Project Milestone 5
// Perishable.h
// Version 2.0
// Date	2017-12-16
// Authors:	Chris Szalwinski, Fardad Soleimanloo
//
//
//
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Kyuyoung Shim	  2017-12-21
/////////////////////////////////////////////////////////////////
#ifndef SICT_PERISHABLE_H
#define SICT_PERISHABLE_H
#include <iostream>
#include <fstream>
#include "NonPerishable.h"
#include "Date.h"

namespace sict {
	class Perishable : public NonPerishable {
	private:
		Date m_expiryDate;
	public:
		Perishable();
		std::fstream& store(std::fstream& file, bool newLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);
		const Date& expiry() const;
	};
}
#endif