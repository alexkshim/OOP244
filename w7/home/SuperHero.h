/**********************************************************
// Workshop 7: Derived Classes
// SuperHero.h
// Version Unknown
// 2017/06/23
//
// Description
// In this workshop, you are to inherit one class from another class and support a class with a global function.
//
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name			          Date		         Reason
// Kyuyoung Shim          07/13
///////////////////////////////////////////////////////////
**********************************************************/

#ifndef SUPERHERO_H
#define SUPERHERO_H

#include "Hero.h"

namespace sict {

	class SuperHero : public Hero {
		int m_superPowerAttackBonus; // superpower:  attack bonus
		int m_superPowerDefendBonus;      // superpower:  defense

	public:
		// constructors  
		SuperHero();
		SuperHero(const char* name,
			int maximumHealth,
			int attack,

			int superPowerAttack,
			int superPowerDefend);

		int getAttack() const;
		int getDefend() const;
	};

	void applyDamage(SuperHero& A, SuperHero& B);
	const SuperHero & operator*(const SuperHero &, const SuperHero &);
}
#endif
