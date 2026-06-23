#pragma once
#include <map>
#include <string>
using std::wstring;
using std::pair;
struct CHGData
{
    int failPercent = 75;
    int successPercent = 20;
    int superSuccessPercent = 5;

//public:
//    int weaponUpgradeSuccessPercent = 0;

    std::map<wstring, pair<int, wstring>> haveTotem =
    {
        {L"1", {0, L"공격속도 증가"}},
        {L"$", {0, L"골드 획득"}},
        {L"♥", {0, L"체력 증가"}},
        {L"7", {0, L"전체 증가"}}
        //{L"♧", {0, L"무기 강화 성공 확률 증가"}}
    };


	bool slotPlaying = false;

	void UpdateWeaponUpgradePercent()
	{
		weaponUpgradeSuccessPercent = haveTotem.at(L"♧").first;
	}*/

};
