// Final Project Milestone 5
// Date.h
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
#ifndef SICT_DATE_H
#define SICT_DATE_H
#define NO_ERROR 0
#define CIN_FAILED 1
#define YEAR_ERROR 2
#define MON_ERROR 3
#define DAY_ERROR 4

namespace sict {

	const int min_year = 2000;
	const int max_year = 2030;

  class Date {
  private:
	  int m_year;
	  int m_mon;
	  int m_day;
	  int m_cmpValue;
	  int m_readErrorCode;
	  int mdays(int, int)const;
	  void errCode(int errorCode);
	  void setEmpty(); // optional to minimize duplications
  public:
	  Date();
	  Date(const int, const int, const int);
	  bool operator==(const Date& rhs) const;
	  bool operator!=(const Date& rhs) const;
	  bool operator<(const Date& rhs) const;
	  bool operator>(const Date& rhs) const;
	  bool operator<=(const Date& rhs) const;
	  bool operator>=(const Date& rhs) const;
	  int errCode() const;
	  bool bad() const;
	  std::istream& read(std::istream& istr);
	  std::ostream& write(std::ostream& ostr) const;
  };

  std::ostream& operator<<(std::ostream& os, const Date& s);
  std::istream& operator>>(std::istream& is, Date& s);

}
#endif