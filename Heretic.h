#ifndef HERETIC_HERETIC_HERETIC_H
#define HERETIC_HERETIC_HERETIC_H

#include "Enemy.h"

class Heretic : virtual public Enemy
{
public:
	Heretic(const String&); //constructor with parameter

	virtual double attackEnemy(Character*); //attack
	virtual double defendEnemy(double); //defend

	virtual void printOnMap(char(*map)[10]); //visualisation on the map
};

#endif // !HERETIC_HERETIC_HERETIC_H

