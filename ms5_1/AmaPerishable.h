// AmaPerishable.h
#ifndef SICT_AMAPERISHABLE_H
#define SICT_AMAPERISHABLE_H
#include "AmaProduct.h"
#include "Date.h"

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