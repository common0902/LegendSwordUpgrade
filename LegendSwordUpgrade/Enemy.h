#pragma once
#include "EnemyData.h"

class MoveEnemy
{
public:
	MoveEnemy(char enemyImage,int enemyType,int enemySpeed)
	{
		image = enemyImage;
		type = enemyType;
		speed = enemySpeed;
	}
	~MoveEnemy()
	{

	}
public:
	char image;
	int type;
	int speed;
};