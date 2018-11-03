/**********************************************************
// Workshop 5: MEMBER OPERATOR OVERLOADS
// Fraction.h
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

#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H

namespace sict {

	class Fraction {
	private:
		int gcd() const; // returns the greatest common divisor of num and denom
		int max() const; // returns the maximum of num and denom
		int min() const; // returns the minimum of num and denom
		void reduce();   // simplifies a Fraction by dividing the numerator and denominator to their greatest common divisor
		int numerator;
		int denominator;
	public:
		Fraction();
		Fraction(int numerator, int denominator);
		bool isEmpty() const;
		void display() const;
		Fraction operator+(const Fraction& fracObj)const;
		Fraction operator*(const Fraction& fracObj)const;
		bool operator==(const Fraction& fracObj)const;
		bool operator!=(const Fraction& fracObj)const;
		const Fraction& operator+=(const Fraction& fracObj);
		// in order as the instruction indicates
	};

}
#endif // SICT_FRACTION_H