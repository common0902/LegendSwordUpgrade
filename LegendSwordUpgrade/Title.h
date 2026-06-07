#pragma once
#include "GameState.h"

class TitleScene : public AbstractState
{
public:
	TitleScene(GameState& gameState) : AbstractState(gameState) {}
	void Enter() override;
	void Update() override;
	void Render() const override;
	void Exit() override;
};

