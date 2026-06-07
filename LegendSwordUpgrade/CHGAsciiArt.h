#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include <Windows.h>
using std::vector;
using std::string;

struct AsciiObjs
{
	vector<string> slotMachine;
	vector<vector<string>> slotArt;
	
	vector<int> slotNum; 
	bool rolling;
	ULONGLONG startTime;
	ULONGLONG rollingTime; 
	ULONGLONG lastChangeTime;
	ULONGLONG changeInterval;
};

void AsciiInit(AsciiObjs& objs);
void AsciiUpdate(AsciiObjs& objs);
void AsciiRender(const AsciiObjs& objs);
void RenderSlotArt(const AsciiObjs& objs, int slotIndex, int artIndex);
