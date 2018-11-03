// Final Project Milestone 6
// Version 1.0
// Date	2017-??-??
// Author   Fardad Soleimanloo
// AidApp.cpp
// 
// 
//
//
// Revision History
// -----------------------------------------------------------
// Name Kyuyoung Shim   Date 2017-08-06   Reason
/////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include "AidApp.h"

namespace sict {

	// The AidApp constructor receives a constant char string called filename
	AidApp::AidApp(const char* filename) {
		strcpy(filename_, filename);
		for (int i = 0; i < MAX_NO_RECS; i++) {
			product_[i] = nullptr;
		}
		noOfProducts_ = 0;
		loadRecs();
	}

	// Prints: "Press Enter to continue..."<NEWLINE> then waits for the user to hit enter. 
	void AidApp::pause()const {
		std::cout << "Press Enter to continue..." << endl;
		while (getchar() != '\n') {
			cin.ignore();
		}
	}

	// Menu() displays the menu as follows and waits for the user to select an option. 
	int AidApp::menu() {
		int option;
		int returnVal = -1;

		cout << "Disaster Aid Supply Management Program" << endl;
		cout << "1- List products" << endl;
		cout << "2- Display product" << endl;
		cout << "3- Add non-perishable product" << endl;
		cout << "4- Add perishable product" << endl;
		cout << "5- Add to quantity of purchased products" << endl;
		cout << "0- Exit program" << endl;
		cout << "> ";
		cin >> option;
		cout << endl;

		switch (option) {
		case 1:
			returnVal = 1;
			break;
		
		case 2:
			returnVal = 2;
			break;

		case 3:
			returnVal = 3;
			break;
			
		case 4:
			returnVal = 4;
			break;

		case 5:
			returnVal = 5;
			break;

		case 0:
			returnVal = 0;
			break;

		default:
			option = -1;
			break;
		}

		cin.clear();
		return returnVal;
	}

	// Opens the data file for reading.  If the file does not exist, it will create an empty file, close the file and exit.  
	// Otherwise, read the data file and store each record to the pointer array of Products accordingly (overwriting the old ones).
	void AidApp::loadRecs() {
		int readIndex = 0;
		char tempChar;

		datafile_.open(filename_, std::ios::in);
		if (datafile_.fail()) {
			datafile_.clear();
			datafile_.close();
			datafile_.open(filename_, std::ios::out);
			datafile_.close();
		}
		else {
			while (!datafile_.fail()) {
				delete[]this->product_[readIndex];
				datafile_ >> tempChar;
				
				if (tempChar == 'P' || tempChar == 'p') {
					product_[readIndex] = new AmaPerishable;
				}
				else if (tempChar == 'N' || tempChar == 'n') {
					product_[readIndex] = new AmaProduct;
				}

				if (tempChar == 'N' || tempChar == 'n' || tempChar == 'P' || tempChar == 'p') {
					datafile_.ignore();
					product_[readIndex]->load(datafile_);
					readIndex++;
				}
			}
			noOfProducts_ = readIndex;
			datafile_.close();
		}
		
	}

	// Opens the data file for writing, Loops through the product_ array up to noOfProducts_ and stores them in the datafile_ and close
	void AidApp::saveRecs() {
		datafile_.open(filename_, std::ios::out);
		for (int i = 0; i < noOfProducts_; i++) {
			product_[i]->store(datafile_);
		}
		datafile_.close();
	}

	// This function prints all the lists of products in the following format calculating those prices.
	void AidApp::listProducts()const {
		double totalPrice = 0;

		cout << " Row | SKU    | Product Name       | Cost  | QTY| Unit     |Need| Expiry   " << endl;
		cout << "-----|--------|--------------------|-------|----|----------|----|----------" << endl;
		for (int i = 0; i < noOfProducts_ - 1; i++) {
			cout << setw(4) << setfill(' ') << right << i + 1 << " | ";
			product_[i]->write(std::cout, true);

			if (i != 0 && i % 9 == 0) {
				cout << endl;
				pause();
			}
			else {
				cout << endl;
			}
			totalPrice += *product_[i];
		}

		cout << "---------------------------------------------------------------------------" << endl;
		cout << "Total cost of support: $" << fixed << setprecision(2) << fabs(totalPrice) << endl << endl;
	}

	// Loops through the product_ up to noOfProducts_ and checks each of them for the same SKU as the incoming argument using the operator== implemented by the Product class.
	// It will return matching index but if not matching, return -1
	int AidApp::SearchProducts(const char* sku)const {
		int matchIndex = -1;

		for (int i = 0; i < noOfProducts_; i++) {
			if (strcmp(product_[i]->sku(), sku) == 0) {
				matchIndex = i;
			}
		}

		return matchIndex;
	}

	// Updates the quantity on hand for a Product.
	void AidApp::addQty(const char* sku) {
		int index = SearchProducts(sku);
		int purchasedQty;
		int abstactQty;
		int extra = 0;
		int tempQty = product_[index]->quantity();

		if (index == -1) {
			cout << "Not found!" << endl;
		}
		else {
			product_[index]->write(cout, false);
			cout << endl << endl;
			cout << "Please enter the number of purchased items: ";
			cin >> purchasedQty;
			if (cin.fail()) {
				cout << "Invalid quantity value!" << endl;
			}
			else {
				abstactQty = product_[index]->qtyNeeded() - product_[index]->quantity();
				if (purchasedQty <= abstactQty) {
					 tempQty += purchasedQty;
					 product_[index]->quantity(tempQty);
				}
				else {
					extra = purchasedQty - (product_[index]->qtyNeeded() - product_[index]->quantity());
					tempQty += abstactQty;
					product_[index]->quantity(tempQty);

					cout << "Too many items; only " << product_[index]->qtyNeeded() << " is needed, please return the extra " << extra << " items. " << endl;
				}
			}
		}
		saveRecs();
		cout << endl;
		cout << "Updated!" << endl;
		cin.clear();
	}

	// Depending on the value of the argument being true or false, create a Perishable or Non-perishable Product 
	// and get the values from the user and add it to the end of the product_ array and save the records (call saveRecs()).
	void AidApp::addProduct(bool isPerishable) {
		noOfProducts_--;
		Product* product;

		if (isPerishable == true) {
			product = new AmaPerishable();
		}
		else {
			product = new AmaProduct();
		}
		product->read(cin);

		if (cin.fail()) {
			product->write(cout, isPerishable);
			cin.clear();
			cin.ignore();
			cout << endl;
		}
		else {
			product_[noOfProducts_] = product;
			cout << endl;
			cout << "Product added" << endl;
			noOfProducts_++;
			saveRecs();
		}
		cout << endl;

	}

	// Display the menu, receive the user’s selection, and do the action requested (follow with a pause using the pause() function), 
	// and repeat (redisplay the menu…) until the user selects zero to exit. 
	int AidApp::run() {
		int option;
		char inSku[MAX_SKU_LEN];
		int foundIndex;

		do {
			cin.clear();
			option = menu();
			switch (option)
			{
			case 1: // 1- List products
				cin.ignore();
				listProducts();
				pause();
				break;
			case 2: // 2- Display product
				cout << "Please enter the SKU: ";
				cin >> inSku;
				cout << endl;
				foundIndex = SearchProducts(inSku);
				if (foundIndex != -1) {
					product_[foundIndex]->write(cout, false);
					cout << endl << endl;
					pause();
				}
				else {
					cout << "Not found!" << endl;
				}
				cin.ignore();
				break;
			case 3: // 3- Add non-perishable product
				addProduct(false);
				loadRecs();
				break;
			case 4: // 4- Add perishable product
				addProduct(true);
				loadRecs();
				break;
			case 5: // 5- Add to quantity of purchased products
				cout << "Please enter the SKU: ";
				cin >> inSku;
				cout << endl;
				addQty(inSku);
				cout << endl;
				break;
			case 0: // 0- Exit program
				cout << "Goodbye!!" << endl;
				break;
			default:
				cout << "===Invalid Selection, try again.===" << endl;
				cin.ignore();
				pause();
				break;
			}

		} while (option != 0);

		return 0;
	}

}