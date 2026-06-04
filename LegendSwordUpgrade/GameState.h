#pragma once
#include "Enums.h"
#define NOMINMAX
#include<Windows.h>
#include<vector>

#include "Player.h"
#include "CHGData.h"
#include "LRWData.h"
#include "PMSData.h"
#include "FSM.h"
#include"Console.h"

constexpr int WIDTH = 160;
constexpr int HEIGHT = 45;

struct GameState
{
	FSM* fsm;
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

