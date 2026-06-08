#pragma once
#include <windows.h>
#include <vector>
#include <string>
#include <algorithm>
using std::vector;
using std::string;
using std::wstring;  

struct AsciiObjs
{
	vector<wstring> slotMachine;
	vector<vector<string>> slotArt;
	
	vector<int> slotNum; 
	bool rolling;
	ULONGLONG startTime;
	ULONGLONG rollingTime; 
	ULONGLONG lastChangeTime;
	ULONGLONG changeInterval;
};

void CHGAsciiInit(AsciiObjs& objs);
void CHGAsciiUpdate(AsciiObjs& objs);
void CHGAsciiRender(const AsciiObjs& objs);
void CHGRenderSlotArt(const AsciiObjs& objs, int slotIndex, int artIndex);
