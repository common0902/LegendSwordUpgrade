#pragma once
#include "GameState.h"

class UpgradeScene : public AbstractState
{
public:
	UpgradeScene(GameState& gameState) : AbstractState(gameState) {}
	void Enter() override;
	void Update() override;
	void Render() const override;
	void Exit() override;
};