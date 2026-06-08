#pragma once
#include "GameState.h"


enum DelayType
{
	EnemyType,PlayerType,TestType
};


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
	std::map<int, ULONGLONG> lastTimeMap;
	int curHp;


public:
	ULONGLONG GetDeltaTime(ULONGLONG lastTime);
	bool Delay(int type, ULONGLONG time);
	bool Delay(DelayType type, ULONGLONG time);
	
};

Vector2 GetMoveDir();
void GotoXY(Vector2 pos);





