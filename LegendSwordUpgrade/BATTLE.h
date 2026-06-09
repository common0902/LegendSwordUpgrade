#pragma once
#include"GameState.h"
#include"SceneState.h"
#include "Enemy.h"
#include"NormalBattleMapState.h"
#include"EnemyBattleState.h"

enum DelayType
{
	EnemyType,PlayerType,TestType
};

enum InBattleState
{
	NormalBattleMap, EnemyBattle
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
	FSM BattelSceneFsm;
	std::map<int, ULONGLONG> lastTimeDict;
	int curPlayerHp = 0;



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





