#pragma once
#include "GameState.h"
#include "SceneState.h"
#include "SlotMachine.h"

class ShopScene : public SceneState
{
	SlotMachine slotMachine;
public:
	ShopScene(GameState& gameState) : SceneState(gameState) {}
	void Enter() override;
	void Update() override;
	void Render() const override;
	void Exit() override;
};
