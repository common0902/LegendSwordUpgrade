#pragma once
#include<vector>
#include<string>
using std::vector;
using std::string;
class Sword
{
public:
	int damage = 0;
	vector<string> image;
	Sword() = default;
	~Sword() = default;
	float chance = 100;
	int tier = 1;
	int upgradeCost;
	int sellCost;


};

