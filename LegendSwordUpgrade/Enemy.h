#pragma once

class Enemy
{
public:
	Enemy(vector<wstring> enemyImage,int enemyMaxHp,int enemyDamage)
	{
		maxHp = enemyMaxHp;
		curHp = enemyMaxHp;
		damage = enemyDamage;
		image = enemyImage;
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
