#pragma once

class AbstractState
{
public:
	AbstractState(){ };
	virtual ~AbstractState() = default;
public:
	virtual void Enter() abstract;
	virtual void Update() abstract;
	virtual void Render() const abstract;
	virtual void Exit() abstract;
};

