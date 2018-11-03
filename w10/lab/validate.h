// OOP244 Workshop 10 - Templates 
// File: validate.h
// Version: 1.0
// Date: 2017/07/16
// Author: Fardad Soleimanloo
// Kyuyoung Shim(102562162)  2017-08-03
/////////////////////////////////////////////
#ifndef ICT_VALIDATE_H_
#define ICT_VALIDATE_H_
namespace ict{

	template <class Validate> bool validate(const Validate& minimum, const Validate& maximum, const Validate* testValue, int elementNum, bool* validation) {
		int validity = true;

		for (int i = 0; i < elementNum; i++) {
			
			if (testValue[i] >= minimum && testValue[i] <= maximum) {
				validation[i] = true;
			}
			else {
				validation[i] = false;
				validity = false;
			}

		}

		return validity;
	}

}
#endif 