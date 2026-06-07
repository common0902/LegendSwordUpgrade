#pragma once
#include "GameState.h"

class ShopScene : public AbstractState
{
public:
	ShopScene(GameState& gameState) : AbstractState(gameState) {}
	void Enter() override;
	void Update() override;
	void Render() const override;
	void Exit() override;
};