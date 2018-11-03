// Final Project Milestone 5
// NonPerishable.h
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

#ifndef SICT_NONPERISHABLE_H
#define SICT_NONPERISHABLE_H
#include <iostream>
#include <fstream>
#include "ErrorMessage.h"
#include "Product.h"

namespace sict {

	const int max_sku_length = 7;
	const int max_unit_length = 10;
	const int max_name_length = 75;
	const double tax_rate = 0.13;

	class NonPerishable : public Product {
	private:
		char m_typeOfProd;
		char m_skuOfProd[max_sku_length + 1];
		char* m_nameOfProd;
		char m_unitForProd[max_unit_length + 1];
		int m_qtyOnHand;
		int m_qtyNeeded;
		double m_priceOfProd; // before taxes
		bool m_taxableOrNot;
		ErrorMessage m_errMsgObj;
	protected:
		void name(const char*);
		const char* name() const;
		double cost() const;
		void message(const char*);
		bool isClear() const;
		void clearMemory(); // optional to avoid code duplications
		void setEmpty(); // optional to avoid code duplications
		void setValues(const char* sku, const char* name, const char* unit,
			int qtyOnHand, bool taxableOrNot, double priceOfProd, int qtyNeeded); // optional to avoid code duplcations
	public:
		NonPerishable();
		NonPerishable(char typeOfProd);
		NonPerishable(const char* sku, const char* name, const char* unit,
			int qtyOnHand = 0, bool taxableOrNot = true, double priceOfProd = 0, int qtyNeeded = 0);
		NonPerishable(const NonPerishable& obj);
		NonPerishable& operator=(const NonPerishable& obj);
		~NonPerishable();
		std::fstream& store(std::fstream& file, bool newLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);
		bool operator==(const char*) const;
		double total_cost() const;
		void quantity(int);
		bool isEmpty() const;
		int qtyNeeded() const { return m_qtyNeeded; }
		int quantity() const { return m_qtyOnHand; }
		bool operator>(const char*) const;
		int operator+=(int);
		bool operator>(const Product&) const;
	};
}
#endif
