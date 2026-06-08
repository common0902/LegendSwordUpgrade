#pragma once
#include "GameState.h"
#include "Enemy.h"

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
	ULONGLONG lastInput = 0;
	std::map<int, ULONGLONG> lastTimeMap;
	int curPlayerHp = 0;
	Enemy* curEnemy;


public:
	ULONGLONG GetDeltaTime(ULONGLONG lastTime);
	bool Delay(int type, ULONGLONG time);
	bool Delay(DelayType type, ULONGLONG time);
	
};

void DrawEnemyImage(Enemy* enemy, int x, int y);
Vector2 GetMoveDir();
void GotoXY(Vector2 pos);
int GetRandomRange(int min, int max);
bool CoutGoToXY(string str, int x, int y);



