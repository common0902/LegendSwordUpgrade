#pragma once
#include"GameState.h"
#include"SceneState.h"
#include"Enemy.h"
#include"BattleSceneStates.h"

enum DelayType
{
	PlayerAttackDelay
};

enum BattleAfterType
{
	EnemyHit
};

enum BattleSceneEnum
{
	Stage,Battle
};


class BattleScene : public SceneState
{
public:
	BattleScene(GameState& gameState) : SceneState(gameState)
	{
		Init();
	}
	void Init();
	void Enter() override;
	void Update() override;
	void Render() const override;
	void Exit() override;
	
public:
	FSM fsm;

public:
	const int maxStage = 5;
	int curStage = 1;
	int curClearStage = 0;

public:
	void ChangeScene(int scene);
	void ChangeState(BattleSceneEnum state);
};



ULONGLONG GetDeltaTime(ULONGLONG lastTime);
ULONGLONG GetDelayDeltaTime(int key);
bool Delay(int type, ULONGLONG time);
bool Delay(DelayType type, ULONGLONG time);
void GotoXY(Vector2 pos);
bool IsGotoXY(Vector2 pos);
int GetRandomRange(int min, int max);
bool Random(int probability);
void DrawImage(vector<wstring> image, int x, int y, int maxWIDTH, int maxHEIGHT);
void DrawImage(vector<wstring> image, Vector2 pos, Vector2 size);
void DrawImage(vector<wstring> image, Vector2 pos);
Color GetHealthColor(int curHp, int maxHp);
string GetBarString(int value, int maxValue, int barWidth, const string& fillChar = "■", const string& emptyChar = "□");
string GetIntString(int value);
string GetEmptyString(int size);
string CenterText(string text, int size);
void SkipBreak();
void CanSkipSleep(int delay);
void Typing(string text, int delay,bool endl = true);
void WaitInput();
int GetIntInput(int min, int max);
bool InputYorN();
string ToString(int value);
void CLS();
bool IsNumder(const string text);
int ToInt(const string text);
Vector2 GetMousePos();
Vector2 GetSize(vector<wstring> image);
bool IsMouseUp(Vector2 leftUpPos, Vector2 rightDownPos);
bool IsMouseUp(Vector2 leftUpPos, vector<wstring> image);
bool IsButtonClick(Vector2 leftUpPos,Vector2 rightDownPos);
bool IsButtonClick(Vector2 leftUpPos, vector<wstring> image);
bool DelayButton(Vector2 leftPos, vector<wstring> image,
	int type, ULONGLONG delay);
void BoolReverse(bool& value);

void SetAfterValue(int key, ULONGLONG afterTime);
bool GetAfterValue(int key);
