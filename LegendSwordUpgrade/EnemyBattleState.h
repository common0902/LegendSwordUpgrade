#pragma once
#include"InBattleSceneState.h"

class EnemyBattleState : public InBattleSceneState
{
public:
	EnemyBattleState(BattleScene& battle) : InBattleSceneState(battle) {}
	void Enter() override;
	void Update() override;
	void Render() const override;
	void Exit() override;
};