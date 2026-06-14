#include "Console.h"
#include "SHOP.h"
#include "CHGAsciiArt.h"
static AsciiObjs objs;

void ShopScene::Enter()
{
	//state.ChgData
	cout << "Shop";
	objs.currentGold = state.gold;
	objs.items = &state.ChgData.haveTotem;
	srand((unsigned int)time(nullptr));

	CHGAsciiInit(objs);
}

void ShopScene::Update()
{
	if (GetKeyDown(VK_ESCAPE))
	{
		state.fsm.ChangeState((int)Scene::TITLE);
		return;
	}

    if (GetKeyDown(VK_SPACE) && !objs.rolling)
    {
		ShakeConsoleWindow(100, 0.4f, 2);

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
	    	wcout << p;
    }

	if (!objs.getItem.empty())
	{
		wstring itemS;

		if (objs.success)
			state.ChgData.haveTotem[objs.getItem].first += 1;
		else if (objs.superSuccess)
			state.ChgData.haveTotem[objs.getItem].first += 5;

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

}
