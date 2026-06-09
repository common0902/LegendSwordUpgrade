#pragma once
#include "EnemyData.h"

class MoveEnemy
{
public:
	MoveEnemy(char enemyImage,int type,int speed)
	{
		image = enemyImage;
		hp = enemyHp;
		damage = enemyDamage;
	}
	~MoveEnemy()
	{

	}
public:
	char image;
	int type;
	int speed;
};