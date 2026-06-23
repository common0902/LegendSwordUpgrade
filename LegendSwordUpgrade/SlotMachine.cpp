#include "SlotMachine.h"
#include "Console.h"
#include "GameState.h"
#include <windows.h>
using std::wstring;

void SlotMachine::Init(GameState& gameState)
{
	slotMachineArt = 
	{
	L"   ╔════════════════════════════════════╗   ",
	L"   ║         ***LUCKY SLOTS***          ║   ",
	L"   ║      ~~~Space를 눌러서 회전~~~     ║   ",
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
	L"║                                          ║",
	L"║                                          ║",
	L"║                                          ║",
	L"╚══════════════════════════════════════════╝"
	};
	infoUIArt = 
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

	slotArt.push_back(
		{
		L"╔═════╗",
		L"╚══╗  ║",
		L"  ╔╝ ╔╝",
		L" ╔╝ ╔╝ ",
		L" ╚══╝  "
		});
	slotArt.push_back(
		{
		L"╔════╗  ",
		L"╚═╗  ║  ",
		L"  ║  ║  ",
		L"  ║  ║  ",
		L"╔═╝  ╚═╗",
		L"╚══════╝"
		});
	slotArt.push_back(
		{
		L"   |   ",
		L"  $$$  ",
		L" $ $   ",
		L"  $$$  ",
		L"   $ $ ",
		L"  $$$  ",
		L"   |   ",
		});
	slotArt.push_back(
		{
		L",d88b.d88b,",
		L"88888888888",
		L"`Y8888888Y'",
		L"  `Y888Y'  ",
		L"    `Y'    "
		});
	/*slotArt.push_back(
		{
		L"   _   ",
		L"  (_)  ",
		L" (_)(_)",
		L"  _|_  "
		});*/

	state = &gameState;

	slotNum = { 0, 1, 2 };
	rolling = false;
	startTime = 0;
	rollingTime = 1500;
	lastChangeTime = 0;
	changeInterval = 100;
	resultShowInterval = 400;
	success = false;
	superSuccess = false;
	resultShow = false;

	InitRender();
}

void SlotMachine::InitRender()
{
	_setmode(_fileno(stdout), _O_U16TEXT);

	int slotMachineLines = (int)slotMachineArt.size();
	SetColor(Color::LIGHT_YELLOW);
	for (int i = 0; i < slotMachineLines; ++i)
	{
		GotoXY(0, i + 10);
		wcout << slotMachineArt[i];
	}
	SetColor();

	int infoLines = (int)infoUIArt.size();
	SetColor();
	for (int i = 0; i < infoLines; ++i)
	{
		GotoXY(50, 10 + i);
		wcout << infoUIArt[i];
	}

	_setmode(_fileno(stdout), _O_TEXT);
}

void SlotMachine::Update()
{
	if (resultShow)
	{
		ULONGLONG now = GetTickCount64();
		if (now - resultShowStartTime >= resultShowInterval)
		{
			if (resultShowIndex < (int)slotNum.size())
			{
				ShakeConsoleWindow(8, 100, 15);

				resultShowIndex++;
				resultShowStartTime = now;
			}
			else
			{
				resultShow = false;
			}
		}
		return;
	}

	if (!rolling) return;

	ULONGLONG now = GetTickCount64();

	if (now - startTime >= rollingTime)
	{
		int artCount = (int)slotArt.size();

		if (superSuccess || success)
		{
			int value = rand() % artCount;

			slotNum[0] = value;
			slotNum[1] = value;
			slotNum[2] = value;

			switch (value)
			{
			case 0:
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
				break;
			/*case 4:
				getItem = L"♧";
				break;*/
			}

		}
		else
		{
			int pattern = rand() % 2;

			if (pattern == 0)
			{
				slotNum[0] = rand() % artCount;

				do
				{
					slotNum[1] = rand() % artCount;
				} while (slotNum[1] == slotNum[0]);

				do
				{
					slotNum[2] = rand() % artCount;
				} while (slotNum[2] == slotNum[0] ||
					slotNum[2] == slotNum[1]);
			}
			else
			{
				int same = rand() % artCount;
				int diff;

				do
				{
					diff = rand() % artCount;
				} while (diff == same);

				slotNum[0] = same;
				slotNum[1] = same;
				slotNum[2] = diff;

				std::random_shuffle(slotNum.begin(), slotNum.end());
			}
		}

		resultShow = true;
		resultShowIndex = 0;
		resultShowStartTime = GetTickCount64();
		rolling = false;
		return;
	}

	if (now - lastChangeTime >= changeInterval)
	{
		int artCount = (int)slotArt.size();
		for (int i = 0; i < (int)slotNum.size(); ++i)
		{
			slotNum[i] = rand() % artCount;
		}
		lastChangeTime = now;
	}
}

void SlotMachine::Render() const
{
	_setmode(_fileno(stdout), _O_U16TEXT);

	RenderInfoUI(50, 10);

	if (resultShow)
	{
		for (int i = 0; i < (int)slotNum.size(); ++i)
		{
			if (i < resultShowIndex)
			{
				if (superSuccess)
					SetColor(Color::YELLOW);
				else if (success)
					SetColor(Color::LIGHT_GREEN);
				else
					SetColor(Color::LIGHT_RED);

				RenderSlotArt(i, slotNum[i]);
				SetColor();
			}
			else if (resultShow)
			{
				RenderNullSlotArt(i);
			}
		}
	}
	else if (rolling)
	{
		for (int i = 0; i < (int)slotNum.size(); ++i)
			RenderSlotArt(i, slotNum[i]);
	}

	_setmode(_fileno(stdout), _O_TEXT);
}

bool SlotMachine::CanRoll() const
{
	return !rolling && !resultShow;
}

void SlotMachine::StartRoll(bool s, bool super)
{
	ShakeConsoleWindow(4, 100, 30);

	startTime = GetTickCount64();
	rolling = true;
	
	success = s;
	superSuccess = super;
}

RollResult SlotMachine::ConsumeResult()
{
	RollResult r;
	r.item = getItem;
	r.superSuccess = superSuccess;
	getItem.clear();
	return r;
}

void SlotMachine::RenderSlotArt(int slotIndex, int artIndex) const
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


	const vector<wstring>& art = slotArt[artIndex];
	int artLines = (int)art.size();


	int offsetY = (8 - artLines) / 2;
	int offsetX = (12 - art[0].size()) / 2;

	for (int i = 0; i < artLines; ++i)
	{
		GotoXY(slotX[slotIndex] + offsetX, slotY + offsetY + i);
		wcout << art[i];
	}
}

void SlotMachine::RenderNullSlotArt(int slotIndex) const
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

void SlotMachine::RenderInfoUI(int renderX, int renderY) const
{
	GotoXY(renderX + 2, renderY + 1);
	wcout << L"보유 골드: " << std::setw(4) << state->gold;
	GotoXY(renderX + 2, renderY + 3);
	wcout << L"보유 토템: ";

	int idx = 0;
	const int perRow = 4;   
	const int cellW = 6;    
	for (auto item = state->ChgData.haveTotem.begin(); item != state->ChgData.haveTotem.end(); ++item)
	{
		int row = idx / perRow;
		int col = idx % perRow;
		GotoXY(renderX + 2 + col * cellW, renderY + 4 + row);  
		wcout << item->first << L" X " << item->second.first << "|";
		idx++;
	}

	int yOffset = 0;
	for (auto item = state->ChgData.haveTotem.begin(); item != state->ChgData.haveTotem.end(); ++item)
	{
		GotoXY(renderX + 2, renderY + 7 + yOffset);
		wcout << item->first << L": ";
		wcout << item->second.second;
		yOffset++;
	}

	GotoXY(renderX + 2, renderY + 7 + yOffset + 2);
	wcout << L"공격속도: " << state->player.attackSpeed;
	GotoXY(renderX + 2, renderY + 7 + yOffset + 3);
	wcout << L"체력: " << state->player.MaxHp;
	/*GotoXY(renderX + 2, renderY + 7 + yOffset + 4);
	wcout << L"무기 강화 성공 확률: " << state->curSword.GetSuccessChance();*/

	GotoXY(13, 28);
	wcout << L"실패 확률: " << state->ChgData.failPercent << L"%";
	GotoXY(13, 29);			  
	wcout << L"성공 확률: " << state->ChgData.successPercent << L"%";
	GotoXY(13, 30);			  
	wcout << L"젝팟 확률: " << state->ChgData.superSuccessPercent << L"%";

}
