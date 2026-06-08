#include "CHGAsciiArt.h"
#include "Console.h"	
#include "GameState.h"
#include <windows.h>

void CHGAsciiInit(AsciiObjs& objs)
{
	objs.slotMachine =
	{
	L"   ╔════════════════════════════════════╗   ",
    L"   ║     *** LUCKY SLOTS*** [100 CR]    ║   ",
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
    L"║            1 - 1 - 1 => WIN     x 5      ║",
    L"║            $ - $ - $ => BONUS   x 10     ║",
    L"║            7 - 7 - 7 => JACKPOT x 50     ║",
    L"╚══════════════════════════════════════════╝"
	};
	objs.slotArt.push_back(
	{	
    "  _____  ",
    " |___  | ",
    "    / /  ",
    "   / /   ",
    "  /_/    "
	});
    objs.slotArt.push_back(
    {
    "   |   ",
    "  $$$  ",
    " $ $   ",
    "  $$$  ",
    "   $ $ ",
    "  $$$  ",
    "   |   ",
    });
    objs.slotArt.push_back(
    {
    "   ____   ",
    "  |__  |  ",
    "    |  |  ",
    "    |  |  ",
    "   |____| "
    });

    objs.slotNum = { 0, 1, 2 }; 
    objs.rolling = false;
    objs.startTime = 0;
    objs.rollingTime = 2000;
    objs.lastChangeTime = 0;
    objs.changeInterval = 100;
}

void CHGAsciiUpdate(AsciiObjs& objs)
{
    if (!objs.rolling) return;

    ULONGLONG now = GetTickCount64();
    ULONGLONG elapsed = now - objs.startTime;

    if (elapsed >= objs.rollingTime)
    {
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
    _setmode(_fileno(stdout), _O_TEXT);
    SetColor();

    for (int i = 0; i < (int)objs.slotNum.size(); ++i)
    {
        CHGRenderSlotArt(objs, i, objs.slotNum[i]);
    }
}

void CHGRenderSlotArt(const AsciiObjs& objs, int slotIndex, int artIndex)
{
    int slotX[] = { 4, 16, 29 };
    int slotY = 14; 

    const vector<string>& art = objs.slotArt[artIndex];
    int artLines = (int)art.size();

    int offsetY = (8 - artLines) / 2;

    SetColor(Color::WHITE);
    for (int i = 0; i < artLines; ++i)
    {
        GotoXY(slotX[slotIndex], slotY + offsetY + i);
        cout << art[i];
    }
    SetColor();
}

