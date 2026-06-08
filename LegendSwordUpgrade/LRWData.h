#pragma once

struct Vector2
{
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


