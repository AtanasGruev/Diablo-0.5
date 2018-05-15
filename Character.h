#ifndef CHARACTER_CHARACTER_CHARACTER_H_
#define CHARACTER_CHARACTER_CHARACTER_H_

int round = 1;
#include "String.h"

//int roundCounter = 1;

class Character;
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
	double originalStrengthHero; //strength
	double originalIntelligenceHero; //intelligence

	//counter for killed enemies
	int counterLevelUp;
	//if(counterLevelUp == pow(2,level)) levelUpHero();
public:
	Character(const String&, unsigned int, double, double, double);
	Character(const Character&);

	//setters
	void setHealth(double);
	//getters
	double getHealth() const;
	double getStrength() const; 
	double getIntelligence() const; 

	void attackHero(Enemy&); //causes damage to an enemy
	void defendHerî(double); //caused damage is reduced by <strength>%
	void levelUpHero(); //enhances the ability of the hero according to the formula below
						//<new value of ability> = [(<start_value_of_ability>/(<start_value_of_strengthHero 
						//+ start_value_of_intelligenceHero)) * 5] + <current_value_of_ability>
};

class Enemy
{
private:
	String nameEnemy; //name
	double healthPointsEnemy; //remaining HP
	//abilities
	double strengthEnemy; //strength
	double intelligenceEnemy; //intelligence
public:
	Enemy(const String&,double, double, double);
	Enemy(const Enemy&);

	void setHealth(double);

	double getHealth() const;
	double getStrength() const;
	double getIntelligence() const;

	void attackEnemy(Character&); //causes damage to an enemy
	void defendEnemy(double damageHero); //caused damage is reduced by <strength>%
};

class Barbarian : public Character
{
private:
	int rageBarbarian;
	int rageForNextBattle;
public:
	Barbarian(const String&);
	Barbarian(const Barbarian&);
	
	void attackHero(Enemy&);  
	void defendHerî(double); 
	void levelUpHero();

	bool isRageAllowed(int) const;
};

class Sorcerer : public Character
{
private:
	double manaSorcerer;
	double manaCapacity;
public:
	Sorcerer(const String&);
	Sorcerer(const Sorcerer&);

	void attackHero(Enemy&);
	void defendHerî(double);
	void levelUpHero();
};

class BountyHunter : public Character
{
private:
	double agilityBountyHunter;
public:
	BountyHunter(const String&);
	BountyHunter(const BountyHunter&);

	void attackHero(Enemy&);
	void defendHerî(double);
	void levelUpHero();
};

#endif // !CHARACTER_CHARACTER_CHARACTER_H_