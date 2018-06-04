#ifndef DIABLO_DIABLO_DIABLO_H
#define DIABLO_DIABLO_DIABLO_H

#include "Skeleton.h"
#include "Heretic.h"

class Diablo : public Skeleton, public Heretic
{
public:
	Diablo(const String&); //constructor with parameter

	virtual double attackEnemy(Character*); //attack
	virtual double defendEnemy(double); //defend

	virtual void printOnMap(char(*map)[10]); //visualisation on the map
};

#endif // !DIABLO_DIABLO_DIABLO_H