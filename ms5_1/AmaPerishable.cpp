// AmaPersishable.cpp
#include "AmaPerishable.h"
#include "AmaProduct.h"
#include "Streamable.h"

using namespace std;

namespace sict {

	AmaPerishable::AmaPerishable() : AmaProduct('P') {

	}

	const Date& AmaPerishable::expiry()const {
		return this->expiry_;
	}

	void AmaPerishable::expiry(const Date &value) {
		this->expiry_ = value;
	}

	fstream& AmaPerishable::store(fstream& file, bool addNewLine)const {
		//this->store(file, false);
		this->store(file);
		file << "," << this->expiry_;
		if (addNewLine == true) {
			file << "\n";
		}
		return file;
	}

	fstream& AmaPerishable::load(fstream& file) {
		this->load(file);
		expiry_.read(file);
		file.ignore();
		return file;
	}

	ostream& AmaPerishable::write(ostream& ostr, bool linear)const {
		this->write(ostr, linear);
	
		if (this->err_.isClear() && !(this->isEmpty())) {
			if (linear == true) {
				ostr << expiry();
			}
			else {
				//ostr << endl;
				ostr << "Expiry date: " << expiry();
			}
		}

		return ostr;
	}

	istream& AmaPerishable::read(istream& istr) {
		Date tempExp;

		this->read(istr);

		if (this->err_.isClear()) {
			cout << "Expiry date (YYYY/MM/DD): ";
			istr >> tempExp;
		}
		else if (tempExp.errCode() == CIN_FAILED) {
			this->err_.message("Invalid Date Entry");
			istr.setstate(ios::failbit);
		}
		else if (tempExp.errCode() == YEAR_ERROR) {
			this->err_.message("Invalid Year in Date Entry");
			istr.setstate(ios::failbit);
		}
		else if (tempExp.errCode() == MON_ERROR) {
			this->err_.message("Invalid Month in Date Entry");
			istr.setstate(ios::failbit);
		}
		else if (tempExp.errCode() == DAY_ERROR) {
			this->err_.message("Invalid Day in Date Entry");
			istr.setstate(ios::failbit);
		}
		else {
			expiry(tempExp);
		}

		return istr;
	}

}