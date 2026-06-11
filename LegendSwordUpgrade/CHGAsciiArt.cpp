#include "CHGAsciiArt.h"
#include "Console.h"	
#include "GameState.h"
#include <windows.h>
using std::wstring;

void CHGAsciiInit(AsciiObjs& objs)
{
	objs.slotMachine =
	{
	L"   ╔════════════════════════════════════╗   ",
    L"   ║         ***LUCKY SLOTS***          ║   ",
    L"   ║ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ║   ",
    L"   ╠═══════════╦════════════╦═══════════╣   ",
    L"   ║           ║            ║           ║   ",
    L"   ║           ║            ║           ║   ",
    L"   ║           ║            ║           ║   ",
    L"   ║           ║            ║           ║   ",
    L"   ║           ║            ║           ║   ",
    L"   ║           ║            ║           ║   ",
    L"   ║           ║            ║           ║   ",
    L"   ║           ║            ║           ║   ",
    L"   ╠═══════════╩════════════╩═══════════╣   ",
    L"   ║  GOLD  :                           ║   ",
    L"   ║  Totem :                           ║   ",
    L"  ╔╩════════════════════════════════════╩╗  ",
    L" ╔╝                                      ╚╗ ",
    L" ║               || SPIN ||               ║ ",
    L"╔╝                                        ╚╗",
    L"╠══════════════════════════════════════════╣",
    L"║                                          ║",
    L"║                                          ║",
    L"║         1 - 1 - 1 => WIN     x 5         ║",
    L"║         $ - $ - $ => BONUS   x 10        ║",
    L"║         7 - 7 - 7 => JACKPOT x 50        ║",
    L"╚══════════════════════════════════════════╝"
	};
	objs.slotArt.push_back(
	{	
    L"╔═════╗",
    L"╚══╗  ║",
    L"  ╔╝ ╔╝",
    L" ╔╝ ╔╝ ",
    L" ╚══╝  "
	});
    objs.slotArt.push_back(
    {
    L"╔════╗  ",
    L"╚═╗  ║  ",
    L"  ║  ║  ",
    L"  ║  ║  ",
    L"╔═╝  ╚═╗",
    L"╚══════╝"
    });
    objs.slotArt.push_back(
    {
    L"   |   ",
    L"  $$$  ",
    L" $ $   ",
    L"  $$$  ",
    L"   $ $ ",
    L"  $$$  ",
    L"   |   ",
    });

    objs.slotNum = { 0, 1, 2 }; 
    objs.rolling = false;
    objs.startTime = 0;
    objs.rollingTime = 2000;
    objs.lastChangeTime = 0;
    objs.changeInterval = 100;
    objs.resultShowInterval = 700;
    objs.success = false;
    objs.superSuccess = false;
}

void CHGAsciiUpdate(AsciiObjs& objs)
{
    if (!objs.rolling) return;

    ULONGLONG now = GetTickCount64();

    if (now - objs.startTime >= objs.rollingTime)
    {
        int artCount = (int)objs.slotArt.size();

        if (objs.superSuccess || objs.success)
        {
            int value = rand() % artCount;

            objs.slotNum[0] = value;
            objs.slotNum[1] = value;
            objs.slotNum[2] = value;

            wstring getItem;
            switch (value)
            {
            case 0 :
                getItem = L"7";
                break;
            case 1: 
                getItem = L"1";
                break;
            case 2: 
                getItem = L"$";
                break;
            }

            objs.getItem = getItem;
        }
        else
        {
            int pattern = rand() % 2;

            if (pattern == 0)
            {
                objs.slotNum[0] = rand() % artCount;

                do
                {
                    objs.slotNum[1] = rand() % artCount;
                } while (objs.slotNum[1] == objs.slotNum[0]);

                do
                {
                    objs.slotNum[2] = rand() % artCount;
                } while (objs.slotNum[2] == objs.slotNum[0] ||
                    objs.slotNum[2] == objs.slotNum[1]);
            }
            else
            {
                int same = rand() % artCount;
                int diff;

                do
                {
                    diff = rand() % artCount;
                } while (diff == same);

                objs.slotNum[0] = same;
                objs.slotNum[1] = same;
                objs.slotNum[2] = diff;

                std::random_shuffle(objs.slotNum.begin(), objs.slotNum.end());
            }
        }

        objs.rolling = false;
        return;
    }

    if (now - objs.lastChangeTime >= objs.changeInterval)
    {
        int artCount = (int)objs.slotArt.size();
        for (int i = 0; i < (int)objs.slotNum.size(); ++i)
        {
            objs.slotNum[i] = rand() % artCount;
        }
        objs.lastChangeTime = now;
    }
}

void CHGAsciiRender(const AsciiObjs& objs)
{
    int slotMachineLines = (int)objs.slotMachine.size();
    SetColor(Color::LIGHT_YELLOW);
    _setmode(_fileno(stdout), _O_U16TEXT);
    for (int i = 0; i < slotMachineLines; ++i)
    {
        GotoXY(0, i + 10);
        wcout << objs.slotMachine[i];
    }
    SetColor();

    GotoXY(14, 23);
    wcout << objs.currentGold;
    GotoXY(14, 24);
    for (auto item = objs.items->begin(); item != objs.items->end(); ++item)
    {
        wcout << item->first + L"X";
        wcout << item->second << L"/";
    }
    //cout << "\r"


    for (int i = 0; i < (int)objs.slotNum.size(); ++i)
    {
        CHGRenderSlotArt(objs, i, objs.slotNum[i]);
    }

    _setmode(_fileno(stdout), _O_TEXT);
}

void CHGRenderSlotArt(const AsciiObjs& objs, int slotIndex, int artIndex)
{
    int slotX[] = { 4, 16, 29 };
    int slotY = 14; 

    const vector<wstring>& art = objs.slotArt[artIndex];
    int artLines = (int)art.size();
    

    int offsetY = (8 - artLines) / 2;
    int offsetX = (12 - art[0].size()) / 2;

    if (objs.superSuccess)
        SetColor(Color::YELLOW);
    else
        SetColor(Color::WHITE);
    for (int i = 0; i < artLines; ++i)
    {
        GotoXY(slotX[slotIndex] + offsetX, slotY + offsetY + i);
        wcout << art[i];
    }
    SetColor();
}

