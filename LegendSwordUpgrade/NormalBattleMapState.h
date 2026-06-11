#pragma once
#include"InBattleSceneState.h"
#include"LRWData.h"

class NormalBattleState : public InBattleSceneState
{
public:
	NormalBattleState(BattleScene& battle) : InBattleSceneState(battle) {}
	void Enter() override;
	void Update() override;
	void Render() const override;
	void Exit() override;

};

