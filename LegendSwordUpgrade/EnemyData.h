#pragma once
#include <vector>
#include <string>

using std::string;
using std::vector;
 
class AbstractEnemyData
{
public:
	AbstractEnemyData() = default;
	virtual ~AbstractEnemyData() = default;
public:
	vector<string> Image;
	int hp;
	int damage;
};

class TestEnemyData : public AbstractEnemyData
{
	TestEnemyData()
	{
		Image = { "12345","67890","24680","13579","임리우 천재" };
		hp = 100;
		damage = 10;
	}

};



