#pragma once
#include"AbstractState.h"

struct GameState;

class SceneState : public AbstractState
{
public:
	GameState& state;
public:
	SceneState(GameState& gameState) : AbstractState(), state(gameState) {}
	virtual ~SceneState() = default;


};



