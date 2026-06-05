#pragma once
#include "GameState.h"

struct Vector2;

class BattleScene : public AbstractState
{
public:
	BattleScene(GameState& gameState) : AbstractState(gameState) {}
	void Enter() override;
	void Update() override;
	void Render() const override;
	void Exit() override;
public:
	ULONGLONG lastInput;


};

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