#pragma once
#include "GameState.h"

Vector2 GetMoveDir();
void GotoXY(Vector2 pos);

class BattleScene : public AbstractState
{
public:
	BattleScene(GameState& gameState) : AbstractState(gameState) {}
	void Enter() override;
	void Update() override;
	void Render() const override;
	void Exit() override;
public:
	ULONGLONG lastInput;
	
	
};





