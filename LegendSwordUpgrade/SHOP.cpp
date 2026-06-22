#include "Console.h"
#include "SHOP.h"
#include "CHGAsciiArt.h"
static AsciiObjs objs;

void StatUp(GameState state, int count);
void ShopScene::Enter()
{
	//state.ChgData
	cout << "Shop";
	objs.currentGold = state.gold;
	objs.items = &state.ChgData.haveTotem;
	srand((unsigned int)time(nullptr));
	SetConsoleGameTitle(L"SHOP");
	//SetConsoleSize(85, 40);
	CHGAsciiInit(objs);
}

void ShopScene::Update()
{

	if (GetKeyDown(VK_ESCAPE))
	{
		
		state.fsm.ChangeState((int)Scene::TITLE);
		return;
	}	

	
    if (GetKeyDown(VK_SPACE) && !objs.rolling && !objs.resultShow)
    {
		if (objs.currentGold >= 10)
			objs.currentGold -= 10;
		else return;

		ShakeConsoleWindow(8, 200, 30);

        objs.startTime = GetTickCount64();
        objs.rolling = true;

		int p = rand() % 100 + 1;
		if (p < state.ChgData.failPercent)
		{
			objs.success = false;
			objs.superSuccess = false;
		}
		else if (p < state.ChgData.successPercent + state.ChgData.failPercent)
		{
			objs.success = true;
			objs.superSuccess = false;
		}
		else
		{
			objs.success = false;
			objs.superSuccess = true;
		}
		GotoXY(0, 40);
	    	wcout << std::setw(3) << p;
    }

	if (!objs.getItem.empty())
	{

		

		if (objs.success)
		{
			state.ChgData.haveTotem[objs.getItem].first += 1;
		}
		else if (objs.superSuccess)
		{
			state.ChgData.haveTotem[objs.getItem].first += 5;
		}

		

		objs.getItem.clear();
	}

	CHGAsciiUpdate(objs);
	//state.ChgData.haveTotem[]
}

void ShopScene::Render() const
{
	CHGAsciiRender(objs);
	
}

void ShopScene::Exit()
{
	state.gold = objs.currentGold;
	state.player.MaxHp = state.ChgData.haveTotem[L"♥"].first * 2;
	state.player.attackSpeed = state.ChgData.haveTotem[L"1"].first * 2;
}


void StatUp(GameState state, int count)
{
	/*if (objs.getItem == L"1")
		state.player.str += count * 3;
	else if (objs.getItem == L"$")
		state.player.str += count * 15;
	else if (objs.getItem == L"♥")
		state.player.MaxHp += count * 3;
	else if (objs.getItem == L"7")
	{
		state.player.str += count * 1;
		state.player.str += count * 1;
		objs.currentGold += count * 1;
	}*/
}
