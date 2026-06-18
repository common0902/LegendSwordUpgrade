#pragma once
#include"BattleSceneState.h"



class BattleSceneStageState : public BattleSceneState
{
public:
	BattleSceneStageState(BattleScene& scene) : BattleSceneState(scene) {}
	virtual ~BattleSceneStageState() = default;

public:
	void Enter() override;
	void Update() override;
	void Render() const override;
	void Exit() override;

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

};











