#pragma once
#include"InBattleSceneState.h"
#include"LRWData.h"

class BattleSettingScene : public InBattleSceneState
{
public:
	BattleSettingScene(BattleScene& battle) : InBattleSceneState(battle) {}
	void Enter() override;
	void Update() override;
	void Render() const override;
	void Exit() override;

};




