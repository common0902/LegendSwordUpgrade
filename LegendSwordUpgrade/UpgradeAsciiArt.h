#pragma once
#include<vector>
#include <string>
#include <algorithm>
#include "Console.h"
using std::vector;
using std::string;
constexpr int SWORD_START_Y = 3;
constexpr int SWORD_HEIGHT = 34;


struct PMSAsciiObjs
{
	vector<vector<string>> swords;
	vector<string> explosion;
};

string GetSwordName(int tier);
void PMSAsciiInit(PMSAsciiObjs& objs);
void PMSAsciiRender(const PMSAsciiObjs& objs, int tier);
void RenderTitle(int x, int y);
void PMSAsciiRenderSlide(const PMSAsciiObjs& objs, int tier, int offsetY);
void PMSAsciiRenderTwoSlide(const PMSAsciiObjs& objs, int oldTier, int newTier, int offsetY, bool isSuccess);
Color GetSwordColor(int tier);
void ClearSwordArea();
void PMSAsciiRenderExplosion(const PMSAsciiObjs& objs);
