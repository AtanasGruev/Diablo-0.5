#ifndef ENEMY_ENEMY_ENEMY_H_
#define ENEMY_ENEMY_ENEMY_H_

#include "String.h"

class Character;

class Enemy
{
private:
	String nameEnemy; //name
	double healthPointsEnemy; //remaining HP

	//abilities
	double strengthEnemy; //strength
	double intelligenceEnemy; //intelligence

	//placement on a 10-by-10 grid, which acts as a map
	int xCoord;
	int yCoord;

	unsigned int counterRounds; //rounds signify current attack modes for some enemies

public:
	Enemy(const String&, double, double, double); //constructor with parameters

	//setter
	virtual void setHealth(double);

	//getters
	String getName() const;
	double getHealth() const;
	double getStrength() const;
	double getIntelligence() const;

	//counter functionality
	void incrementCounterRounds();
	unsigned int getCounterRounds() const;

	//quintessential virtual functions
	virtual double attackEnemy(Character*) = 0; //causes damage to a hero
	virtual double defendEnemy(double damageHero) = 0; //caused damage is reduced by <strength>%
	virtual double necromancerSkeleton() { return -1; }; //returns negative in all but Necromancer's case

	//funtions that control placement and visualisation on the map
	void setXEnemy(int);
	void setYEnemy(int);
	int getXEnemy() const;
	int getYEnemy() const;
	void placeEnemy(int, int);
	virtual void printOnMap(char(*map)[10]) = 0;
};

#endif // !ENEMY_ENEMY_ENEMY_H_
