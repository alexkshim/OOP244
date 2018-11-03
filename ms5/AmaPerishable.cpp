// Final Project Milestone 5
// Version 1.0
// Date	2017-07-10
// Author   Fardad Soleimanloo
// AmaPreishable.cpp
// 
// 
//
//
// Revision History
// -----------------------------------------------------------
// Name Kyuyoung Shim  Date 2017-07-27   Reason
/////////////////////////////////////////////////////////////////

#include "Streamable.h"
#include "AmaPerishable.h"
#include "AmaProduct.h"

using namespace std;

namespace sict {

	// default constructor that invokes the AmaProduct constructor passing the value ‘P’ for the fileTag argument.
	AmaPerishable::AmaPerishable() : AmaProduct('P') {

	}

	// Returns a constant reference to expiry_ member variable.
	const Date& AmaPerishable::expiry()const {
		return this->expiry_;
	}

	// Sets the expiry_ attribute to the incoming value.
	void AmaPerishable::expiry(const Date &value) {
		this->expiry_ = value;
	}

	// Calls the parent’s store passing the file and “false” as arguments and then writes a comma and the expiry date into the file. 
	fstream& AmaPerishable::store(fstream& file, bool addNewLine)const {
		AmaProduct::store(file, false);
		file << ',' << this->expiry_;
		if (addNewLine == true) {
			file << endl;
		}
		return file;
	}

	// Calls the parent’s load passing the file as the argument and then calls the read method of the expiry_ object 
	// passing the file as the argument and then ignores one character 
	fstream& AmaPerishable::load(fstream& file) {
		AmaProduct::load(file);
		file.ignore();
		expiry_.read(file);
		
		return file;
	}

	// Calls the write of the parent passing ostr and linear as arguments. Then if err_ is clear and product is not empty
	ostream& AmaPerishable::write(ostream& ostr, bool linear)const {
		
		if (this->err_.isClear() && !(this->isEmpty())) {
			AmaProduct::write(ostr, linear);
			if (linear == true) {
				ostr << expiry();
			}
			else {
				ostr << "\nExpiry date: " << expiry();
			}
		}
		else {
			ostr << err_.message();
		}

		return ostr;
	}

	// read function checking validity and set the error message if found
	istream& AmaPerishable::read(istream& istr) {
		Date tempExp;
		AmaProduct::read(istr);
		if (this->err_.isClear()) {
			cout << "Expiry date (YYYY/MM/DD): ";
			tempExp.read(istr);

			if (tempExp.bad()) {
				istr.setstate(ios::failbit);
				if (tempExp.errCode() == CIN_FAILED) {
					istr.setstate(ios::failbit);
					err_.message("Invalid Date Entry");
				}
				else if (tempExp.errCode() == YEAR_ERROR) {
					istr.setstate(ios::failbit);
					this->err_.message("Invalid Year in Date Entry");
				}
				else if (tempExp.errCode() == MON_ERROR) {
					istr.setstate(ios::failbit);
					this->err_.message("Invalid Month in Date Entry");
				}
				else if (tempExp.errCode() == DAY_ERROR) {
					istr.setstate(ios::failbit);
					this->err_.message("Invalid Day in Date Entry");
				}
			}
			else {
				expiry(tempExp);
			}

		}
		return istr;
	}

}