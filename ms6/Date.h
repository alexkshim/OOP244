// Final Project Milestone 6
// Version 1.0
// Date	2017-07-10
// Author   Fardad Soleimanloo
// Date.h
// 
// 
//
//
// Revision History
// -----------------------------------------------------------
// Name Kyuyoung Shim   Date 2017-08-06   Reason
/////////////////////////////////////////////////////////////////

#ifndef SICT_DATE_H__
#define SICT_DATE_H__
#include <iostream>
#include <fstream>
#include <cstring>
#define NO_ERROR 0
#define CIN_FAILED 1
#define YEAR_ERROR 2
#define MON_ERROR 3
#define DAY_ERROR 4


namespace sict{

   class Date {
   private:
	   int year_;
	   int mon_;
	   int day_;
	   int readErrorCode_;

   public:
	   int value()const;
	   void errCode(int errorCode);
	   int errCode()const;
	   bool bad()const;
	   int mdays()const;
	   Date();
	   Date(const int, const int, const int);
	   bool operator==(const Date& D)const;
	   bool operator!=(const Date& D)const;
	   bool operator<(const Date& D)const;
	   bool operator>(const Date& D)const;
	   bool operator<=(const Date& D)const;
	   bool operator>=(const Date& D)const;
	   std::istream& read(std::istream& istr);
	   std::ostream& write(std::ostream& ostr)const;
   };

   std::istream& operator>>(std::istream& is, Date& s);
   std::ostream& operator<<(std::ostream& os, const Date& s);

}
#endif