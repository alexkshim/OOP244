// Final Project Milestone 5
// Perishable.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Perishable.h"


namespace sict {

	// This constructor passes the file record tag for a perishable product (‘P? to the base class constructor and sets the current object to a safe empty state
	Perishable::Perishable() : NonPerishable('P') {
		NonPerishable();
	}

	// This function stores a file record for the current object and calls its base class version passing as arguments a reference to the fstream object and a false flag
	std::fstream& Perishable::store(std::fstream& file, bool newLine) const {
		NonPerishable::store(file, false);
		file << ',' << m_expiryDate; // expiry();
		if (newLine == true) {
			file << std::endl;
		}

		return file;
	}

	// This function extracts the fields for a single file record from the fstream object and calls its base class version passing as an argument a reference to the fstream object
	std::fstream& Perishable::load(std::fstream& file) {
		NonPerishable::load(file);
		file.ignore();
		m_expiryDate.read(file); // expiry().

		return file;
	}

	// This function calls its base class version passing as arguments a reference to the ostream object and the bool flag
	std::ostream& Perishable::write(std::ostream& os, bool linear) const {
		if (this->isClear() && !(this->isEmpty())) {
			NonPerishable::write(os, linear);
			if (linear == false) {
				os << "\nExpiry date: ";
			}
			os << expiry();
		}

		return os;
	}

	// This function calls its base class version passing as its argument a reference to the istream object
	std::istream& Perishable::read(std::istream& is) {
		Date tempExp;
		NonPerishable::read(is);
		if (this->isClear()) {
			std::cout << "Expiry date (YYYY/MM/DD): ";
			tempExp.read(is);

			if (tempExp.bad()) {
				is.setstate(std::ios::failbit);
				if (tempExp.errCode() == CIN_FAILED) {
					is.setstate(std::ios::failbit);
					this->message("Invalid Date Entry");
				}
				else if (tempExp.errCode() == YEAR_ERROR) {
					is.setstate(std::ios::failbit);
					this->message("Invalid Year in Date Entry");
				}
				else if (tempExp.errCode() == MON_ERROR) {
					is.setstate(std::ios::failbit);
					this->message("Invalid Month in Date Entry");
				}
				else if (tempExp.errCode() == DAY_ERROR) {
					is.setstate(std::ios::failbit);
					this->message("Invalid Day in Date Entry");
				}
			}
			else {
				expiry();
			}

		}
		return is;
	}

	// This query returns the expiry date for the perishable product
	const Date& Perishable::expiry() const {
		return m_expiryDate;
	}

	// A helper that creates a Perishable object in dynamic memory and returns its address
	Product* CreatePerishable() {
		Product* pObj = nullptr;
		pObj = new Perishable;
		return pObj;
	}
}