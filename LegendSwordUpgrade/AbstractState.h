#pragma once

struct GameState;

class AbstractState
{
public:
	GameState& state;
public:
	AbstractState(GameState& gameState) : state(gameState) { };
	virtual ~AbstractState() = default;
public:
	virtual void Enter() abstract;
	virtual void Update() abstract;
	virtual void Render() const abstract;
	virtual void Exit() abstract;
};

