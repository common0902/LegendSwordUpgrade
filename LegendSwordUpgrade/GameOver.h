#pragma once
#include "GameState.h"
#include "SceneState.h"

class GameOverScene : public SceneState
{
public:
	GameOverScene(GameState& gameState) : SceneState(gameState) {}
	void Enter() override;
	void Update() override;
	void Render() const override;
	void Exit() override;
};


