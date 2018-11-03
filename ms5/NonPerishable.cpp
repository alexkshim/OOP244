// Final Project Milestone 5
// NonPerishable.cpp
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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include <cmath>
#include "NonPerishable.h"

namespace sict {

	// This function replaces any name previously stored. If the address in the incoming parameter is nullptr, 
	// this function removes the name of the product, if any, from memory
	void NonPerishable::name(const char* nameOfProd) {
		if (nameOfProd != nullptr) {
			clearMemory();
			int len = strlen(nameOfProd);	
			m_nameOfProd = new char[len + 1];
			strncpy(m_nameOfProd, nameOfProd, len + 1);
		}
	}

	// Returns the address of the C-style string that holds the name of the product. 
	// If the product has no name, this query returns nullptr
	const char* NonPerishable::name() const {
		return (m_nameOfProd != nullptr) ? m_nameOfProd : nullptr;
	}

	// Returns the price of the product plus any tax that applies to the product
	double NonPerishable::cost() const {
		double tax = 0;
		
		if (m_taxableOrNot == true) {
			tax = m_priceOfProd * tax_rate;
		}

		return m_priceOfProd + tax;
	}

	// Receives the address of a C-style string holding an error message 
	// and stores that message in the ErrorMessage object
	void NonPerishable::message(const char* errorMsg) {
		m_errMsgObj.message(errorMsg);
	}

	// Returns true if the ErrorMessage object is clear; false otherwise.
	bool NonPerishable::isClear() const {
		return m_errMsgObj.message() == nullptr ? true : false;
	}

	// An optional function that clears the memory for the product's name
	void NonPerishable::clearMemory() {
		//delete[]m_nameOfProd;
		m_nameOfProd = nullptr;
	}

	// An optional function setting current member data by default
	void NonPerishable::setEmpty() {
		m_skuOfProd[0] = '\0';
		name(nullptr);
		m_unitForProd[0] = '\0';
		m_qtyOnHand = 0;
		m_taxableOrNot = true;
		m_priceOfProd = 0;
		m_qtyNeeded = 0;
	}

	// An optional function initializing member data to the current object
	void NonPerishable::setValues(const char* sku, const char* name, const char* unit,
		int qtyOnHand, bool taxableOrNot, double priceOfProd, int qtyNeeded) {
		strncpy(m_skuOfProd, sku, max_sku_length + 1);
		this->name(name);
		strncpy(m_unitForProd, unit, max_unit_length + 1);
		m_qtyOnHand = qtyOnHand;
		m_taxableOrNot = taxableOrNot;
		m_priceOfProd = priceOfProd;
		m_qtyNeeded = qtyNeeded;
	}

	// Default Constructor
	NonPerishable::NonPerishable() {
		m_typeOfProd = 'N';
		setEmpty();
	}

	// This constructor optionally receives a character that identifies the product type, 
	// stores the character in an instance variable and sets the current object to a safe recognizable empty state
	NonPerishable::NonPerishable(char typeOfProd) {
		m_typeOfProd = typeOfProd;
		setEmpty();
	}

	// A constructor with seven parameters setting all of the incoming values to the current object properly
	NonPerishable::NonPerishable(const char* sku, const char* name, const char* unit,
		int qtyOnHand, bool taxableOrNot, double priceOfProd, int qtyNeeded) {
			strncpy(m_skuOfProd, sku, max_sku_length + 1);
			this->name(name);
			strncpy(m_unitForProd, unit, max_unit_length + 1);
			m_qtyOnHand = qtyOnHand;
			m_taxableOrNot = taxableOrNot;
			m_priceOfProd = priceOfProd;
			m_qtyNeeded = qtyNeeded;
	}

	// Copy Constructor - receives an unmodifiable reference to a NonPerishable object 
	// and copies the object referenced to the current object
	NonPerishable::NonPerishable(const NonPerishable& obj) {
		if (!obj.isEmpty()) {
			if (this != &obj) {
				*this = obj;
			}
		}
		else {
			m_typeOfProd = '\0';
			setEmpty();
		}
	}

	// Copy Assignment Operator - receives an unmodifiable reference to a NonPerishable object 
	// and replaces the current object with a copy of the object referenced 
	NonPerishable& NonPerishable::operator=(const NonPerishable& obj) {
		if (this != &obj) {
			if (!obj.isEmpty()) {
				m_typeOfProd = obj.m_typeOfProd;
				setValues(obj.m_skuOfProd, obj.m_nameOfProd, obj.m_unitForProd, obj.m_qtyOnHand, obj.m_taxableOrNot, obj.m_priceOfProd, obj.m_qtyNeeded);
			}
			else {
				m_typeOfProd = '\0';
				setEmpty();
			}
		}

		return *this;
	}

	// Destructor - deallocates any memory that has been dynamically allocated
	NonPerishable::~NonPerishable() {
		clearMemory();
	}
	
	// This function inserts a record with comma separated fields containing the data for the current object into the fstream object
	std::fstream& NonPerishable::store(std::fstream& file, bool newLine) const { // problem occurs here
		//if (m_qtyOnHand == 1) {
			file << m_typeOfProd << ',' << m_skuOfProd << ',' << m_nameOfProd << ',' << m_priceOfProd << 
		 	',' << m_taxableOrNot << ',' << m_qtyOnHand << ',' << m_unitForProd << ',' << m_qtyNeeded << ((newLine) ? "\n" : "");
		//}
		//else {
		//	file << m_typeOfProd << ',' << m_skuOfProd << ',' << m_nameOfProd << ',' << m_unitForProd << ',' << m_taxableOrNot << ','
		//		<< m_priceOfProd << ',' << m_qtyOnHand << ',' << m_qtyNeeded << ((newLine) ? "\n" : "");
		//}
		//file << m_typeOfProd << ',' << m_skuOfProd << ',' << m_nameOfProd << ',' << m_unitForProd << ',' << m_taxableOrNot << ','
		//	<< m_priceOfProd << ',' << m_qtyOnHand << ',' << m_qtyNeeded << ((newLine) ? "\n" : "");

		return file;
	}

	// This function extracts the fields for a record from the fstream object, 
	// creates a temporary object from the field data and copy assigns that object to the current object
	std::fstream& NonPerishable::load(std::fstream& file) {
		char tempSku[max_sku_length];
		char maxLengthName[max_name_length + 1];
		char tempUnit[max_unit_length];
		bool tempTaxableOrNot;
		double tempPrice;
		int  tempQtyOnHand;
		int tempQtyNeeded;

		file.getline(tempSku, max_sku_length + 1, ',');
		file.getline(maxLengthName, max_name_length, ',');
		file >> tempPrice;
		file.ignore();
		file >> tempTaxableOrNot;
		file.ignore();
		file >> tempQtyOnHand;
		file.ignore();
		file.getline(tempUnit, max_unit_length, ',');
		file >> tempQtyNeeded;
		file.ignore();

		NonPerishable tmp(tempSku, maxLengthName, tempUnit, tempQtyOnHand, tempTaxableOrNot, tempPrice, tempQtyNeeded);
		*this = tmp;

		return file;
	}

	// This function inserts the data fields for the current object into the ostream object in the following order 
	// and separated by a vertical bar character ('|')
	std::ostream& NonPerishable::write(std::ostream& os, bool linear) const {
		if (!m_errMsgObj.isClear()) {
			os << m_errMsgObj.message();
		}
		else {
			if (linear == true) {
				os.setf(std::ios::left);
				os << std::setw(max_sku_length) << std::setfill(' ') << std::left << m_skuOfProd << '|';

				os.setf(std::ios::left);
				os << std::setw(20) << std::setfill(' ') << std::left << m_nameOfProd << '|';

				os.setf(std::ios::right);
				os.width(7);
				os << std::setfill(' ') << std::fixed << std::setprecision(2) << fabs(cost()) << '|';

				os.setf(std::ios::right);
				os.width(4);
				os << std::setfill(' ') << m_qtyOnHand << '|';

				os << std::setfill(' ') << std::setw(10) << std::left << m_unitForProd << '|';

				os.setf(std::ios::right);
				os << std::setfill(' ') << std::setw(4) << std::right << m_qtyNeeded << '|';
			}
			else {
				os << "Sku: " << m_skuOfProd << std::endl;
				os << "Name: " << m_nameOfProd << std::endl;
				os << "Price: " << std::fixed << std::setprecision(2) << fabs(m_priceOfProd) << std::endl;
				os << "Price after tax: ";
				if (m_taxableOrNot) {
					os << std::fixed << std::fabs(cost()) << std::endl;
				}
				else {
					os << "N/A" << std::endl;
				}
				os << "Quantity On Hand: " << m_qtyOnHand << ' ' << m_unitForProd << std::endl;
				os << "Quantity Needed: " << m_qtyNeeded;
			}
		}

		return os;
	}

	// This function extracts the data fields for the current object in the following order, line by line.
	std::istream& NonPerishable::read(std::istream& is) {
		char tempSku[max_sku_length];
		char tempName[max_name_length + 1]; // before allowcated, to get up to 75 characters of the name including a null byte
		char tempUnit[max_unit_length];
		char yesOrNo;
		double tempPrice;
		int  tempQtyOnHand;
		int tempQtyNeeded;

		if (!is.fail()) {
			m_errMsgObj.clear();
			std::cin.clear();
			std::cin.clear();
			std::cout << " Sku: ";
			is.getline(tempSku, max_sku_length, '\n');
			strncpy(m_skuOfProd, tempSku, max_sku_length);

			if (!is.fail()) {
				std::cin.clear();
				std::cout << " Name: ";
				is.getline(tempName, max_name_length, '\n');
				name(tempName);

				if (!is.fail()) {
					std::cin.clear();
					std::cout << " Unit: ";
					is.getline(tempUnit, max_unit_length, '\n');
					strncpy(m_unitForProd, tempUnit, max_unit_length + 1);

					std::cout << " Taxed? (y/n): ";
					is >> yesOrNo;
					if (is.fail() || !(yesOrNo == 'Y' || yesOrNo == 'y' || yesOrNo == 'N' || yesOrNo == 'n')) {
						m_errMsgObj.message("Only (Y)es or (N)o are acceptable");
						is.setstate(std::ios::failbit);
					}
					else {
						if (yesOrNo == 'Y' || yesOrNo == 'y') {
							m_taxableOrNot = true;
						}
						else {
							m_taxableOrNot = false;
						}
						is.clear();
						std::cin.clear();
						std::cout << " Price: ";
						is >> tempPrice;
						if (is.fail()) {
							message("Invalid Price Entry");
							is.setstate(std::ios::failbit);
						}
						else {
							m_priceOfProd = tempPrice;
							is.ignore();
							std::cin.clear();
							std::cout << "Quantity On hand: ";
							is >> tempQtyOnHand;
							if (is.fail()) {
								message("Invalid Quantity Entry");
								is.setstate(std::ios::failbit);
							}
							else {
								quantity(tempQtyOnHand);
								is.ignore();
								std::cin.clear();
								std::cout << "Quantity Needed: ";
								is >> tempQtyNeeded;
								if (is.fail()) {
									message("Invalid Quantity Needed Entry");
									is.setstate(std::ios::failbit);
								}
								else {
									m_qtyNeeded = tempQtyNeeded;
								} // validation ends
							}
						}
					}
				}
			}
		}

		return is;
	}

	// A query that receives the address of an unmodifiable C-style string and returns true 
	// if the string is identical to the sku of the current object; false otherwise
	bool NonPerishable::operator==(const char* sku) const {
		bool sameOrNot = false;
		
		if (strcmp(m_skuOfProd, sku) == 0) {
			sameOrNot = true;
		}

		return sameOrNot;
	}
	
	// A query that returns the total cost of all items on hand
	double NonPerishable::total_cost() const {
		return cost() * m_qtyOnHand;
	}

	// A modifier that receives an integer holding the number of units of the Product that are on hand. 
	// This function resets the number of units that are on hand.
	void NonPerishable::quantity(int noOfUnit) {
		m_qtyOnHand = noOfUnit;
	}

	// Returns true if the object is not in an error state; false otherwise
	bool NonPerishable::isEmpty() const {
		return m_typeOfProd == '\0' && m_skuOfProd[0] == '\0' && m_nameOfProd != nullptr && m_qtyOnHand == 0 && m_priceOfProd == 0 && m_qtyNeeded == 0;
	}

	// Receives the address of a C-style string holding a product sku and returns true 
	// if the string is greater than the sku of the current object as the string comparison functions define ¡®greater than¡¯; false otherwise.
	bool NonPerishable::operator>(const char* sku) const {
		return (strcmp(sku, m_skuOfProd) > 0);
	}

	// If the integer received is positive-valued, this function adds it to the quantity on hand. 
	// If the integer is negative-valued or zero, this function does nothing and returns the quantity on hand (without modification).
	int NonPerishable::operator+=(int qtyNeeded) {
		return m_qtyOnHand += qtyNeeded;
	}

	// A query that receives an unmodifiable reference to a Product object and returns true 
	// if the name of the current object is greater than the name of the Product object; false otherwise
	bool NonPerishable::operator>(const Product& obj) const {
		return (strcmp(this->m_nameOfProd, obj.name()) > 0);
	}

	// A helper that receives a reference to an ostream object and an unmodifiable reference to 
	// a Product object and returns a reference to the ostream object
	std::ostream& operator<<(std::ostream& ostr, const Product& mf) {
		return mf.write(ostr, true);
	}

	// A helper that receives a reference to an istream object and an modifiable reference to 
	// a Product object and returns a reference to the istream object
	std::istream& operator>>(std::istream& istr, Product& mf) {
		return mf.read(istr);
	}

	// A helper that receives a reference to a double and an unmodifiable reference to a Product object and returns a double. 
	// Implementations of this function will add the total cost of the Product object to the double received and return the updated double
	double operator+=(double& d, const Product& p) {
		d += p.total_cost();
		return d;
	}

	// A helper that creates a NonPerishable object in dynamic memory and returns its address
	Product* CreateProduct() {
		Product* pObj = nullptr;
		pObj = new NonPerishable;
		return pObj;
	}

}
