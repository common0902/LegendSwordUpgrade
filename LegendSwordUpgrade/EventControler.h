#pragma once

#include"BattleEvent.h"
#include<map>

class EventControler {
private:
	std::map<int, BattleEvent*> events;

public:
	void AddEvent(int key, BattleEvent* event)
	{
		events[key] = event;
	}
	void Start(int key)
	{
		if (events[key] != nullptr) events[key]->Start();
	}
};