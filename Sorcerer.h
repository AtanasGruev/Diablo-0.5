#ifndef SORCERER_SORCERER_SORCERER_H_
#define SORCERER_SORCERER_SORCERER_H_

#include "Character.h"

class Sorcerer : public Character
{
private:
	double manaSorcerer; //special ability, used to give mana bonus to the attack of the hero
	double manaCapacity; //manaSorcerer cannot exceed the manaCapacity
public:
	Sorcerer(const String&); //constructor with parameter
	double getSpecialAbility() const; //returns mana left
	virtual double getMinimumAbility() const; //returns minimum ability, includes manaSorcerer

	double attackHero(); //attack
	double defendHerî(double); //defend
	void levelUpHero(); //level up

	virtual void battleWithEnemy(Enemy*); //battle
};

#endif // !SORCERER_SORCERER_SORCERER_H_