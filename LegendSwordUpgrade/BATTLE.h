#pragma once
#include "GameState.h"

class BattleScene : public AbstractState
{
public:
	BattleScene(GameState& gameState) : AbstractState(gameState) {}
	void Enter() override;
	void Update() override;
	void Render() const override;
	void Exit() override;
};

struct Point
{
public:
	int x;
	int y;

public:
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