#pragma once
#include "EnemyData.h"

class Enemy
{
public:
	Enemy(EnemyData data)
	{
		maxHp = data.hp;
		curHp = maxHp;
		damage = data.damage;
		image = data.Image;
	}
	virtual ~Enemy()
	{

	}
public:
	vector<wstring> image;
	int curHp;
	int maxHp;
	int damage;
};