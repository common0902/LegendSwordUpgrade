#pragma once
#include"InBattleSceneState.h"

class NormalBattleMapState : public InBattleSceneState
{
public:
	NormalBattleMapState(BattleScene& battle) : InBattleSceneState(battle) {}
	void Enter() override;
	void Update() override;
	void Render() const override;
	void Exit() override;
};