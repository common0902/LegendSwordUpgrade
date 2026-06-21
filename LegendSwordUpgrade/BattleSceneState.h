#pragma once
#include"AbstractState.h"

class BattleScene;

class BattleSceneState : public AbstractState
{
public:
	BattleScene& scene;
public:
	BattleSceneState(BattleScene& battleScene) : AbstractState(), scene(battleScene) {}
	virtual ~BattleSceneState() = default;

};

