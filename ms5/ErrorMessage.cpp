// Final Project Milestone 5
// ErrorMessage.cpp
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
#include <fstream>
#include "ErrorMessage.h"

namespace sict {

	// If the address is nullptr, this function puts the object in a safe empty state.
	// If the address points to a non-empty message, this function allocates memory for that message and copies it into the allocated memory
	ErrorMessage::ErrorMessage(const char* errorMessage) {
		if (errorMessage == nullptr) {
			clear();
		}
		else {
			clear();
			message(errorMessage);
		}
	}

	// This function de-allocates any memory that has been dynamically allocated by the current object
	ErrorMessage::~ErrorMessage() {
		delete[]m_message;
		clear();
	}

	// This function clears any message stored by the current object and initialize the object to a safe empty state
	void ErrorMessage::clear() {
		m_message = nullptr;
	}

	// This query reports returns true if the current object is in a safe empty state
	bool ErrorMessage::isClear() const {
		return m_message == nullptr;
	}

	// This function stores a copy of the C-style string pointed to by str: de-allocates any memory allocated for a previously stored message,
	// allocates the dynamic memory needed to store a copy of str, and copies the string at address str to the allocated memory.
	void ErrorMessage::message(const char* str) {
		int len = strlen(str);

		delete[]m_message;
		clear();
		m_message = new char[len + 1];
		strncpy(m_message, str, len + 1);
		m_message[len] = '\0';
	}

	// This query returns the address of the message stored in the current object
	const char* ErrorMessage::message()const {
		return m_message;
	}

	// This operator sends an ErrorMessage, if a message exists, to an std::ostream object and returns a reference to the std::ostream object
	std::ostream& operator<<(std::ostream& os, const ErrorMessage& s) {
		if (!s.isClear()) {
			os << s.message();
		}

		return os;
	}

}