/**********************************************************
// Workshop 3: Classes and Privacy
// CRA_Account.h
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

#ifndef SICT_KINGDOM_H
#define SICT_KINGDOM_H

#define MAX_NAME_LENGTH 40
#define MIN_SIN 100000000
#define MAX_SIN 999999999
#define MAX_YRS 4

namespace sict {

	class CRA_Account {
		char familyName[MAX_NAME_LENGTH + 1];
		char givenName[MAX_NAME_LENGTH + 1];
		int sin;
		int m_year[MAX_YRS];
		double m_balance[MAX_YRS];
		int m_years;
	public:
		CRA_Account();
		void set(const char* familyName, const char* givenName, int sin);
		bool isValid() const;
		void display() const;
		void set(int year, double balance);
	};

}

#endif // SICT_KINGDOM_H
