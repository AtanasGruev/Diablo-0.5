#ifndef SKELETON_SKELETON_SKELETON_H
#define SKELETON_SKELETON_SKELETON_H

#include "Enemy.h"

class Skeleton : virtual public Enemy
{
public:
	Skeleton(const String&); //constructor with parameter

	virtual double attackEnemy(Character*); //attack
	virtual double defendEnemy(double); //defend

	virtual void printOnMap(char(*map)[10]); //visualisation on the map 
};

#endif // !SKELETON_SKELETON_SKELETON_H
