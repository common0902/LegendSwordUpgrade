#pragma once

class Enemy
{
public:
	Enemy(string enemyName,vector<wstring> enemyImage, int enemyMaxHp, int enemyDamage, int enemyAttackSpeed)
	{
		name = enemyName;
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
	string name;
	vector<wstring> image;
	int curHp;
	int maxHp;
	int damage;
	int attackSppeed;
};
