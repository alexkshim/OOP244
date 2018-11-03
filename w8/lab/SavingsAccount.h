/**********************************************************
// Workshop 7: Virtual Functions
// SavingsAccount.h
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
// Kyuyoung Shim          07/20
///////////////////////////////////////////////////////////
**********************************************************/

#ifndef SICT_SAVINGSACCOUNT_H__
#define SICT_SAVINGSACCOUNT_H__

#include "Account.h"

using namespace std;

namespace ict{

	class SavingsAccount : public Account {

	private:
		double interestRate;

	public:
		SavingsAccount(double balance_, double inRate);
		double calculateInterest();
		ostream& display(ostream& ostr);

	};

};
#endif
