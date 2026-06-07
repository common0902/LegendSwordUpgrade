#pragma once
#include "GameState.h"

class GameOverScene : public AbstractState
{
public:
	GameOverScene(GameState& gameState) : AbstractState(gameState) {}
	void Enter() override;
	void Update() override;
	void Render() const override;
	void Exit() override;
};


