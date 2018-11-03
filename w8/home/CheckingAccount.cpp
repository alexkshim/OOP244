/**********************************************************
// Workshop 8: Virtual Functions
// CheckingAccount.cpp
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

#include "CheckingAccount.h"

using namespace std;

namespace ict{    
	
	// Constructor: If transaction fee is less than zero, the transactionFee will be set to zero
	CheckingAccount::CheckingAccount(double inBalance, double transFee) : Account(inBalance) {
		if (transFee < 0) {
			transactionFee = 0;
		}
		else {
			transactionFee = transFee;
		}
	}

	// A member function that updates the balance by deducting the transactionFee from the balance
	void CheckingAccount::chargeFee() {
		double calBalance = getBalance();
		calBalance -= transactionFee;
		setBalance(calBalance);
	}

	// Override member functions debit for class CheckingAccount so that 
	// it subtracts the transactionFee from the account balance (call chargeFee)
	bool CheckingAccount::debit(double transFee) {
		bool success;
		if (Account::debit(transFee) && transactionFee > 0) {
			success = true;
			chargeFee();
		}
		return success;
	}

	// Override member functions credit for class CheckingAccount so that
	// it subtracts the transactionFee from the account balance (call chargeFee).
	void CheckingAccount::credit(double transFee) {
		Account::credit(transFee);
		chargeFee();
	}

	// Override the display function in the Account class 
	// that insert that print a SavingsAccount in the following format (example):
	ostream& CheckingAccount::display(std::ostream& ostr) {
		ostr << "Account type: Checking" << endl;
		ostr << "Balance: $ " << getBalance() << endl;
		ostr.setf(ios::fixed);
		ostr.precision(2);
		ostr << "Transaction Fee: " << transactionFee << endl;
		return ostr;
	}

}