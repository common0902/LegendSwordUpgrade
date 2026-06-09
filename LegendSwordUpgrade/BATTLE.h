#pragma once
#include "GameState.h"
#include "Enemy.h"
#include"TextData.h"

enum DelayType
{
	EnemyType,PlayerType,TestType
};


class BattleScene : public SceneState
{
public:
	BattleScene(GameState& gameState) : SceneState(gameState) {}
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
Vector2 GetMoveDir();
void GotoXY(Vector2 pos);
int GetRandomRange(int min, int max);
bool Random(int probability);
void DrawImage(vector<string> image,int x, int y);

