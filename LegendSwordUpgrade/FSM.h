#pragma once
#include"AbstractState.h"
#include<map>

class FSM
{
private:
	AbstractState* curScene;
	std::map<int, AbstractState*> stateMap;

public:
	FSM() = default;
	void AddState(int key, AbstractState* state)
	{
		stateMap[key] = state;
	}
	void SetState(int key)
	{
		curScene = stateMap[key];
		curScene->Enter();
	}
	void ChangeState(int key)
	{
		if(curScene != nullptr) curScene->Exit();
		SetState(key);
	}
	
public:
	void Update()
	{
		curScene->Update();
	}
	void Render() const
	{
		curScene->Render();
	}

};

