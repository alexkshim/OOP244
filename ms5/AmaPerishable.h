// Final Project Milestone 5
// Version 1.0
// Date	2017-07-10
// Author   Fardad Soleimanloo
// AmaPerishable.h
// 
// 
//
//
// Revision History
// -----------------------------------------------------------
// Name Kyuyoung Shim  Date 2017-07-27   Reason
/////////////////////////////////////////////////////////////////

#ifndef SICT_AMAPERISHABLE_H
#define SICT_AMAPERISHABLE_H
#include "AmaProduct.h"
#include "Date.h"
#include "ErrorMessage.h"

namespace sict {

	class AmaPerishable : public AmaProduct {
	private:
		Date expiry_;
	public:
		AmaPerishable();
		const Date& expiry()const;
		void expiry(const Date &value);

		virtual std::fstream& store(fstream& file, bool addNewLine = true)const;
		virtual std::fstream& load(fstream& file);
		virtual std::ostream& write(ostream& ostr, bool linear)const;
		virtual std::istream& read(istream& istr);
	
	};

}



#endif