#pragma once
#include "GameState.h"

class TitleScene : public SceneState
{
public:
	TitleScene(GameState& gameState) : SceneState(gameState) {}
	void Enter() override;
	void Update() override;
	void Render() const override;
	void Exit() override;
};

