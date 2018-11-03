/**********************************************************
// Workshop 8: Virtual Functions
// SavingsAccount.cpp
// Version Unknown
// 2017/07/??
//
// Description
// In this workshop, you are to implement specific behavior
// based on an abstract definition of that behavior.
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name			          Date		         Reason
// Kyuyoung Shim          07/25
///////////////////////////////////////////////////////////
**********************************************************/

#include "SavingsAccount.h"
#include <cstring>
#include <iomanip>
#include <cmath>

using namespace std;

namespace ict{ 
	
	// constructor that receives the initial balance, as well as an initial value for the SavingsAccount’s interest rate, 
	// and then initializes the object. If interest rate is less than zero, the interstRate will be set to zero. 
	SavingsAccount::SavingsAccount(double balance_, double inRate) : Account(balance_) {
		if (inRate < 0) {
			inRate = 0;
		}
		else {
			interestRate = inRate;
		}
	}

	// Member function calculateInterest should determine this amount by multiplying the interest rate by the account balance. 
	double SavingsAccount::calculateInterest() {
		return this->getBalance() * interestRate ;
	}

	// Override the display function in the Account class that print a SavingsAccount in the following format
	ostream& SavingsAccount::display(ostream& ostr) {
		ostr << "Account type: Saving" << endl;
		ostr << "Balance: $ " << fixed << setprecision(2) << fabs(getBalance()) << endl;
		ostr << "Interest Rate (%): " << this->interestRate * 100 << endl;
		return ostr;
	}

}