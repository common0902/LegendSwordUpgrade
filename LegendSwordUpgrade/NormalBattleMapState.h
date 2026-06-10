#pragma once
#include"InBattleSceneState.h"
#include"LRWData.h"

class NormalBattleMapState : public InBattleSceneState
{
public:
	NormalBattleMapState(BattleScene& battle) : InBattleSceneState(battle) {}
	void Enter() override;
	void Update() override;
	void Render() const override;
	void Exit() override;

public:
	Vector2 GetMoveDir();
};

