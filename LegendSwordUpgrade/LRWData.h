#pragma once
#include"TextData.h"

struct Vector2
{
public:
	Vector2()
	{
		x = 0;
		y = 0;
	}
	Vector2(int startx, int starty)
	{
		x = startx;
		y = starty;
	}
	~Vector2() = default;
public:
	int x;
	int y;

public:
	Vector2 operator+ (Vector2 p)
	{
		return Vector2{ x + p.x,y + p.y };
	}
	void operator+= (Vector2 p)
	{
		x += p.x;
		y += p.y;
	}
	Vector2 operator- (Vector2 p)
	{
		return Vector2{ x - p.x,y - p.y };
	}
	Vector2 operator* (Vector2 p)
	{
		return Vector2{ x * p.x,y * p.y };
	}
	Vector2 operator* (int p)
	{
		return Vector2{ x * p,y * p };
	}
	Vector2 operator/ (int p)
	{
		return Vector2{ x / p, y / p };
	}
	bool operator==(Vector2 p)
	{
		return x == p.x && y == p.y;
	}
};


struct LRWData
{
#pragma region TestTitle
public:
	int curMenu; 

#pragma endregion

#pragma region BattleScene
public:





#pragma endregion

};


