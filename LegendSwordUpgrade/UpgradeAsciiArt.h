#pragma once
#include<vector>
#include <string>
#include <algorithm>
using std::vector;
using std::string;

struct PMSAsciiObjs
{
	vector<vector<string>> swords;
};

string GetSwordName(int tier);
void PMSAsciiInit(PMSAsciiObjs& objs);
void PMSAsciiRender(const PMSAsciiObjs& objs, int tier);
