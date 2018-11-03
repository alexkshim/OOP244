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
#include "Streamable.h"
#include "general.h"

using namespace std;

namespace sict {

	// This constructor sets the Product to a safe recognizable empty state. All number values are set to zero in this state.
	Product::Product() {
		sku_[0] = '\0';
		name_ = nullptr;
		price_ = 0.0;
		quantity_ = 0;
		qtyNeeded_ = 0;
		taxed_ = true;
	}

	// Product is constructed by passing 5 values to the constructor
	Product::Product(const char* sku, const char* name, const bool taxedOrNot, const double price, const int neededQty) {	
		strncpy(sku_, sku, MAX_SKU_LEN);
		sku_[MAX_SKU_LEN - 1] = '\0';
		if (this->name_ != name) {
			this->name_ = new char[strlen(name) + 1];
			strncpy(name_, name, strlen(name) + 1);
			name_[strlen(name)] = '\0';
		}
		this->quantity_ = 0;
		this->price_ = price;
		this->qtyNeeded_ = neededQty;
		this->taxed_ = taxedOrNot;
	}

	// Copy Constructor
	Product::Product(const Product& obj) {
		if (!obj.isEmpty()) {
			if (this != &obj) {
				strncpy(sku_, obj.sku_, MAX_SKU_LEN);
				sku_[MAX_SKU_LEN - 1] = '\0';
				this->name_ = new char[strlen(obj.name_) + 1];
				strncpy(name_, obj.name_, strlen(obj.name_) + 1);
				name_[strlen(obj.name_)] = '\0';
				this->quantity_ = obj.quantity_;
				this->price_ = obj.price_;
				this->qtyNeeded_ = obj.qtyNeeded_;
				this->taxed_ = obj.taxed_;
			}
		}
	}

	// the operator= allow the Product to be copied from and assigned to another Product safely and without any memory leak
	Product& Product::operator=(const Product& obj) {
		if (this != &obj) {
			if (!obj.isEmpty()) {
				delete[]this->name_;
				this->name_ = new char[strlen(obj.name_) + 1];
				strncpy(this->name_, obj.name_, strlen(obj.name_) + 1);
				name_[strlen(obj.name_)] = '\0';
				strncpy(this->sku_, obj.sku_, MAX_SKU_LEN);
				sku_[MAX_SKU_LEN - 1] = '\0';
				this->price_ = obj.price_;
				this->taxed_ = obj.taxed_;
				this->quantity_ = obj.quantity_;
				this->qtyNeeded_ = obj.qtyNeeded_;
			}
		}
		else {
			sku_[0] = '\0';
			name_ = nullptr;
			price_ = 0;
			quantity_ = 0;
			qtyNeeded_ = 0;
			taxed_ = true;
		}

		return *this;
	}

	// Setters and Getters (Queries):
	void Product::sku(const char* sku) { 
		strncpy(sku_, sku, MAX_SKU_LEN);
		sku_[MAX_SKU_LEN - 1] = '\0';
	}
	const char* Product::sku()const { return sku_; }

	void Product::name(const char* name) { 
		this->name_ = new char[strlen(name) + 1];
		strncpy(name_, name, strlen(name) + 1);
		name_[strlen(name)] = '\0';
	}
	const char* Product::name()const { return name_; }

	void Product::price(const double price) { this->price_ = price; }
	double Product::price()const { return this->price_; }

	void Product::taxed(const bool taxedOrNot) { this->taxed_ = taxedOrNot; }
	bool Product::taxed()const { return this->taxed_; }

	void Product::quantity(const int qty) { this->quantity_ = qty; }
	int Product::quantity()const { return this->quantity_; }

	void Product::qtyNeeded(const int qtyNeeded) { this->qtyNeeded_ = qtyNeeded; }
	int Product::qtyNeeded()const { return this->qtyNeeded_; }

	//  Cost returns the cost of the Product after tax. If the Product is not taxed the return value of cost() will be the same as price.
	double Product::cost()const {
		double calPrice;
		
		if (taxed()) {
			calPrice = this->price_ + (this->price_ * TAX);
		}
		else {
			calPrice = this->price_;
		}

		return calPrice;
	}

	// isEmpty return true if the Product is in a safe empty state. All the above getters are constant methods, which means they CANNOT modify the owner.
	bool Product::isEmpty()const { return sku_[0] == '\0' && name_ == nullptr && price_ == 0 && quantity_ == 0 && qtyNeeded_ == 0 && taxed_ == true; }

	// This operator will compare the received constant character pointer to the SKU of the Product, 
	// if they are the same, it will return true or else, it will return false. 
	bool Product::operator==(const char* comSku)const {
		bool sameOrNot = false;
		if (strcmp(this->sku_, comSku) == 0) {
			sameOrNot = true;
		}
		return sameOrNot;
	}

	// receives an integer and returns an integer. This operator will add the received integer value to the quantity of the Product, returning the sum.
	int Product::operator+=(const int qtyUp) {
		quantity_ += qtyUp;
		return quantity_;
	}

	// receives an integer and returns an integer. This operator will reduce the quantity of the Product by the integer value returning the quantity after reduction.
	int Product::operator-=(const int qtyDown) {
		quantity_ -= qtyDown;
		return quantity_;
	}

	// This operator multiplies the cost of the Product by the quantity of the Product and then adds that value to the left operand and returns the result. 
	double operator+=(double& price, const Product& product) {
		price += (product.cost() * product.quantity());
		return price;
	}

	// Non-member Output operator overloads:
	std::ostream& operator<<(std::ostream& os, const Product& s) {
		return s.write(os,true);
	}

	// Non-member Input operator overloads:
	std::istream& operator>>(std::istream& is, Product& s) {
		return s.read(is);
	}


}
