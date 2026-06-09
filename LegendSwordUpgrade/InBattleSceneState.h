#pragma once
#include"AbstractState.h"

class BattleScene;

class InBattleSceneState : public AbstractState
{
public:
	BattleScene& battleScene;

public:
	InBattleSceneState(BattleScene& battle) : AbstractState(), battleScene(battle) {}
};
