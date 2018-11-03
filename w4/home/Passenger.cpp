/**********************************************************
// Workshop 4: CONSTRUCTORS
// Passenger.cpp
// Version Unknown
// 2017/06/??
// Chris Szalwinski
// Description
// In this workshop, you are to initialize the data within an object of class type up-on its creation.
//
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name			          Date		         Reason
// Kyuyoung Shim          06/13              removed sict::
///////////////////////////////////////////////////////////
**********************************************************/

#include <iostream>
#include <cstring>
#include "Passenger.h"

using namespace std;

namespace sict {

	// default constructor: this constructor sets the object to a safe empty state, including the date variables
	Passenger::Passenger() {
		safeEmpty();
	}
	
	// I considered using safe setting three times with the same long code is just waste.
	// that is why I made a function for safe empty setting and used above and others below.
	void Passenger::safeEmpty() { 
		passenger_name[0] = '\0';
		destination[0] = '\0';
		yearOfDepart = 0;
		monthOfDepart = 0;
		dayOfDepart = 0;
	}

	// constructor with 2 parameters: The first parameter receives the name of the passenger 
	// and the second parameter receives the name of the destination.  
	// This copies data from into the instance variables and sets the departure date to July 1st, 2017, only if the data is valid. 
	Passenger::Passenger (const char* addOfPsg, const char* destination) {
		if (!isEmpty()) {
			strncpy(passenger_name, addOfPsg, MAX_NAME_LEN);
			strncpy(this->destination, destination, MAX_NAME_LEN);
			this->yearOfDepart = 2017;
			this->monthOfDepart = 7;
			this->dayOfDepart = 1;
		}
		else {
			safeEmpty();
		}
	}
	
	// constructor with 5 parameters: this constructor copies data to everything in the class if valid, otherwise set empty status.
	Passenger::Passenger (const char* nameOfPsg, const char* nameOfDsn, const int& years, const int& months, const int& days) {
		int validity = 0;
		
		if (nameOfPsg != nullptr && nameOfPsg != '\0') {
			validity++;
		}
		if (nameOfDsn != nullptr && nameOfDsn != '\0') {
			validity++;
		}
		if (years == 2017 || years == 2018 || years == 2019 || years == 2020) {
			validity++;
		}
		if (months >= 1 && months <= 12) {
			validity++;
		}
		if (days >= 1 && days <= 31) {
			validity++;
		}

		if (validity == 5) {
			strncpy(passenger_name, nameOfPsg, MAX_NAME_LEN);
			passenger_name[MAX_NAME_LEN - 1] = '\0';
			strncpy(destination, nameOfDsn, MAX_NAME_LEN);
			passenger_name[MAX_NAME_LEN - 1] = '\0';
			yearOfDepart = years;
			monthOfDepart = months;
			dayOfDepart = days;
		}
		else {
			safeEmpty();
		}

	}

	// A query that reports if the Passenger object is in a safe empty state.
	bool Passenger::isEmpty() const {
		bool emptyOrNot = true;

		if (passenger_name[0] && destination[0]) {
			emptyOrNot = false;
		}

		return emptyOrNot;
	}

	// A query that displays the contents of the Passenger object
	void Passenger::display() const {
		cout << passenger_name << " - " << destination << " on " << yearOfDepart << '/';
		cout.width(2);
		cout.fill('0');
		cout.setf(ios::right);
		cout << monthOfDepart << '/';
		cout.width(2);
		cout.fill('0');
		cout.setf(ios::right);
		cout << dayOfDepart << endl;
	}

	// a query that returns the address of the name of the passenger; 
	// the address of an empty string if the Passenger object is in a safe empty state.
	const char* Passenger::name() const {
		return passenger_name;
	}

	// a query that receives an unmodifiable reference to a Passenger ob-ject 
	// and checks if that passenger referenced can travel with the cur-rent Passenger 
	bool Passenger::canTravelWith(const Passenger& refPsg) const {
		bool CanOrNot = false;

		if (!strcmp(refPsg.destination, this->destination)) {
			if (refPsg.yearOfDepart == this->yearOfDepart
				&& refPsg.monthOfDepart == this->monthOfDepart
				&& refPsg.dayOfDepart == this->dayOfDepart) {
				CanOrNot = true;
			}
		}

		return CanOrNot;
	}

}
