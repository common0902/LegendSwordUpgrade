#pragma once

class Enemy
{
public:
	Enemy(vector<wstring> enemyImage, int enemyMaxHp, int enemyDamage, int enemyAttackSpeed)
	{
		maxHp = enemyMaxHp;
		curHp = enemyMaxHp;
		damage = enemyDamage;
		image = enemyImage;
		attackSppeed = enemyAttackSpeed;
	}
	virtual ~Enemy()
	{

	}
public:
	vector<wstring> image;
	int curHp;
	int maxHp;
	int damage;
	int attackSppeed;
};
