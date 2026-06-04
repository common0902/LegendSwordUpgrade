#pragma once
#include "Enums.h"
#define NOMINMAX
#include<Windows.h>
#include<vector>

#include "Player.h"
#include "CHGData.h"
#include "LRWData.h"
#include "PMSData.h"

struct GameState
{
public:
	Scene prevScene = Scene::NONE;
	Scene curScene = Scene::TITLE;
	Menu curMenu = Menu::START;
	bool isRunning = true;
	Player player;
	ULONGLONG curTime;

	int gold = 0;
	Sword curSword;

	CHGData ChgData;
	LRWData LrwData;
	PMSData PmsData;
};

