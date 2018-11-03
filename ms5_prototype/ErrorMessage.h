// Final Project Milestone 2
// Version 1.0
// Date	
// Author	
//
//
// Revision History
// -----------------------------------------------------------
// Name  Kyuyoung Shim   Date 11 July, 2017    Reason
#ifndef SICT_ERRORMESSAGE_H
#define SICT_ERRORMESSAGE_H
#include <iostream>
#include <fstream>
#include <cstring>

namespace sict {


	class ErrorMessage {
	private:
		char* message_;
	public:
		ErrorMessage();
		ErrorMessage(const char* errorMessage);
		ErrorMessage(const ErrorMessage& em) = delete;
		ErrorMessage& operator=(const ErrorMessage& em) = delete;
		ErrorMessage& operator=(const char* errorMessage);
		virtual ~ErrorMessage();
		void clear();
		bool isClear()const;
		void message(const char* value);
		const char* message()const;

	};
	std::ostream& operator<<(std::ostream& os, const ErrorMessage& s);

}
#endif