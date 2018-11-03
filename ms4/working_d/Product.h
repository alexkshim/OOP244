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
		//Product(const char*, const char*);
		Product(const char*, const char*, const bool, const double, const int);
		Product(const Product&);
		Product& operator=(const Product&);
		virtual ~Product();
		void sku(char* sku);
		char sku()const;
		
		void name(const char* name);
		char name()const;
		
		void price(double price);
		double price()const;

		void taxed(bool taxedOrNot);
		bool taxed()const;

		void quantity(int qty);
		int quantity()const;

		void qtyNeeded(int qtyNeeded);
		int qtyNeeded()const;

		double cost()const;
		bool isEmpty()const;
	
		bool operator==(const char*)const;
		int operator+=(const int)const;
		int operator-=(const int)const;

	};

	double operator+=(const double&, const Product&);
	std::ostream& operator<<(std::ostream& os, const Product& s);
	std::istream& operator>>(std::istream& is, Product& s);

}

#endif // !1