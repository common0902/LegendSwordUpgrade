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

struct AsciiObjs
{

	vector<wstring> slotMachine;
	vector<vector<wstring>> slotArt;
	int currentGold;
	map<wstring, int>* items;

	vector<int> slotNum; 
	bool rolling;
	ULONGLONG startTime;
	ULONGLONG rollingTime; 
	ULONGLONG lastChangeTime;
	ULONGLONG changeInterval;

	ULONGLONG resultShowInterval; 
	bool success;
	bool superSuccess;
	wstring getItem;

};

void CHGAsciiInit(AsciiObjs& objs);
void CHGAsciiUpdate(AsciiObjs& objs);
void CHGAsciiRender(const AsciiObjs& objs);
void CHGRenderSlotArt(const AsciiObjs& objs, int slotIndex, int artIndex);
