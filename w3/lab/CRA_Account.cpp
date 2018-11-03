/**********************************************************
// Workshop 3: Classes and Privacy
// CRA_Account.cpp
// Version 1.1
// 2017/05/10
// Chris Szalwinski
// Description
// This workshop demonstrates classes in C++ and
// how member variables are defined privately, but
// accessed through public member functions
//
// Revision History
///////////////////////////////////////////////////////////
// Name			          Date		         Reason
// Kyuyoung Shim          06/01              removed sict::
///////////////////////////////////////////////////////////
**********************************************************/

#include <iostream>
#include "CRA_Account.h"
#include "string.h"

using namespace std;

namespace sict {

	// if sin is a valid SIN, this function stores the family and given names on the account along with the SIN.
	// If sin is not a valid SIN, this function stores values that identify an empty state.
	void CRA_Account::set(const char* familyName, const char* givenName, int sin) {
		if (MIN_SIN <= sin && MAX_SIN >= sin) {
			strcpy(this->familyName, familyName);
			strcpy(this->givenName, givenName);
			this->sin = sin;
		}
		else {
			this->familyName[0] = '\0';
			this->givenName[0] = '\0';
			this->sin = 0;
		}
	}

	// returns the validity of the SIN stored in the object.
	bool CRA_Account::isValid() const {
		bool validity = false;

		if (MIN_SIN <= this->sin && MAX_SIN >= this->sin) {
			// this-> is not necessary
			validity = true;
		}

		return validity;
	}

	// if the object is not empty, this function inserts into the standard output stream 
	// the content of the current instance 
	void CRA_Account::display() const {
		if (isValid()) {
			cout << "Family Name: " << this->familyName << endl;
			cout << "Given Name : " << this->givenName << endl;
			cout << "CRA Account: " << this->sin << endl;
			// this-> is not necessary but for my learning
		}
		else {
			cout << "Account object is empty!" << endl;
		}
	}

}