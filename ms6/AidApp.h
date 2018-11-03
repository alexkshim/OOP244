// Final Project Milestone 6
// Version 1.0
// Date	2017-??-??
// Author   Fardad Soleimanloo
// AidApp.h
// 
// 
//
//
// Revision History
// -----------------------------------------------------------
// Name Kyuyoung Shim   Date 2017-08-06   Reason
/////////////////////////////////////////////////////////////////

#ifndef AIDAPP_H
#define AIDAPP_H
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <cmath>
#include "general.h"
#include "Product.h"
#include "AmaPerishable.h"

namespace sict {

	class AidApp {
	private:
		char filename_[256];
		Product* product_[MAX_NO_RECS];
		std::fstream datafile_;
		int noOfProducts_;
		AidApp(char* filename) = delete;
		AidApp& operator=(const AidApp&) = delete;
	public:
		AidApp(const char* filename);
		void pause()const;
		int menu();
		void loadRecs();
		void saveRecs();
		void listProducts()const;
		int SearchProducts(const char* sku)const;
		void addQty(const char* sku);
		void addProduct(bool isPerishable);
		int run();
	};

}

#endif