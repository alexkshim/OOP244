/**********************************************************
// Workshop 7: Derived Classes
// Hero.h
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

#ifndef HERO_H
#define HERO_H

#include <iostream>

namespace sict {

	class Hero {
		char m_name[41];
		int  m_attack;
		int  m_maximumHealth;
		int  m_health;

		bool isEmpty() const;

	public:
		// constructors
		Hero();
		Hero(const char name[], int maximumHealth, int attack);

		// member functions
		void respawn();
		bool isAlive() const { return m_health > 0; }
		int  getAttack() const { return m_attack; }
		void deductHealth(int);
		void display(std::ostream& name) const;

		// friend helper function to insert name into ostream
		friend std::ostream& operator<<(std::ostream&, const Hero&);
	};

	void applyDamage(Hero& A, Hero& B);
	const Hero & operator*(const Hero &, const Hero &);

}
#endif
