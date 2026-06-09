#pragma once
#include <vector>
#include <string>

using std::string;
using std::vector;
 
class EnemyData
{
public:
	EnemyData() = default;
	virtual ~EnemyData() = default;
public:
	char minImage;
	vector<string> Image;
	int hp;
	int damage;
	int speed;

};

class TestEnemyData : public EnemyData
{
	TestEnemyData()
	{
		Image = { "12345","67890","24680","13579","임리우 천재" };
		hp = 100;
		damage = 10;
	}

};



