#pragma once
#include"GameState.h"
#include"SceneState.h"
#include"Enemy.h"
#include"EventControler.h"

enum DelayType
{
	EnemyType,PlayerType,TestType
};

enum BattleEventType
{
	Heal, EnemyBattle,Null
};


class BattleScene : public SceneState
{
public:
	BattleScene(GameState& gameState) : SceneState(gameState)
	{

	};
	void Enter() override;
	void Update() override;
	void Render() const override;
	void Exit() override;
	
public:
	int curPlayerHp = 0;
	int curDamage = 0;
	int attackProbability = 0;
	vector<wstring> curSwordImage;
	string swordName;

public:
	EventControler eventControler;
	int curState = 1;
	int curClearStage = 0;
	int curPhase = 1;
	int curMaxPhase = 1;
public:
	void StatSetting();
	void StageSetting();
	void StageChoose();
	int StageInput(Vector2 inputPo) const;
	void SwordSetting();
	void EventSetting();

	void DrawBaseUI() const;
	void DrawPlayerStat() const;
	void DrawCurrentSword() const;

	void StageClear();

public:
	BattleEventType GetRandomEvent() const;
	int GetMaxPhase(int stage) const;
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
string GetBarString(int value, int maxValue, int barWidth, const string& fillChar = "бс", const string& emptyChar = "бр");
string GetIntString(int value);
string GetEmptyString(int size);
string CenterText(string text, int size);
void SkipBreak();
void CanSkipSleep(int delay);
void Typing(string text, int delay,bool endl = true);
void ScreenReset();
void WaitInput();
int GetIntInput(int min, int max);
bool InputYorN();
string ToString(int value);
