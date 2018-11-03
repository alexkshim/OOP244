/**********************************************************
// Workshop 5: MEMBER OPERATOR OVERLOADS
// Fraction.cpp
// Version Unknown
// 2017/06/20
// Chris Szalwinski
// Description
// In this workshop, you are to overload member operators for a class type.
//
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name			          Date		         Reason
// Kyuyoung Shim          06/15              removed sict::
///////////////////////////////////////////////////////////
**********************************************************/

#include <iostream>
#include <cstring> // I may not need this
#include "Fraction.h"

using namespace std;

namespace sict {
	
	// this constructor sets the object to a safe empty state
	Fraction::Fraction() {
		numerator = -1;
		denominator = -1;
	}
	
	// receives the numerator and denominator of a fraction and stores the data only if it is valid.
	Fraction::Fraction(int numerator, int denominator) {
		if (numerator >= 0 && denominator > 0) {
			this->numerator = numerator;
			this->denominator = denominator;
			reduce();
		}
		else {
			this->numerator = -1;
			this->denominator = -1;
		}
	}
	
	// max returns the maximum of the numerator and denominator
	int Fraction::max() const {
		return (numerator >= denominator) ? numerator : denominator;
	}

	// min returns the maximum of the numerator and denominator
	int Fraction::min() const {
		return (numerator <= denominator) ? numerator : denominator;
	}

	// gcd returns the greatest common divisor of num and denom
	int Fraction::gcd() const {
		int mn = min();  // min of numerator and denominator
		int mx = max();  // max of numerator and denominator
		int g_c_d = 1;
		bool found = false;

		for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
			if (mx % x == 0 && mn % x == 0) {
				found = true;
				g_c_d = x;
			}
		}
		return g_c_d;
	}
	
	// reduce simplifies the fraction by dividing the numerator and denominator by the greatest common divisor
	void Fraction::reduce() {
		int gDivisor = 0;
		gDivisor = gcd();
		numerator /= gDivisor;
		denominator /= gDivisor;
	}

	// display inserts num/denom into the output stream
	void Fraction::display() const {
		if (!isEmpty()) {
			if (denominator == 1) {
				cout << numerator;
			}
			else {
				cout << numerator << '/' << denominator;
			}
		}
		else {
			cout << "no fraction stored";
		}
	}

	// isEmpty returns true if Fraction object is in a safe empty state
	bool Fraction::isEmpty() const {

		return numerator == -1 && denominator == -1;
	}

	// + operator adds the rhs to the current object and reduces the result
	Fraction Fraction::operator+(const Fraction& fracObj)const {
		Fraction calVal;

		if (!isEmpty()) {
			calVal.numerator = ((this->numerator * fracObj.denominator) + (fracObj.numerator * this->denominator));
			calVal.denominator = (this->denominator * fracObj.denominator);
			calVal.reduce();
		}
		
		return calVal;
	}

	// If both of the operands are valid fractions, your function returns a copy of the result of the multiplication operation in reduced form.  
	// If either operand is in a safe empty state, your function returns a Fraction object in a safe empty state.
	Fraction Fraction::operator*(const Fraction& fracObj)const {
		Fraction result;

		if (!isEmpty()) {
			result.numerator = (this->numerator * fracObj.numerator);
			result.denominator = (this->denominator * fracObj.denominator);
			result.reduce();
		}
		else {
			result = *this;
		}

		return result;
	}

	// If both of the operands are valid fractions of equal value, your function returns true; otherwise false.
	bool Fraction::operator==(const Fraction& fracObj)const {
		bool validity = false;

		if (!isEmpty()) {
			if ((this->numerator * fracObj.denominator) == (this->denominator * fracObj.numerator)) {
				validity = true;
			}
		}

		return validity;
	}

	// If both of the operands are valid fractions of unequal value, your function returns true; otherwise false.
	bool Fraction::operator!=(const Fraction& fracObj)const {
		bool validity = false;

		if (isEmpty()) {
			if ((this->numerator * fracObj.denominator) != (this->denominator * fracObj.numerator)) {
				validity = true;
			}
		}

		return validity;
	}

	// If both of the operands are valid fractions, your function stores the result of 
	// the addition operation in reduced form in its instance variables and returns a reference to the current object.
	// If either operand is in a safe empty state, your function stores a Fraction object 
	// in a safe empty state and returns a reference to the current object.
	const Fraction& Fraction::operator+=(const Fraction& fracObj) {

		if (!isEmpty()) {
			*this = Fraction::operator+(fracObj); // re-using the operator+
		}

		return *this;
	}

}

