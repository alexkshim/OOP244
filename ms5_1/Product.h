// Final Project Milestone 4
// Version 1.0
// Date	2017-07-??
// Author	Fardad Soleimanloo
//
//
// 
//
//
// Revision History
// -----------------------------------------------------------
// Name   Kyuyoung Shim   Date  13 July 2017   Reason
/////////////////////////////////////////////////////////////////

#ifndef SICT_PRODUCT_H
#define SICT_PRODUCT_H
#include <iostream>
#include <fstream>
#include <cstring>
#include "general.h"
#include "Streamable.h"

using namespace std;

namespace sict {

	class Product : public Streamable {
	private:
		char sku_[MAX_SKU_LEN + 1];
		char* name_;
		double price_;
		bool taxed_;
		int quantity_;
		int qtyNeeded_;
	public:
		Product();
		Product(const char* sku, const char* name, const bool taxed = true, const double price = 0.0, const int qtyNeeded = 0);
		Product(const Product&);
		Product& operator=(const Product&);
		void sku(const char* sku);
		const char* sku()const;
		
		void name(const char* name);
		const char* name()const;
		
		void price(const double price);
		double price()const;

		void taxed(const bool taxedOrNot);
		bool taxed()const;

		void quantity(const int qty);
		int quantity()const;

		void qtyNeeded(const int qtyNeeded);
		int qtyNeeded()const;

		double cost()const;
		bool isEmpty()const;
	
		bool operator==(const char*)const;
		int operator+=(int);
		int operator-=(int);



	};

	double operator+=(double&, const Product&);
	std::ostream& operator<<(std::ostream&, const Product&);
	std::istream& operator>>(std::istream&, Product&);

}

#endif // !1