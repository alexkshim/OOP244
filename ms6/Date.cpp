// Final Project Milestone 6
// Version 1.0
// Date	2017-07-10
// Author   Fardad Soleimanloo
// Date.cpp
// 
// 
//
//
// Revision History
// -----------------------------------------------------------
// Name Kyuyoung Shim   Date 2017-08-06   Reason
/////////////////////////////////////////////////////////////////

#include "Date.h"
#include "general.h"

using namespace std;

namespace sict {

	// No argument (default) constructor setting all variables by default
	Date::Date() {
		this->year_ = 0;
		this->mon_ = 0;
		this->day_ = 0;
		readErrorCode_ = NO_ERROR;
	}
	
	// Three argument constructor: Accepts three arguments to set the values of year_, mon_ and day_ attributes. It also sets the readErrorCode_ to NO_ERROR.
	Date::Date(const int year, const int month, const int day) {
		this->year_ = year;
		this->mon_ = month;
		this->day_ = day;
		readErrorCode_ = NO_ERROR;
	}

	// This function returns a unique integer number based on the date. This value is used to compare two dates. 
	int Date::value()const {
		return year_ * 372 + mon_ * 31 + day_;
	}

   // Returns the number of days in a month.
   int Date::mdays()const {
      int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
      int mon = mon_ >= 1 && mon_ <= 12 ? mon_ : 13;
      mon--;
      return days[mon] + int((mon == 1)*((year_ % 4 == 0) && (year_ % 100 != 0)) || (year_ % 400 == 0));
   }

   // Sets the readErrorCode_ member-variable to one of the values mentioned above.
   void Date::errCode(int errorCode) {
	   readErrorCode_ = errorCode;
   }

   // Returns the readErrorCode_ value
   int Date::errCode()const {
	   return readErrorCode_;
   }

   // Returns true if readErrorCode_ is not equal to zero
   bool Date::bad()const {
	   bool badOrNot = false;
	   if (readErrorCode_ != 0) {
		   badOrNot = true;
	   }
	   return badOrNot;
   }

   // These operators return the comparison result of the return value of the value() function applied to left and right operands (The Date objects on the left and right side of the operators).
   bool Date::operator==(const Date& D)const {
	   if (this == &D) {
		   return true;
	   }
	   return (this->value() == D.value());  
   }
   bool Date::operator!=(const Date& D)const {
	   return !(*this == D);
   }
   bool Date::operator<(const Date& D)const {
	   
	   if (*this == D) {
		   return false;
	   }
	   return (this->value() < D.value());

   }
   bool Date::operator>(const Date& D)const {
	   if (*this == D) {
		   return false;
	   }
	   return !(*this < D);
   }
   bool Date::operator<=(const Date& D)const {
	   if (*this == D) {
		   return true;
	   }
	   return (*this < D);
   }
   bool Date::operator>=(const Date& D)const {
	   if (*this == D) {
		   return true;
	   }
	   return !(*this < D);
   }

   // Reads the date in the following format: YYYY?MM?DD (e.g. 2016/03/24 or 2016-03-24) from the console.
   // This function regards every single detail, for instance, every after 4 year from 2000, the final date of February is incremented by 1
   std::istream& Date::read(std::istream& istr) {

	   char ch;
	   istr >> year_ >> ch >> mon_ >> ch >> day_;
	   if (!cin.fail()) {

		   if (year_ >= MIN_YEAR && year_ <= MAX_YEAR) {
			   readErrorCode_ = NO_ERROR;
			   if (mon_ >= 1 && mon_ <= 12) {
				   readErrorCode_ = NO_ERROR;
				   if (day_ >= 1 && day_ <= this->mdays()) {
					   readErrorCode_ = NO_ERROR;	  
				   }
				   else {
					   readErrorCode_ = DAY_ERROR;
				   }

			   }
			   else {
				   readErrorCode_ = MON_ERROR;
			   }
		   }
		   else {
			   readErrorCode_ = YEAR_ERROR;
		   }

	   }
	   else {
		   readErrorCode_ = CIN_FAILED;
		 
	   }

	   return istr;
   }

   // Writes the date using the ostr argument in the following format: YYYY/MM/DD, then return the ostr.
   std::ostream& Date::write(std::ostream& ostr)const {
	   ostr << this->year_ << '/';
	   ostr.width(2);
	   ostr.fill('0');
	   ostr.setf(std::ios::right);
	   ostr << this->mon_ << '/';
	   ostr.width(2);
	   ostr.fill('0');
	   ostr.setf(std::ios::right);
	   ostr << this->day_;

	   return ostr;
   }

   // Non-member Input operator overloads
   std::istream& operator>>(std::istream& is, Date& s) {
	   s.read(is);
	   return is;
   }
   
   // Non-member Output operator overloads
   std::ostream& operator<<(std::ostream& os, const Date& s) {
	   s.write(os);
	   return os;
   }


}
