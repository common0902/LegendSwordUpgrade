#pragma once
#include "GameState.h"
#include "SceneState.h"

class ShopScene : public SceneState
{
public:
	ShopScene(GameState& gameState) : SceneState(gameState) {}
	void Enter() override;
	void Update() override;
	void Render() const override;
	void Exit() override;
};
