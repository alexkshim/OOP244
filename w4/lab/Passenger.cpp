#include <iostream>
#include <cstring>
#include "Passenger.h"

using namespace std;

namespace sict {

	Passenger::Passenger() {
		passenger_name[0] = 0;
		destination[0] = 0;
	}

	Passenger::Passenger (const char* nameOfPsg, const char* nameOfDsn) {
		if (nameOfPsg != nullptr && nameOfPsg != '\0') {
			strncpy(passenger_name, nameOfPsg, 32);
		}
		else {
			passenger_name[0] = 0;
		}

		if (nameOfDsn != nullptr && nameOfDsn != '\0') {
			strncpy(destination, nameOfDsn, 32);
		}
		else {
			destination[0] = 0;
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
		cout << passenger_name << " - " << destination << endl;
	}

}
