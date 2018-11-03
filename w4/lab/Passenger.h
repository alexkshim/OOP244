#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H

namespace sict {

	class Passenger {
	private:
		char passenger_name[32];
		char destination[32];
	public:
		Passenger();
		Passenger(const char* nameOfPsg, const char* nameOfDsn);
		bool isEmpty() const;
		void display() const;
	};

}

#endif // SICT_PASSENGER_H