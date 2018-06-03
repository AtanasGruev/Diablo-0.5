#ifndef BARBARIAN_BARBARIAN_BARBARIAN_H_
#define BARBARIAN_BARBARIAN_BARBARIAN_H_

#include "Character.h"

class Barbarian : public Character
{
private:
	int rageBarbarian; //special ability, used to supple rage bonus to the attack of the hero
	int rageForNextBattle; //transforms into rageBarbarian after a battle has finished
public:
	Barbarian(const String&); //constructor with parameter
	virtual  double getSpecialAbility() const; // returns rage left
	virtual double getMinimumAbility() const; //returns minimum ability, includes rageBarbarian

	double attackHero();  //attack
	double defendHerî(double); //defend
	void levelUpHero(); //level up

	void convertRage();
	bool isRageAllowed(int) const; //uses rageFlag to check whether transformation to rageBarbarian should occur

	virtual void battleWithEnemy(Enemy*); //battle
};

#endif // !BARBARIAN_BARBARIAN_BARBARIAN_H_