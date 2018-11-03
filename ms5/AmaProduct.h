// Final Project Milestone 5
// Version 1.0
// Date	2017-07-10
// Author   Fardad Soleimanloo
// AmaProduct.h
// 
// 
//
//
// Revision History
// -----------------------------------------------------------
// Name Kyuyoung Shim  Date 2017-07-27   Reason
/////////////////////////////////////////////////////////////////
#ifndef SICT_AMAPRODUCT_H
#define SICT_AMAPRODUCT_H
#include "Product.h"
#include "Streamable.h"
#include "ErrorMessage.h"

#define MAX_GETLINE_NUM 100 // may require different size
#define MAX_UPC_LEN 7

namespace sict {

	class AmaProduct : public Product {
	private:
		char fileTag_;
		char unit_[11];
	protected:
		ErrorMessage err_;
	public:
		AmaProduct(char value = 'N');
		const char* unit()const;
		void unit(const char* value);

		std::fstream& store(fstream& file, bool addNewLine = true)const ;
		std::fstream& load(std::fstream& file) ;
		std::ostream& write(ostream& ostr, bool linear)const ;
		std::istream& read(istream& istr) ;


	};


}




#endif

