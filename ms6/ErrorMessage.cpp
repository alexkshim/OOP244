// Final Project Milestone 6
// Version 1.0
// Date	2017-07-10
// Author   Fardad Soleimanloo
// ErrorMessage.cpp
// 
// 
//
//
// Revision History
// -----------------------------------------------------------
// Name Kyuyoung Shim  Date 2017-08-06   Reason
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS

#include "ErrorMessage.h"

using namespace std;

namespace sict {

	// default constructor, sets the message_ member variable to nullptr.
	ErrorMessage::ErrorMessage() {
		this->message_ = nullptr;
	}

	// Sets the message_ member variable to nullptr and then uses the message() setter member function to set the error message to the errorMessage argument. 
	ErrorMessage::ErrorMessage(const char* errorMessage) {
		this->message_ = nullptr;
		message(errorMessage);
	}
		
	// Sets the message_ to the errorMessage argument and returns the current object (*this)
	ErrorMessage& ErrorMessage::operator=(const char* errorMessage) {
		clear();
		message(errorMessage);

		return *this;
	}
	
	// De-allocates the memory pointed by message_.
	ErrorMessage::~ErrorMessage() {
		delete[]this->message_;
	}
	
	// De-allocates the memory pointed by message_ and then sets message_ to nullptr.
	void ErrorMessage::clear() {
		delete[] this->message_;
		this->message_ = nullptr;
	}
	
	// Returns true if message_ is nullptr.
	bool ErrorMessage::isClear()const {
		return this->message_ == nullptr;
	}
	
	// Sets the message_ of the ErrorMessage object to a new value 
	void ErrorMessage::message(const char* value) {
		int lengthOfMsg = strlen(value);
		//cout << value;
		clear();
		this->message_ = new char[lengthOfMsg + 1];
		strncpy(this->message_, value, lengthOfMsg + 1);
		this->message_[lengthOfMsg] = '\0';
	}
	
	// Returns the address kept in message_.
	const char* ErrorMessage::message()const {
		return message_;
	}
	
	// If ErrorMessage isClear, Nothing should be printed, otherwise the c-string pointed by message_ is printed.
	std::ostream& operator<<(std::ostream& os, const ErrorMessage& s) {
		if (!s.isClear()) {
			os << s.message();
		}

		return os;
	}

}
