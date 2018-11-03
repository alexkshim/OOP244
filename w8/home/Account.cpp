/**********************************************************
// Workshop 8: Virtual Functions
// Account.cpp
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

#include "Account.h"

using namespace std;

namespace ict{ 
	
	// constructor   
	Account::Account(double balance_) {
		if (balance_ >= 0) {
			this->balance = balance_;
		}
		else {
			this->balance = 1.0;
		}

	}

	// credit (add) an amount to the account balance
	void Account::credit(double incomingAmout) {
		this->balance += incomingAmout;
	}
	
	// debit (subtract) an amount from the account balance return bool 
	bool Account::debit(double debitAmount) {

		if (debitAmount <= this->balance) {
			this->balance -= debitAmount;
			return true;
		}
			return false;

	}

	// return the member of balance (getter)
	double Account::getBalance() const
	{
		return balance;
	} 

	// set the balance to the new balance (setter)
	void Account::setBalance( double newBalance )
	{
		balance = newBalance;
	} 

}