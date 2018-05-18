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

	//counters
protected:
	unsigned int counterLevelUp; //counter for killed enemies, used to level up
	unsigned int counterRounds; //counter for rounds
	//if(counterLevelUp == pow(2,level)) levelUpHero();
private:
	//placement on a 10-by-10 grid, which acts as a map
	int xCoord;
	int yCoord;
public:
	Character(const String&, unsigned int, double, double, double);

	//setters
	void setHealth(double);
	//getters
	double getHealth() const;
	double getLevel() const;
	double getCounterLevelUp() const;
	double getStrength() const; 
	double getIntelligence() const; 
	virtual double getMinimumAbility() const;
	virtual double getSpecialAbility() const = 0;

	virtual double attackHero()=0; //causes damage to an enemy
	///if defendHero(double) is virtual, should the same-name function be defined in derivative classes
	virtual double defendHerî(double); //caused damage is reduced by <strength>%
	virtual void levelUpHero(); //enhances the ability of the hero according to the formula below
						//<new value of ability> = [(<start_value_of_ability>/(<start_value_of_strengthHero 
						//+ start_value_of_intelligenceHero)) * 5] + <current_value_of_ability>

	void setXCharacter(int);
	void setYCharacter(int);
	int getXCharacter() const;
	int getYCharacter() const;
	void moveCharacter();

	//battle mechanics - virtual functions, which are then overriden
	virtual void battleWithSkeletonOrHeretic(Enemy*) = 0;
	void printBattleWithSkeletonOrHeretic(Enemy*, double, double);

	//virtual void battleWithNecromancer(Enemy*) = 0;
	//virtual void battleWithDiablo(Enemy*) = 0;
};

class Barbarian : public Character
{
private:
	int rageBarbarian;
	int rageForNextBattle;
	bool rageFlag;
public:
	Barbarian(const String&);
	virtual  double getSpecialAbility() const; // returns rage left
	virtual double getMinimumAbility() const;

	double attackHero();  
	double defendHerî(double); 
	void levelUpHero();

	bool isRageAllowed(int) const;

	virtual void battleWithSkeletonOrHeretic(Enemy*);
};

class Sorcerer : public Character
{
private:
	double manaSorcerer;
	double manaCapacity;
public:
	Sorcerer(const String&);
	double getSpecialAbility() const; //returns mana left
	virtual double getMinimumAbility() const;

	double attackHero();
	double defendHerî(double);
	void levelUpHero();

	virtual void battleWithSkeletonOrHeretic(Enemy*);

};

class BountyHunter : public Character
{
private:
	double agilityBountyHunter;
public:
	BountyHunter(const String&);
	virtual double getSpecialAbility() const; //return agility 
	virtual double getMinimumAbility() const;

	double attackHero();
	double defendHerî(double);
	void levelUpHero();

	virtual void battleWithSkeletonOrHeretic(Enemy*);
};

#endif // !CHARACTER_CHARACTER_CHARACTER_H_