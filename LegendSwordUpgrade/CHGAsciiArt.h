#pragma once
#include <windows.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using std::vector;
using std::string;
using std::wstring;  
using std::map;
using std::pair;

struct AsciiObjs
{

	vector<wstring> slotMachineArt;
	vector<vector<wstring>> slotArt;
	vector<wstring> infoUIArt;
	int currentGold;
	map<wstring, pair<int, wstring>>* items;

	vector<int> slotNum; 
	bool rolling;
	ULONGLONG startTime;
	ULONGLONG rollingTime; 
	ULONGLONG lastChangeTime;
	ULONGLONG changeInterval;

	ULONGLONG resultShowInterval; 
	bool resultShow;
	bool success;
	bool superSuccess;
	wstring getItem;

};

void CHGAsciiInit(AsciiObjs& objs);
void CHGAsciiInitRender(AsciiObjs& objs);
void CHGAsciiUpdate(AsciiObjs& objs);
void CHGAsciiRender(const AsciiObjs& objs);
void CHGRenderSlotArt(const AsciiObjs& objs, int slotIndex, int artIndex);
void CHGRenderInfoUI(const AsciiObjs& objs, int renderX, int renderY);