#ifndef CHARACTER_CHARACTER_CHARACTER_H_
#define CHARACTER_CHARACTER_CHARACTER_H_

#include "String.h"

class Enemy;

class Character
{
private:
	String nameHero; //name
	unsigned int levelHero; //level
	double healthPointsHero; //remaining HP

	//abilities
	double strengthHero; //strength
	double intelligenceHero; //intelligence

	//original values
	double originalHealthPointsHero; //HP
	double originalStrengthHero; //strength
	double originalIntelligenceHero; //intelligence

	//placement on a 10-by-10 grid, which acts as a map
	int xCoord;
	int yCoord;

	//counters
	unsigned int counterLevelUp; //counter for killed enemies, used to level up
	unsigned int counterRounds; //counter for rounds
	//if(counterLevelUp == pow(2,level)) levelUpHero();
public:
	Character(const String&, unsigned int, double, double, double); //constructor with parameters, initializes Character

	//setters
	void setHealth(double);
	void setCounterRounds(unsigned int);
	void setCounterLevelUp(unsigned int);
	//getters
	virtual String getName() const;
	double getHealth() const;
	double getLevel() const;
	unsigned int getCounterLevelUp() const;
	unsigned int getCounterRounds() const;
	double getStrength() const; 
	double getIntelligence() const;
	virtual double getMinimumAbility() const;
	virtual double getSpecialAbility() const = 0;

	//quintessensial virtual functions
	virtual double attackHero()=0; //causes damage to an enemy
	virtual double defendHerî(double); //caused damage is reduced by <strength>%
	//enhances the ability of the hero according to the formula below
	//<new value of ability> = [(<start_value_of_ability>/(<start_value_of_strengthHero 
	//+ start_value_of_intelligenceHero)) * 5] + <current_value_of_ability>
	virtual void levelUpHero();

	//functionality that is related to moving on the map
	void setXCharacter(int);
	void setYCharacter(int);
	int getXCharacter() const;
	int getYCharacter() const;
	void moveCharacter();

	//battle mechanics - virtual function, which is then overriden
	//making battle() functionality closed under all enemeies
	//that would require one pure virtual function for battlement and one public - for printing the results
	virtual void battleWithEnemy(Enemy*) = 0;
	void printBattleWithEnemy(Enemy*, double, double);
};

class Barbarian : public Character
{
private:
	int rageBarbarian; //special ability, used to supple rage bonus to the attack of the hero
	int rageForNextBattle; //transforms into rageBarbarian after a battle has finished
	bool rageFlag; //signalises when the above transformation takes place
public:
	Barbarian(const String&); //constructor with parameter
	virtual  double getSpecialAbility() const; // returns rage left
	virtual double getMinimumAbility() const; //returns minimum ability, includes rageBarbarian

	double attackHero();  //attack
	double defendHerî(double); //defend
	void levelUpHero(); //level up

	bool isRageAllowed(int) const; //uses rageFlag to check whether transformation to rageBarbarian should occur

	virtual void battleWithEnemy(Enemy*); //battle
};

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

#endif // !CHARACTER_CHARACTER_CHARACTER_H_