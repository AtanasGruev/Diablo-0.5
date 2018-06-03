#ifndef BOUNTYHUNTER_BOUNTYHUNTER_BOUNTYHUNTER_H
#define BOUNTYHUNTER_BOUNTYHUNTER_BOUNTYHUNTER_H

#include "Character.h"

class BountyHunter : public Character
{
private:
	double agilityBountyHunter; //special ability, gives agility bonus to the attack of the hero
public:
	BountyHunter(const String&); //constructor with parameter
	virtual double getSpecialAbility() const; //return agility 
	virtual double getMinimumAbility() const; //returns minimum ability, includes agilityBountyHunter

	double attackHero(); //attack
	double defendHerî(double); //defend
	void levelUpHero(); //level up

	virtual void battleWithEnemy(Enemy*); //battle
};

#endif // !BOUNTYHUNTER_BOUNTYHUNTER_BOUNTYHUNTER_H