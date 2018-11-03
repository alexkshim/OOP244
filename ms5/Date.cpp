// Final Project Milestone 5
// Date.cpp
// Version 2.0
// Date	2017-12-16
// Authors:	Chris Szalwinski, Fardad Soleimanloo
//
//
//
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Kyuyoung Shim	  2017-12-21
/////////////////////////////////////////////////////////////////
#include <iostream>
#include <iomanip>
#include "Date.h"

namespace sict {
	
	// This function is optional to minimize code duplications and sets member data by default
	void Date::setEmpty() {
		m_year = 0;
		m_mon = 0;
		m_day = 0;
		m_cmpValue = 0;
	}

	// No argument (default) constructor setting member data by default
	Date::Date() {
		setEmpty();
		errCode(NO_ERROR);
	}

	// This constructor checks if each number is in range, in the order of year, month and day.
	Date::Date(const int year, const int month, const int day) {
		if (year >= min_year && year <= max_year) {
			m_year = year;
			if (month >= 1 && month <= 12) {
				m_mon = month;
				if (day >= 1 && day <= mdays(month, year)) {
					errCode(NO_ERROR);
					m_day = day;
					m_cmpValue = year * 372 + month * 13 + day;
				}
				else {
					errCode(DAY_ERROR);
					setEmpty();
				}
			}
			else {
				errCode(MON_ERROR);
				setEmpty();
			}
		}
		else {
			errCode(YEAR_ERROR);
			setEmpty();
		}

	}

	// number of days in month mon_ and year year_
	//
	int Date::mdays(int mon, int year)const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}

	// This function sets the error state variable to one of the values listed above.
	void Date::errCode(int errorCode) {
		m_readErrorCode = errorCode;
	}

	// These comparison operators return the result of comparing the current object as the left-hand side operand with another Date object as 
	// the right-hand side operand if the two objects are not empty. If one or both of them is empty, these operators return false.
	bool Date::operator==(const Date& rhs)const {
		if (this == &rhs) {
			return true;
		}
		return (m_cmpValue == rhs.m_cmpValue);
	}
	bool Date::operator!=(const Date& rhs)const {
		return !(*this == rhs);
	}
	bool Date::operator<(const Date& rhs)const {

		if (*this == rhs) {
			return false;
		}
		return (m_cmpValue < rhs.m_cmpValue);

	}
	bool Date::operator>(const Date& rhs)const {
		if (*this == rhs) {
			return false;
		}
		return !(*this < rhs);
	}
	bool Date::operator<=(const Date& rhs)const {
		if (*this == rhs) {
			return true;
		}
		return (*this < rhs);
	}
	bool Date::operator>=(const Date& rhs)const {
		if (*this == rhs) {
			return true;
		}
		return !(*this < rhs);
	}

	// This query returns the error state as an error code value.
	int Date::errCode() const {
		return m_readErrorCode;
	}

	// This query returns true if the error state is not NO_ERROR. 
	bool Date::bad() const {
		return (errCode() != 0) ? true : false;
	}

	// This function reads the date from the console in the following format: YYYY?MM?DD
	// and then returns a reference to the std::istream object. 
	std::istream& Date::read(std::istream& istr) {
		char ch;

		istr >> m_year >> ch >> m_mon >> ch >> m_day;
		if (!istr.fail()) {
			if (m_year >= min_year && m_year <= max_year) {
				errCode(NO_ERROR);
				if (m_mon >= 1 && m_mon <= 12) {	
					errCode(NO_ERROR);
					if (m_day >= 1 && m_day <= mdays(m_mon, m_year)) {
						errCode(NO_ERROR);
					}
					else {
						setEmpty();
						errCode(DAY_ERROR);
					}
				}
				else {
					setEmpty();
					errCode(MON_ERROR);
				}
			}
			else {
				setEmpty();
				errCode(YEAR_ERROR);
			}
		}
		else {
			setEmpty();
			errCode(CIN_FAILED);
			istr.fail();
		}

		return istr;
	}

	// This query writes the date to an std::ostream object in the following format: YYYY/MM/DD, 
	// and then returns a reference to the std::ostream object.
	std::ostream& Date::write(std::ostream& ostr)const {
		ostr << m_year << '/' << std::setw(2) << std::setfill('0') 
			<< std::right << m_mon << '/' << std::setw(2) << std::setfill('0')
			<< std::right << m_day;

		return ostr;
	}

	// This operator works with an std::ostream object to print a date to the console.
	std::ostream& operator<<(std::ostream& os, const Date& s) {
		s.write(os);
		return os;
	}

	// This operator works with an std::istream object to read a date from the console.
	std::istream& operator>>(std::istream& is, Date& s) {
		s.read(is);
		return is;
	}

}
