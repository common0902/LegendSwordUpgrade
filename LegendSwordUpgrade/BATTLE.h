#pragma once
#include "GameState.h"
#include "Enemy.h"

enum DelayType
{
	EnemyType,PlayerType,TestType
};


class BattleScene : public SceneState
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
	MoveEnemy* curEnemy;


public:
	bool Delay(int type, ULONGLONG time);
	bool Delay(DelayType type, ULONGLONG time);
	
};
ULONGLONG GetDeltaTime(ULONGLONG lastTime);
void DrawEnemyImage(MoveEnemy* enemy, int x, int y);
Vector2 GetMoveDir();
void GotoXY(Vector2 pos);
int GetRandomRange(int min, int max);
bool Random(int probability);


