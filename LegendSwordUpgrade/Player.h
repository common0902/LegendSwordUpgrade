#pragma once
#include "Sword.h"
struct CHGData;

class Player
{
public:
	int attackSpeed;
	int str;
	int MaxHp;

	void ApplyTotem(const CHGData& data);
};

