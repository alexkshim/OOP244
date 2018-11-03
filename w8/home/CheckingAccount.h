/**********************************************************
// Workshop 8: Virtual Functions
// CheckingAccount.h
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

#ifndef SICT_CHECKINGACCOUNT_H__
#define SICT_CHECKINGACCOUNT_H__

#include "Account.h"

using namespace std;

namespace ict{

	class CheckingAccount : public Account {
	
	private:
		double transactionFee;
		void chargeFee();

	public: 
		CheckingAccount(double inBalance, double transFee);
		virtual bool debit(double transFee);
		virtual void credit(double transFee);
		virtual ostream& display(std::ostream& ostr);

	};

};
#endif
