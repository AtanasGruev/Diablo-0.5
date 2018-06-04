#include "Enemy.h"
#include "Character.h"
#include <iostream>

Enemy::Enemy(const String& name, double health, double strength, double intelligence) : nameEnemy(name), healthPointsEnemy(health),
strengthEnemy(strength), intelligenceEnemy(intelligence), counterRounds(1)
{}

void Enemy::setHealth(double health)
{
	healthPointsEnemy = health;
}

String Enemy::getName() const
{
	return nameEnemy;
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

void Enemy::incrementCounterRounds()
{
	counterRounds++;
}

unsigned int Enemy::getCounterRounds() const
{
	return counterRounds;
}

void Enemy::setXEnemy(int xPos)
{
	xCoord = xPos;
}

void Enemy::setYEnemy(int yPos)
{
	yCoord = yPos;
}

int Enemy::getXEnemy() const
{
	return xCoord;
}

int Enemy::getYEnemy() const
{
	return yCoord;
}

void Enemy::placeEnemy(int newX, int newY)
{
	Enemy::setXEnemy(newX);
	Enemy::setYEnemy(newY);
}