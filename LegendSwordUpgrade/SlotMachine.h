#pragma once
#include <windows.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include "GameState.h"
using std::vector;
using std::string;
using std::wstring;
using std::map;
using std::pair;

struct RollResult
{
	wstring item;
	bool superSuccess = false;
};

class SlotMachine
{
public:
	SlotMachine() = default;
	~SlotMachine() = default;

	void Init(GameState& gameState);
	void Update();
	void Render() const;

	bool CanRoll() const;
	void StartRoll(bool success, bool super);
	RollResult ConsumeResult();
private:
	void InitRender();
	void RenderSlotArt(int slotIndex, int artIndex) const;
	void RenderNullSlotArt(int slotIndex) const;
	void RenderInfoUI(int renderX, int renderY) const;

private:
	GameState* state = nullptr;

	vector<wstring> slotMachineArt;
	vector<vector<wstring>> slotArt;
	vector<wstring> infoUIArt;

	vector<int> slotNum;
	bool rolling = false;
	ULONGLONG startTime = 0;
	ULONGLONG rollingTime = 0;
	ULONGLONG lastChangeTime = 0;
	ULONGLONG changeInterval = 0;

	ULONGLONG resultShowStartTime = 0;
	ULONGLONG resultShowInterval = 0;
	bool resultShow = false;
	bool success = false;
	bool superSuccess = false;
	wstring getItem;
	int resultShowIndex = 0;
};
