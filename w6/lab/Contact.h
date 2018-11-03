/**********************************************************
// Workshop 6: CLASS WITH A RESOURCE
// Contact.cpp
// Version Unknown
// 2017/06/23
// Chris Szalwinski
// Description
// In this workshop, you are to design and code a class type that accesses a resource.
//
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name			          Date		         Reason
// Kyuyoung Shim          06/23              removed sict::
///////////////////////////////////////////////////////////
**********************************************************/

#ifndef SICT_CONTACT_H
#define SICT_CONTACT_H
#define MAX_NAME_LENGTH 20

namespace sict {

	class Contact {
	private:
		char contactName[MAX_NAME_LENGTH];
		long long* phoneNum;
		int numOfPhoneNum;
	public:
		Contact();
		Contact(const char* nameOfContact, const long long* phoneNum, const int numOfPhoneNum);
		~Contact();
		bool isEmpty() const;
		void display() const;
	};

}
#endif // SICT_CONTACT_H