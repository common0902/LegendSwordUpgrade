#pragma once
#include "AbstractState.h"
#include<map>

class FSM
{
private:
	AbstractState* curScene = nullptr;
	std::map<int, AbstractState*> stateMap;

public:
	FSM() = default;
	void AddState(int key, AbstractState* state)
	{
		stateMap[key] = state;
	}
	void ChangeState(int key)
	{
		if (curScene != nullptr) curScene->Exit();
		curScene = stateMap[key];
		if (curScene != nullptr) curScene->Enter();
	}
	
public:
	void Update()
	{
		if (curScene != nullptr) curScene->Update();
	}
	void Render() const
	{
		if (curScene != nullptr) curScene->Render();
	}
	

};

