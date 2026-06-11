#pragma once

#include <vector>
#include <string>
 
class EnemyData
{
public:
	EnemyData() = default;
	virtual ~EnemyData() = default;
public:
	char minImage;
	std::vector<std::wstring> Image;
	int hp;
	int damage;
	int speed;
};



