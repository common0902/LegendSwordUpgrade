#include "CHGAsciiArt.h"
#include "Console.h"	
#include "GameState.h"
#include <windows.h>
using std::wstring;

void CHGAsciiInit(AsciiObjs& objs)
{
	objs.slotMachineArt =
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
    L"  ╔╩════════════════════════════════════╩╗  ",
    L" ╔╝                                      ╚╗ ",
    L" ║               || SPIN ||               ║ ",
    L"╔╝                                        ╚╗",
    L"╠══════════════════════════════════════════╣",
    L"║               WIN     = 75%              ║",
    L"║               BONUS   = 20%              ║",
    L"║               JACKPOT = 5%               ║",
    L"╚══════════════════════════════════════════╝"
	};
    objs.infoUIArt =
    {
     L"⡤⠤⠤⠤⠤⠤⠤⠤⠤⠤⠤⠤⠤⠤⠤⠤⠤⠤⠤⠤⠤⠤⠤⠤⠤⠤⠤⠤⠤⠤⢤",
     L"⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸",
     L"⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸",
     L"⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸",
     L"⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸",
     L"⣇⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣸",
     L"⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸",
     L"⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸",
     L"⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸",
     L"⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸",
     L"⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸",
     L"⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸",
     L"⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸",
     L"⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸",
     L"⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸",
     L"⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸",
     L"⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸",
     L"⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸",
     L"⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸",
     L"⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸",
     L"⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸",
     L"⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸",
     L"⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸",
     L"⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸",
     L"⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉"
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
    objs.slotArt.push_back(
    {
    L",d88b.d88b,",
    L"88888888888",
    L"`Y8888888Y'",
    L"  `Y888Y'  ",
    L"    `Y'    "
    });

    objs.slotNum = { 0, 1, 2 }; 
    objs.rolling = false;
    objs.startTime = 0;
    objs.rollingTime = 2000;
    objs.lastChangeTime = 0;
    objs.changeInterval = 100;
    objs.resultShowInterval = 400;
    objs.success = false;
    objs.superSuccess = false;
    objs.resultShow = false;

    CHGAsciiInitRender(objs);
}

void CHGAsciiInitRender(AsciiObjs& objs)
{
    _setmode(_fileno(stdout), _O_U16TEXT);

    int slotMachineLines = (int)objs.slotMachineArt.size();
    SetColor(Color::LIGHT_YELLOW);
    for (int i = 0; i < slotMachineLines; ++i)
    {
        GotoXY(0, i + 10);
        wcout << objs.slotMachineArt[i];
    }
    SetColor();

    int infoLines = (int)objs.infoUIArt.size();
    SetColor();
    for (int i = 0; i < infoLines; ++i)
    {
        GotoXY(50, 10 + i);
        wcout << objs.infoUIArt[i];
    }

    _setmode(_fileno(stdout), _O_TEXT);

}

void CHGAsciiUpdate(AsciiObjs& objs)
{

    if (objs.resultShow)
    {
        ULONGLONG now = GetTickCount64();
        if (now - objs.resultShowStartTime >= objs.resultShowInterval)
        {
            if (objs.resultShowIndex < (int)objs.slotNum.size())
            {
                ShakeConsoleWindow(8, 100, 15);

                objs.resultShowIndex++;
                objs.resultShowStartTime = now;
            }
            else
            {
                objs.resultShow = false;
            }
        }
        return;
    }

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
            case 3:
                getItem = L"♥";
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

        objs.resultShow = true;
        objs.resultShowIndex = 0;
        objs.resultShowStartTime = GetTickCount64();
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
    _setmode(_fileno(stdout), _O_U16TEXT);

    CHGRenderInfoUI(objs, 50, 10);

    if (objs.resultShow)
    {
        for (int i = 0; i < (int)objs.slotNum.size(); ++i)
        {
            if (i < objs.resultShowIndex)
            {
                if (objs.superSuccess)
                    SetColor(Color::YELLOW);
                else if (objs.success)
                    SetColor(Color::LIGHT_GREEN);
                else
                    SetColor(Color::LIGHT_RED);

                CHGRenderSlotArt(objs, i, objs.slotNum[i]);
                SetColor();
            }
            else if (objs.resultShow) 
            {
                CHGRenderNullSlotArt(objs, i);
            }
        }
    }
    else if (objs.rolling)
    {
        for (int i = 0; i < (int)objs.slotNum.size(); ++i)
            CHGRenderSlotArt(objs, i, objs.slotNum[i]);
    }

    _setmode(_fileno(stdout), _O_TEXT);
}

void CHGRenderSlotArt(const AsciiObjs& objs, int slotIndex, int artIndex)
{
    int slotX[] = { 4, 16, 29 };
    int slotY = 14; 
    int slotW = 11; 
    int slotH = 8;  

    
    for (int i = 0; i < slotH; ++i)
    {
        GotoXY(slotX[slotIndex], slotY + i);
        wcout << wstring(slotW, L' ');
    }


    const vector<wstring>& art = objs.slotArt[artIndex];
    int artLines = (int)art.size();
    

    int offsetY = (8 - artLines) / 2;
    int offsetX = (12 - art[0].size()) / 2;
    
    for (int i = 0; i < artLines; ++i)
    {
        GotoXY(slotX[slotIndex] + offsetX, slotY + offsetY + i);
        wcout << art[i];
    }
}

void CHGRenderNullSlotArt(const AsciiObjs& objs, int slotIndex)
{
    int slotX[] = { 4, 16, 29 };
    int slotY = 14;
    int slotW = 11;
    int slotH = 8;

    for (int i = 0; i < slotH; ++i)
    {
        GotoXY(slotX[slotIndex], slotY + i);
        wcout << wstring(slotW, L' ');
    }
}

void CHGRenderInfoUI(const AsciiObjs& objs, int renderX, int renderY)
{

    GotoXY(renderX + 2, renderY + 1);
    wcout << L"보유 골드: " << std::setw(4) << objs.currentGold;
    GotoXY(renderX + 2, renderY + 3);
    wcout << L"보유 토템: ";
    GotoXY(renderX + 2, renderY + 4);
    for (auto item = objs.items->begin(); item != objs.items->end(); ++item)
    {
        wcout << item->first + L" X ";
        wcout << item->second.first << L"|";
    }

    int yOffset = 0;
    for (auto item = objs.items->begin(); item != objs.items->end(); ++item)
    {
        GotoXY(renderX + 2, renderY + 7 + yOffset);
        wcout << item->first <<L": ";
        wcout << item->second.second;
        yOffset++;
    }


}

