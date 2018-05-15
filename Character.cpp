#include "Character.h"
#include <iostream>

/*
CLASS CHARACTER INTERFACE
*/

Character::Character(const String& name, unsigned int level, double health, double strength, double intelligence) : nameHero(name), levelHero(level),
healthPointsHero(health), strengthHero(strength), originalStrengthHero(strength), intelligenceHero(intelligence), originalIntelligenceHero(intelligence)
{}

Character::Character(const Character& copyCharacter) : nameHero(copyCharacter.nameHero), levelHero(copyCharacter.levelHero),
healthPointsHero(copyCharacter.healthPointsHero), strengthHero(copyCharacter.strengthHero), originalStrengthHero(copyCharacter.strengthHero),
intelligenceHero(copyCharacter.intelligenceHero), originalIntelligenceHero(copyCharacter.intelligenceHero)
{}

void Character::setHealth(double health)
{
	healthPointsHero = health;
}

double Character::getHealth() const
{
	return healthPointsHero;
}

double Character::getStrength() const
{
	return strengthHero;
}

double Character::getIntelligence() const
{
	return intelligenceHero;
}

double Character::getMinimumAbility() const
{
	if (strengthHero < intelligenceHero) return strengthHero;
	else return intelligenceHero;
}

void Character::attackHero(Enemy& enemy)
{}

void Character::defendHer�(double damageEnemy)
{
	damageEnemy -= (strengthHero / 100)*damageEnemy;
}

void Character::levelUpHero()
{
	healthPointsHero = (110 / 100)*healthPointsHero;
	strengthHero += (originalStrengthHero / (originalStrengthHero + originalIntelligenceHero)) * 5;
	intelligenceHero += (originalIntelligenceHero / (originalStrengthHero + originalIntelligenceHero)) * 5;
}

/*
CLASS ENEMY INTERFACE
*/

Enemy::Enemy(const String& name, double health, double strength, double intelligence) : nameEnemy(name), healthPointsEnemy(health),
strengthEnemy(strength), intelligenceEnemy(intelligence)
{}

Enemy::Enemy(const Enemy& copyEnemy) : nameEnemy(copyEnemy.nameEnemy), healthPointsEnemy(copyEnemy.healthPointsEnemy),
strengthEnemy(copyEnemy.strengthEnemy), intelligenceEnemy(copyEnemy.intelligenceEnemy)
{}

void Enemy::setHealth(double health)
{
	healthPointsEnemy = health;
}

double Enemy::getHealth() const
{
	return healthPointsEnemy;
}

double Enemy::getStrength() const
{
	return strengthEnemy;
}

double Enemy::getIntelligence() const
{
	return intelligenceEnemy;
}

void Enemy::attackEnemy(Character& hero)
{}

void Enemy::defendEnemy(double damageHero)
{
	damageHero -= (strengthEnemy / 100)*damageHero;
}

/*
CLASS BARBARIAN INTERFACE
*/

Barbarian::Barbarian(const String& name) : Character(name, 1, 100, 10, 3), rageBarbarian(0), rageForNextBattle(0)
{}

Barbarian::Barbarian(const Barbarian& copyBarbarian) : Character(copyBarbarian), rageBarbarian(copyBarbarian.rageBarbarian),
rageForNextBattle(copyBarbarian.rageForNextBattle)
{}

double Barbarian::getRage() const
{
	return rageBarbarian;
}

double Barbarian::getMinimumAbility() const
{
	double minAbility = Character::getMinimumAbility();
	if (minAbility < rageBarbarian) return minAbility;
	else return rageBarbarian;
}

bool Barbarian::isRageAllowed(int rage) const
{
	return (rage < 100);
}

void Barbarian::attackHero(Enemy& enemy)
{
	double rageMultiplier = (rageBarbarian / 5) / 100;
	double damageBarbarian = (100 + rageMultiplier) *(getStrength() + 0.2*getIntelligence());
	if (isRageAllowed(rageForNextBattle)) rageForNextBattle += 2;
}

void Barbarian::defendHer�(double damageEnemy)
{
	Character::defendHer�(damageEnemy);
}

void Barbarian::levelUpHero()
{
	Character::levelUpHero();
}

/*
CLASS SORCERER INTERFACE
*/

Sorcerer::Sorcerer(const String& name) : Character(name, 1, 70, 4, 12), manaSorcerer(100), manaCapacity(100)
{}

Sorcerer::Sorcerer(const Sorcerer& copySorcerer) : Character(copySorcerer), manaSorcerer(copySorcerer.manaSorcerer), manaCapacity(copySorcerer.manaCapacity)
{}

double Sorcerer::getMana() const
{
	return manaSorcerer;
}

double Sorcerer::getMinimumAbility() const
{
	double minAbility = Character::getMinimumAbility();
	if (minAbility < manaSorcerer) return minAbility;
	else return manaSorcerer;
}

void Sorcerer::attackHero(Enemy& enemy)
{
	double damageSorcerer = (0.5 + (manaSorcerer / manaCapacity)*0.75)*getIntelligence();
	manaSorcerer -= (10 / 100)*manaCapacity;
}

void Sorcerer::defendHer�(double damageEnemy)
{
	Character::defendHer�(damageEnemy);
}

void Sorcerer::levelUpHero()
{
	Character::levelUpHero();
	manaCapacity += (10 / 100)*manaCapacity;
}

/*
CLASS BOUNTYHUNTER INTERFACE
*/

BountyHunter::BountyHunter(const String& name) : Character(name, 80, 1, 9, 6), agilityBountyHunter(10)
{}

BountyHunter::BountyHunter(const BountyHunter& copyBountyHunter) : Character(copyBountyHunter), agilityBountyHunter(copyBountyHunter.agilityBountyHunter)
{}

double BountyHunter::getAgility() const
{
	return agilityBountyHunter;
}

double BountyHunter::getMinimumAbility() const
{
	double minAbility = Character::getMinimumAbility();
	if (minAbility < agilityBountyHunter) return minAbility;
	else return agilityBountyHunter;
}

void BountyHunter::attackHero(Enemy& enemy)
{
	double damageBountyHunter;
	if (roundCounter % 3 == 0)
	{
		damageBountyHunter = agilityBountyHunter + 0.4*getIntelligence() + 0.6*getStrength();
	}
	else 
	{ 
		damageBountyHunter = 0.8*agilityBountyHunter; 
	}
}

void BountyHunter::defendHer�(double damageEnemy)
{
	Character::defendHer�(damageEnemy);
}

void BountyHunter::levelUpHero()
{
	Character::levelUpHero();
	agilityBountyHunter += 4;
}

//
//	enemy.setHealth(getHealth() - damageBarbarian);
//

/*
CLASS SKELETON INTERFACE
*/

Skeleton::Skeleton(const String& name) : Enemy(name, 32, 3, 0)
{}

Skeleton::Skeleton(const Skeleton& copySkeleton) : Enemy(copySkeleton)
{}

void Skeleton::attackEnemy(Character& character)
{
	double damageSkeleton = getStrength() + 0.1*character.getIntelligence();
}

void Skeleton::defendEnemy(double damageCharacter)
{
	Enemy::defendEnemy(damageCharacter);
}

/*
CLASS HERETIC INTERFACE
*/

Heretic::Heretic(const String& name) : Enemy(name, 20, 1, 4)
{}

Heretic::Heretic(const Heretic& copyHeretic) : Enemy(copyHeretic)
{}

void Heretic::attackEnemy(Character& character)
{
	double damageHeretic = character.getMinimumAbility() + getIntelligence();
}

void Heretic::defendEnemy(double damageCharacter)
{
	Enemy::defendEnemy(damageCharacter);
}