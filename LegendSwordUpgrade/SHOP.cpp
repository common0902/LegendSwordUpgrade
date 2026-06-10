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
    if (GetKeyDown(VK_SPACE) && !objs.rolling)
    {
        objs.startTime = GetTickCount64();
        objs.rolling = true;

		int p = rand() % 100 + 1;
		if (p < state.ChgData.failPercent)
		{
			objs.success = false;
			objs.superSuccess = false;
		}
		else if (p < state.ChgData.successPercent)
		{
			objs.success = true;
			objs.superSuccess = false;
		}
		else
		{
			objs.success = false;
			objs.superSuccess = true;
		}
    }

	if (!objs.getItem.empty())
	{
		wstring itemS;

		if (objs.success)
			state.ChgData.haveTotem[objs.getItem] += 1;
		else if (objs.superSuccess)
			state.ChgData.haveTotem[objs.getItem] += 5;

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
