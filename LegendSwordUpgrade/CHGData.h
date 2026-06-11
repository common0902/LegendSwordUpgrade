#pragma once
#include <map>
#include <string>
using std::wstring;
struct CHGData
{
    int failPercent = 75;
    int successPercent = 20;
    int superSuccessPercent = 5;

    std::map<wstring, int> haveTotem =
    {
        {L"1", 0},
        {L"$", 0},
        {L"7", 0}
    };


	bool slotPlaying = false;

};