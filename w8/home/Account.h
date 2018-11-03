/**********************************************************
// Workshop 8: Virtual Functions
// Account.h
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

#ifndef SICT_ACCOUNT_H__
#define SICT_ACCOUNT_H__

#include <iostream>

using namespace std;

namespace ict{
   
	class Account{
	
	private:	
		double balance; // data member that stores the balance
		
	protected:
		double getBalance() const; // return the account balance
		void setBalance( double ); // sets the account balance

	public:
		Account(double balance);
		virtual void credit(double incomingAmout);
		virtual bool debit(double debitAmount);			
		virtual ostream& display(ostream& ostr) = 0;
	
	};

};
#endif
