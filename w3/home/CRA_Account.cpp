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
#include <iomanip>
#include <cmath>
#include "CRA_Account.h"
#include "string.h"

using namespace std;

namespace sict {

	// m_years in the class called CRA_Account is now initialized as 0
	CRA_Account::CRA_Account() {
		m_years = 0;
	}

	// stores the family and given names on the account along with the SIN(if sin is valid) 
	// and initializes the number of years for which data is stored to 0.
	void CRA_Account::set(const char* familyName, const char* givenName, int sin) {
		if (MIN_SIN <= sin && MAX_SIN >= sin) {
			strncpy(this->familyName, familyName, MAX_NAME_LENGTH + 1);
			strncpy(this->givenName, givenName, MAX_NAME_LENGTH + 1);
			this->sin = sin;
		}
		else {
			this->familyName[0] = '\0';
			this->givenName[0] = '\0';
			this->familyName[MAX_NAME_LENGTH] = '\0';
			this->givenName[MAX_NAME_LENGTH] = '\0';
			this->sin = 0;

			this->m_balance[0] = 0;
			this->m_balance[MAX_YRS - 1] = 0;
			this->m_year[0] = 0;
			this->m_year[MAX_YRS - 1] = 0;
			this->m_years = 0;
		}
	}

	// returns the validity of the SIN stored in the object.  
	bool CRA_Account::isValid() const {
		bool validity = false;

		if (MIN_SIN <= this->sin && MAX_SIN >= this->sin) {
			int checkDigit = 0;
			int evenPositionedSum = 0;
			int oddPositionedSum = 0;
			int total = 0;
			int isEndZero = 0;
			int difference = 0;

			checkDigit = this->sin % 10;	 // 9th (check digit)

			evenPositionedSum =				 // = 2nd + 4th + 6th + 8th
				(this->sin / 10000000 % 10)  // 1'2'3 - 456 - 789
				+ (this->sin / 100000 % 10)  // 123 - '4'56 - 789
				+ (this->sin / 1000 % 10)	 // 123 - 45'6' - 789 
				+ (this->sin / 10 % 10);	 // 123	- 456 - 7'8'9

			oddPositionedSum =				 // = 1st + 3rd + 5th + 7th
				(this->sin / 100000000)		 // '1'23 - 456 - 789
				+ (this->sin / 1000000 % 10) // 12'3' - 456 - 789
				+ (this->sin / 10000 % 10)	 // 123 - 4'5'6 - 789 
				+ (this->sin / 100 % 10);	 // 123 - 456 - '7'89

			total = evenPositionedSum + oddPositionedSum;

			isEndZero = total % 10;

			if (isEndZero == 0) {
				difference = isEndZero;
			}
			else {
				difference = 10 - isEndZero;
			}

			if (checkDigit == difference) {
				validity = true;
			}
		}

		return validity;
	}

	// if the object is not empty, inserts into the standard output stream the content of the object
	void CRA_Account::display() const {

		if (isValid()) {
			cout << "Family Name: " << this->familyName << endl;
			cout << "Given Name : " << this->givenName << endl;
			cout << "CRA Account: " << this->sin << endl;
			// this-> is not necessary but for my learning
			for (int i = 0; i < MAX_YRS; i++) {
				if (this->m_balance[i] > 2) {
					cout << "Year (" << this->m_year[i] << ") balance owing: " << this->m_balance[i] << endl;
				}
				else if (this->m_balance[i] < -2) {
					cout << "Year (" << this->m_year[i] << ") refund due: " << fixed << setprecision(2) << fabs(this->m_balance[i]) << endl;
				}
				else {
					cout << "Year (" << this->m_year[i] << ") No balance owing or refund due! " << endl;
				}
			}
		}
		else {
			cout << "Account object is empty!" << endl;
		}

	}

	// if the object has a valid SIN and has room to store the data received, 
	// this function stores year and balance in the object. If not, this function does nothing.
	void CRA_Account::set(int year, double balance) {
		if (isValid() && m_years != MAX_YRS) {
			m_year[m_years] = year;
			m_balance[m_years] = balance;
			m_years++;
		}
	}

}