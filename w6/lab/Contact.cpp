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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Contact.h"

using namespace std;

namespace sict {

	// this default constructor sets the current object to a safe empty state
	Contact::Contact() {
		contactName[0] = '\0';
		contactName[MAX_NAME_LENGTH - 1] = '\0';
		phoneNum = nullptr;
		numOfPhoneNum = 0;
	}

	// this constructor receives the address of an unmodifiable C-style string that holds the name of the contact, 
	// the address of an unmodifiable array of phone numbers and the number of phone numbers in the array.
	Contact::Contact(const char* nameOfContact, const long long* phoneNum_, const int numOfPhoneNum_) {
		int numCount = 0;
		
		if (nameOfContact != nullptr && phoneNum_ != nullptr && numOfPhoneNum_ > 0) {
			strncpy(contactName, nameOfContact, MAX_NAME_LENGTH);
			contactName[MAX_NAME_LENGTH - 1] = '\0';
			phoneNum = new long long[numOfPhoneNum_];
			for (int i = 0; i < numOfPhoneNum_; i++) {
				if (phoneNum_[i] < 1000000000000 && phoneNum_[i] >= 10000000000) {
					phoneNum[numCount] = phoneNum_[i];
					numCount++;
				}
			}
			numOfPhoneNum = numCount;
		}
		else if(nameOfContact != nullptr) {
			strncpy(contactName, nameOfContact, MAX_NAME_LENGTH);
			contactName[MAX_NAME_LENGTH - 1] = '\0';
			phoneNum = nullptr;
			numOfPhoneNum = numOfPhoneNum_;
		}
		else {
			contactName[0] = '\0';
			phoneNum = nullptr;
			numOfPhoneNum = 0;
		}

	}

	// this destructor deallocates any memory that has been allocated dynamically
	Contact::~Contact() {
		delete[] this->phoneNum;
	}

	// a query that returns false if the current object has valid data; true if the object is in a safe empty state
	bool Contact::isEmpty() const {
		return contactName[0] == '\0' && phoneNum == nullptr && numOfPhoneNum == 0;
	}

	// a query that prints the data stored by the object in the following format with the seperation of phone numbers
	void Contact::display() const {
		int countryCode = 0;
		int areaCode = 0;
		int prefix = 0;
		int suffix = 0;
		
		if (isEmpty()) {
			cout << "Empty contact!" << endl;
		}
		else {
			cout << contactName << endl;
			for (int i = 0; i < this->numOfPhoneNum; i++) {
				countryCode = (int)(phoneNum[i] / 10000000000);
				areaCode = (int)(phoneNum[i] / 10000000) % 1000 ;
				prefix = (int)(phoneNum[i] / 10000) % 1000;
				suffix = (int)(phoneNum[i] % 10000);
				cout << "(+" << countryCode << ") " << areaCode << ' ' << prefix << '-' << suffix << endl;
			}
		}
	}

}