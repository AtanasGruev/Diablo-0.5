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

	int xCoord;
	int yCoord;

	unsigned int counterRounds;

public:
	Enemy(const String&, double, double, double);

	virtual void setHealth(double);

	virtual String getName()  const;
	virtual double getHealth() const;
	double getStrength() const;
	double getIntelligence() const;

	void incrementCounterRounds();
	unsigned int getCounterRounds() const;

	virtual double attackEnemy(Character*)=0; //causes damage to a hero
	virtual double defendEnemy(double damageHero)=0; //caused damage is reduced by <strength>%

	void setXEnemy(int);
	void setYEnemy(int);
	int getXEnemy() const;
	int getYEnemy() const;
	void placeEnemy(int, int);
};

class Skeleton : virtual public Enemy
{
public:
	Skeleton(const String&);

	virtual double attackEnemy(Character*);
	virtual double defendEnemy(double);
};

class Heretic : virtual public Enemy
{
public:
	Heretic(const String&);

	double attackEnemy(Character*);
	double defendEnemy(double);
};

class Necromancer : public Enemy
{
private:
	Enemy* skeletonServant;
	bool skeletonIsAlive;
public:
	Necromancer(const String&);
	~Necromancer();
	double attackEnemy(Character*);
	double defendEnemy(double);
};

class Diablo : public Skeleton, public Heretic
{
public:
	Diablo(const String&);

	double attackEnemy(Character*);
	double defendEnemy(double);
};

#endif //!ENEMY_ENEMY_ENEMY_H_