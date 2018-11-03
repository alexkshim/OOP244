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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include "Product.h"

using namespace std;

namespace sict {

	// This constructor sets the Product to a safe recognizable empty state. All number values are set to zero in this state.
	Product::Product() {
		this->sku_[0] = '\0';
		this->name_ = nullptr;
		this->taxed_ = true;
		this->price_ = 0;
		this->quantity_ = 0;
		this->qtyNeeded_ = 0;
	}

	Product::Product(const char* sku, const char* name) {
		strncpy(this->sku_, sku, MAX_SKU_LEN);
		this->name_ = new char[strlen(name)];
		strcpy(name_, name);
		this->taxed_ = true;
		this->price_ = 0;
		this->qtyNeeded_ = 0;
		this->quantity_ = 0;
	}

	Product::Product(const char* sku, const char* name, const bool taxedOrNot, const double price, const int neededQty) {
		strncpy(this->sku_, sku, MAX_SKU_LEN);
		this->name_ = new char[strlen(name)];
		strcpy(name_, name);
		this->taxed_ = taxedOrNot;
		this->price_ = price;
		this->qtyNeeded_ = neededQty;
	}

	Product::Product(const Product& obj) {
		*this = obj;
	}

	Product& Product::operator=(const Product& obj) {
		if (&obj != nullptr) {
			if (this != &obj) {
				if (obj.name_ != nullptr) {
					delete[]name_;
					name_ = new char[strlen(obj.name_)];
					strcpy(name_, obj.name_);
				}
				strcpy(this->sku_, obj.sku_);
				this->price_ = obj.price_;
				this->taxed_ = obj.taxed_;
				this->quantity_ = obj.quantity_;
				this->qtyNeeded_ = obj.qtyNeeded_;
			}
		}
		return *this;
	}

	Product::~Product() {
		delete[]name_;
	}


	void Product::sku(char* sku) { strncpy(sku_, sku, MAX_SKU_LEN); }
	char Product::sku()const { return *this->sku_; }

	void Product::name(char* name) { strcpy(name_, name); }
	char Product::name()const { return *this->name_; }

	void Product::price(double price) { this->price_ = price; }
	double Product::price()const { return this->price_; }

	void Product::taxed(bool taxedOrNot) { this->taxed_ = taxedOrNot; }
	bool Product::taxed()const { return this->taxed_; }

	void Product::quantity(int qty) { this->quantity_ = qty; }
	int Product::quantity()const { return this->quantity_; }

	void Product::qtyNeeded(int qtyNeeded) { this->qtyNeeded_ = qtyNeeded; }
	int Product::qtyNeeded()const { return this->qtyNeeded_; }

	double Product::cost()const { // implement in cpp
		if (this->taxed_) {
			return this->price_ * TAX;
		}
		else {
			return this->price_;
		}
	}


	bool Product::isEmpty()const { return sku_[0] == '\0' && name_ == nullptr && price_ == 0 && quantity_ == 0 && qtyNeeded_ == 0; }



	// receives a constant character pointer and returns a Boolean.
	bool Product::operator==(const char* comSku)const {
		if (strncmp(comSku, this->sku_, MAX_SKU_LEN) == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	int Product::operator+=(const int qtyUp)const {
		int sumOfQty = this->quantity_ + qtyUp;
		return sumOfQty;
	}
	int Product::operator-=(const int qtyDown)const {
		int sumOfQty = this->quantity_ - qtyDown;
		return sumOfQty;
	}

	double operator+=(const double& price, const Product& product) {
		double sum = price + (product.price() * (double)product.quantity());
		return sum;
	}


	std::ostream& operator<<(std::ostream& os, const Product& s) {
		return s.write(os,true);
	}
	std::istream& operator>>(std::istream& is, Product& s) {
		return s.read(is);
	}


}
