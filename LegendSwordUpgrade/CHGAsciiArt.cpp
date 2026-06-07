#include "CHGAsciiArt.h"
#include "Console.h"	
#include "GameState.h"

void AsciiInit(AsciiObjs& objs)
{
	objs.slotMachine =
	{
	"   ╔════════════════════════════════════╗   ",
    "   ║     *** LUCKY SLOTS*** [100 CR]    ║   ",
    "   ║ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ║   ",
    "   ╠═══════════╦════════════╦═══════════╣   ",
    "   ║           ║            ║           ║   ",
    "   ║           ║            ║           ║   ",
    "   ║           ║            ║           ║   ",
    "   ║           ║            ║           ║   ",
    "   ║           ║            ║           ║   ",
    "   ║           ║            ║           ║   ",
    "   ║           ║            ║           ║   ",
    "   ║           ║            ║           ║   ",
    "   ╠═══════════╩════════════╩═══════════╣   ",
    "   ║  GOLD  :                           ║   ",
    "   ║  Totem :                           ║   ",
    "  ╔╩════════════════════════════════════╩╗  ",
    " ╔╝                                      ╚╗ ",
    " ║               || SPIN ||               ║ ",
    "╔╝                                        ╚╗",
    "╠══════════════════════════════════════════╣",
    "║                                          ║",
    "║                                          ║",
    "║            1 - 1 - 1 => WIN     x 5      ║",
    "║            $ - $ - $ => BONUS   x 10     ║",
    "║            7 - 7 - 7 => JACKPOT x 50     ║",
    "╚══════════════════════════════════════════╝"
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

void AsciiUpdate(AsciiObjs& objs)
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

void AsciiRender(const AsciiObjs& objs)
{
    int slotMachineLines = (int)objs.slotMachine.size();
    SetColor(Color::LIGHT_YELLOW);
    for (int i = 0; i < slotMachineLines; ++i)
    {
        GotoXY(0, i + 10);
        cout << objs.slotMachine[i];
    }

    for (int i = 0; i < (int)objs.slotNum.size(); ++i)
    {
        RenderSlotArt(objs, i, objs.slotNum[i]);
    }
}

void RenderSlotArt(const AsciiObjs& objs, int slotIndex, int artIndex)
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
}

