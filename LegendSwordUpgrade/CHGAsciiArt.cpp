#include "CHGAsciiArt.h"
#include "Console.h"	
#include "GameState.h"

void AsciiInit(AsciiObjs& objs)
{
	objs.slotMachine =
	{
		"   ╔════════════════════════════════════╗          ",
		"   ║                                    ║			",
		"   ║                                    ║			",
		"   ╠═══════════╦════════════╦═══════════╣			",
		"   ║           ║            ║           ║			",
		"   ║           ║            ║           ║			",
		"   ║           ║            ║           ║        	",
		"   ║           ║            ║           ║      XXX	",
		"   ║           ║            ║           ║      XXX	",
		"   ║           ║            ║           ║      XXX	",
		"   ║           ║            ║           ║      XXX	",
		"   ║           ║            ║           ║XXXXXXXXX	",
		"   ╠═══════════╩════════════╩═══════════╣XXXXXXXXX	",
		"   ║                                    ║			",
		"   ║                                    ║			",
		"  ╔╩════════════════════════════════════╩╗			",
		"  ║			   -------                ║			",
		" ╔╝              //     \\               ╚╗        ",
		" ║              ||       ||               ║		",
		"╔╝               \\     //                ╚╗       ",
		"║                 -------                  ║		",
		"╠══════════════════════════════════════════╣		",
		"║                                          ║		",
		"║                                          ║		",
		"║                                          ║		",
		"║                                          ║		"
	};
	objs.slotArt =
	{	
		"            ",
		"     ╔║     ",
		"    ╔╩║     ",
		"    ║ ║     ",
		"      ║     ",
		"    ══╩═    ",
		"            ",
		"            "
	};
}

void             AsciiUpdate(AsciiObjs& objs)
{

}

void AsciiRender(const AsciiObjs& objs)
{
	int slotMachineLines = (int)objs.slotMachine.size();

	SetColor(Color::LIGHT_YELLOW);
	for (int i = 0; i < slotMachineLines; ++i)
	{
		GotoXY(0, i+10);
		cout << objs.slotMachine[i];
	}
}
