#pragma once
#include"BattleSceneState.h"
#include"GameState.h"

class BattleSceneStageState : public BattleSceneState
{
public:
	BattleSceneStageState(BattleScene& scene) : BattleSceneState(scene)
	{
		Init();
	}
	virtual ~BattleSceneStageState() = default;

public:
	void Init();
	void Enter() override;
	void Update() override;
	void Render() const override;
	void Exit() override;

public:
	void StageChange(int stage);


public:
	bool prevIsMouseCancelButton = true;
	bool isMouseCancelButton = false;
	bool* prevOnMouseStageButton;
	bool* OnMouseStageButton;
};

class Enemy;

class BattleSceneBattleState : public BattleSceneState
{
public:
	BattleSceneBattleState(BattleScene& scene) : BattleSceneState(scene) { }
	virtual ~BattleSceneBattleState() = default;

public:
	void Enter() override;
	void Update() override;
	void Render() const override;
	void Exit() override;

public:
	int curStage;
	Enemy* enemy;

public:
	ULONGLONG lastAttackTime;
	Vector2 curEnemyDrawPos;

public:
	int playerCurHp = 0;
	int playerMaxHp = 0;
	int playerDamage = 0;
	int playerAttackSpeed = 1;

public:
	void SetEnemyData();
	void PlayerAttack(int damage);
	string GetAttackDelayBarString(int value, int maxValue, int barWidth, string fillChar = "■", string emptyChar = "□") const;

};

void CircleFade(int delay);





