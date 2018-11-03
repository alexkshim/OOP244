// Final Project Milestone 5
// Version 1.0
// Date	2017-07-10
// Author   Fardad Soleimanloo
// AmaProduct.cpp
// 
// 
//
//
// Revision History
// -----------------------------------------------------------
// Name Kyuyoung Shim  Date 2017-07-27   Reason
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <iostream>
#include <iomanip>
#include <cmath>
#include "AmaProduct.h"
#include "ErrorMessage.h"

using namespace std;

namespace sict {

	// constructor that receives the value for the fileTag_ member variable and assigns fileTag_ to the value
	AmaProduct::AmaProduct(char value) {
		this->fileTag_ = value;
	}
	
	// returns a constant pointer to the unit_ member variable
	const char* AmaProduct::unit()const {
		return this->unit_;
	}

	// Copies the incoming value string into the unit_ string
	void AmaProduct::unit(const char* value) {
		strncpy(this->unit_, value, 11);
		this->unit_[10] = '\0';

	}

	// Using the operator<< of ostream first writes the fileTag_ member variable and a comma into the file argument, 
	// then without any formatting or spaces writes all the member variables of Product, comma separated, in following order:
	std::fstream& AmaProduct::store(fstream& file, bool addNewLine)const {
		file << fileTag_ << ',';
		file << sku() << ',' << name() << ',' << price() << ',' << taxed() << ','
			<< quantity() << ',' << unit() << ',' << qtyNeeded() << ((addNewLine) ? "\n" : "");
		return file;
	}

	// Using the operator>>, ignore and getline methods of istream, AmaProduct reads all the comma separated fields form the current record 
	// in the file and sets the member variables using the setter methods. 
	std::fstream& AmaProduct::load(std::fstream& file) {
		char tempSku[MAX_SKU_LEN];
		char tempName[MAX_GETLINE_NUM];
		double tempPrice;
		bool tempTaxed;
		int tempQuantity;
		char tempUnit[11];
		int tempQtyNeeded;

		file.getline(tempSku, MAX_SKU_LEN, ',');
		sku(tempSku);

		file.getline(tempName, MAX_GETLINE_NUM, ',');
		name(tempName);

		file >> tempPrice;
		file.ignore();
		price(tempPrice);

		file >> tempTaxed;
		file.ignore();
		taxed(tempTaxed);

		file >> tempQuantity;
		file.ignore();
		quantity(tempQuantity);

		file.getline(tempUnit, MAX_GETLINE_NUM, ',');
		unit(tempUnit);

		file >> tempQtyNeeded;
		qtyNeeded(tempQtyNeeded);

		return file;
	}

	// If the err_ member variable is not clear (use isClear member function). It simply prints the err_ using ostr and returns ostr. 
	std::ostream& AmaProduct::write(ostream& ostr, bool linear)const {
		if (!this->err_.isClear()) {
			ostr << err_.message();
		}
		else {
			if (linear == true) {
				ostr.setf(ios::left);
				ostr << setw(MAX_SKU_LEN)<<setfill(' ')<< left << sku() << '|';
				
				ostr.setf(ios::left);
				ostr << setw(20)<< setfill(' ') << left << name() << '|';
				
				ostr.setf(ios::right);
				ostr.width(7);
				ostr << setfill(' ') << fixed << setprecision(2) << fabs(cost()) << '|';

				ostr.setf(ios::right);
				ostr.width(4);
				ostr << setfill(' ') << quantity() << '|';
				
				ostr << setfill(' ')  << setw(10) << left << unit() << '|';

				ostr.setf(ios::right);
				ostr << setfill(' ') <<setw(4) << right << qtyNeeded() << '|';
			}
			else {
				ostr << "Sku: " << sku() << endl;
				ostr << "Name: " << name() << endl;
				ostr << "Price: " << fixed << fabs(price()) << endl;
				ostr << "Price after tax: ";
				if (cost() != price()) {
					ostr << fixed << fabs(cost()) << endl;
				}
				else {
					ostr << "N/A" << endl;
				}
				ostr << "Quantity On Hand: " << quantity() << " " << unit() << endl;
				ostr << "Quantity Needed: " << qtyNeeded();
			}

		}

		return ostr;
	}

	// Receives the values using istream (the istr argument) exactly as the following format
	std::istream& AmaProduct::read(istream& istr) {
		char tempSku[MAX_SKU_LEN];
		char tempName[MAX_GETLINE_NUM];
		double tempPrice;
		char tempTaxed;
		int tempQuantity;
		char tempUnit[11];
		int tempQtyNeeded;
		bool priceValidity = true;

		if (!istr.fail()) {
			this->err_.clear();

			cout << "Sku: ";
			istr >> tempSku;
			sku(tempSku);

			if (!istr.fail()) {
				cout << "Name: ";
				istr >> tempName;
				name(tempName);

				if (!istr.fail()) {
					cout << "Unit: ";
					istr >> tempUnit;
					unit(tempUnit);

					cout << "Taxed? (y/n): "; 
					istr >> tempTaxed;
					if (istr.fail() || !(tempTaxed == 'Y' || tempTaxed == 'y' || tempTaxed == 'N' || tempTaxed == 'n')) {
						this->err_.message("Only (Y)es or (N)o are acceptable"); //setting the error message
						istr.setstate(ios::failbit);
						priceValidity = false;
					}
					else {
						if (tempTaxed == 'Y' || tempTaxed == 'y') {
							taxed(true);
						}
						else {
							taxed(false);
						}
						istr.clear();

						if (priceValidity == true) {
							cout << "Price: ";
							istr >> tempPrice;
							if (istr.fail()) {
								this->err_ = "Invalid Price Entry";
								istr.setstate(ios::failbit);
							}
							else {
								price(tempPrice);
								istr.ignore();

								cout << "Quantity On hand: ";
								istr >> tempQuantity;
								if (istr.fail()) {
									this->err_ = "Invalid Quantity Entry";
									istr.setstate(ios::failbit);
								}
								else {
									quantity(tempQuantity);
									istr.ignore();

									cout << "Quantity Needed: ";
									istr >> tempQtyNeeded;
									if (istr.fail()) {
										this->err_ = "Invalid Quantity Needed Entry";
										istr.setstate(ios::failbit);
									}
									else {
										qtyNeeded(tempQtyNeeded);
										istr.clear();
									} // validation ends

								}

							}

						}

					}

				}

			}

		}

		return istr;
	}

}