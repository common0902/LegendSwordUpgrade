#pragma once
#include "EnemyData.h"

class Enemy
{
public:
	Enemy(vector<string> enemyImage,int enemyHp,int enemyDamage)
	{
		image = enemyImage;
		hp = enemyHp;
		damage = enemyDamage;
	}
	~Enemy()
	{

	}
public:
	int hp;
	int damage;
	vector<string> image;

};