#pragma once
#include "GameState.h"
#include "SceneState.h"

class WinScene : public SceneState
{
public:
	WinScene(GameState& gameState) : SceneState(gameState) {}
	void Enter() override;
	void Update() override;
	void Render() const override;
	void Exit() override;
};


