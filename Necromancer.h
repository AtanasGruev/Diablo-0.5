#ifndef NECROMANCER_NECROMANCER_NECROMANCER_H
#define NECROMANCER_NECROMANCER_NECROMANCER_H

#include "Enemy.h"
#include "Skeleton.h"

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
	virtual double necromancerSkeleton(); //checks whether skeleton servant is alive in the general case of pointer to Enemy

	virtual void printOnMap(char(*map)[10]); //visualisation on the map
};

#endif // !NECROMANCER_NECROMANCER_NECROMANCER_H
