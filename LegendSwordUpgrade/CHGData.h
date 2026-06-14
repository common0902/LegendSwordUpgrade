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

    std::map<wstring, pair<int, wstring>> haveTotem =
    {
        {L"1", {0, L"°ø°Ý·Â Áõ°¡"}},
        {L"$", {0, L"°ñµå È¹µæ"}},
        {L"7", {0, L"·ê·¿ ´çÃ· È®·ü Áõ°¡"}}
    };


	bool slotPlaying = false;

};