#pragma once
#include "GameState.h"

void InitBattle(GameState& state);
void UpdateBattle(GameState& state);
void RenderBattle(const GameState& state);

struct Point
{
public:
	int x;
	int y;

	Point operator+ (Point p)
	{
		return Point{ x + p.x,y + p.y };
	}
	Point operator- (Point p)
	{
		return Point{ x - p.x,y - p.y };
	}
	Point operator* (Point p)
	{
		return Point{ x * p.x,y * p.y };
	}

};