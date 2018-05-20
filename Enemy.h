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
	virtual String getName() const;
	virtual double getHealth() const;
	double getStrength() const;
	double getIntelligence() const;

	//counter functionality
	void incrementCounterRounds();
	unsigned int getCounterRounds() const;

	//quintessential virtual functions
	virtual double attackEnemy(Character*)=0; //causes damage to a hero
	virtual double defendEnemy(double damageHero)=0; //caused damage is reduced by <strength>%

	//funtions that control placement and visualisation on the map
	void setXEnemy(int);
	void setYEnemy(int);
	int getXEnemy() const;
	int getYEnemy() const;
	void placeEnemy(int, int);
	virtual void printOnMap(char(*map)[10]) = 0;
};

class Skeleton : virtual public Enemy
{
public:
	Skeleton(const String&); //constructor with parameter

	virtual double attackEnemy(Character*); //attack
	virtual double defendEnemy(double); //defend

	virtual void printOnMap(char(*map)[10]); //visualisation on the map 
};

class Heretic : virtual public Enemy
{
public:
	Heretic(const String&); //constructor with parameter

	virtual double attackEnemy(Character*); //attack
	virtual double defendEnemy(double); //defend

	virtual void printOnMap(char(*map)[10]); //visualisation on the map

};

class Necromancer : public Enemy
{
private:
	Enemy* skeletonServant; //every third round of a battle a skeletonServant appears and protects the Necromancer
	bool skeletonIsAlive; //signalises whether the skeletonServant is still alive
public:
	Necromancer(const String&); //constructor with parameter
	~Necromancer(); //destructor, releases the memory for skeletonServant
	virtual double attackEnemy(Character*); //attack
	virtual double defendEnemy(double); //defend

	virtual void printOnMap(char(*map)[10]); //visualisation on the map

};

class Diablo : public Skeleton, public Heretic
{
public:
	Diablo(const String&); //constructor with parameter

	virtual double attackEnemy(Character*); //attack
	virtual double defendEnemy(double); //defend

	virtual void printOnMap(char(*map)[10]); //visualisation on the map

};

#endif //!ENEMY_ENEMY_ENEMY_H_