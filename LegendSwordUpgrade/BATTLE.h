#pragma once
#include"GameState.h"
#include"SceneState.h"
#include"Enemy.h"
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
	int curPlayerHp = 0;
	int curDamage = 0;
	vector<wstring> image;


public:
	void BaseUI() const;
	void DrawPlayerStat() const;
	void DrawCurrentSword() const;
	
	
	
};



ULONGLONG GetDeltaTime(ULONGLONG lastTime);
bool Delay(int type, ULONGLONG time);
bool Delay(DelayType type, ULONGLONG time);
void GotoXY(Vector2 pos);
int GetRandomRange(int min, int max);
bool Random(int probability);
void DrawImage(vector<wstring> image, int x, int y, int maxWIDTH, int maxHEIGHT);
void DrawImage(vector<wstring> image, Vector2 pos, Vector2 size);
void DrawImage(vector<wstring> image, Vector2 pos);
Color GetHealthColor(int curHp, int maxHp);
string GetBarString(int value, int maxValue,
	int barWidth, const string& fillChar = "бс", const string& emptyChar = "бр");
string GetIntString(int value);
string GetEmptyString(int size);
string CenterText(string text, int size);
