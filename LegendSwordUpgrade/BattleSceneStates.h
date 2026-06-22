#pragma once
#include"BattleSceneState.h"



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


class BattleSceneBattleState : public BattleSceneState
{
public:
	BattleSceneBattleState(BattleScene& scene) : BattleSceneState(scene) {}
	virtual ~BattleSceneBattleState() = default;

public:
	void Enter() override;
	void Update() override;
	void Render() const override;
	void Exit() override;

public:
	int curStage;

};

void CircleFade(int delay);




