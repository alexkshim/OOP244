/**********************************************************
// Workshop 4: CONSTRUCTORS
// Passenger.h
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

#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H
#define MAX_NAME_LEN 32

namespace sict {

	class Passenger {
	private:
		char passenger_name[MAX_NAME_LEN];
		char destination[MAX_NAME_LEN];
		int yearOfDepart;
		int monthOfDepart;
		int dayOfDepart;
	public:
		Passenger();
		Passenger(const char* addOfPsg, const char* destination);
		Passenger(const char* nameOfPsg, const char* nameOfDsn, const int& years, const int& months, const int& days);
		bool isEmpty() const;
		void display() const;
		const char* name() const;
		bool canTravelWith(const Passenger&) const;
		void safeEmpty(); // this is optional I made, explained above its definition.
	};

}

#endif // SICT_PASSENGER_H