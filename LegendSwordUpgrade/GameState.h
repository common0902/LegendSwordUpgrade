#pragma once
#include "Enums.h"
#define NOMINMAX
#include<Windows.h>
#include<vector>

#include "Player.h"

struct GameState
{
	Scene prevScene = Scene::NONE;
	Scene curScene = Scene::TITLE;
	Menu curMenu = Menu::START;
	bool isRunning = true;
	Player player;
	int gold = 0;
	ULONGLONG curTime;

};

