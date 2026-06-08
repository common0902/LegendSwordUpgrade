#include "Console.h"
#include "SHOP.h"
#include "CHGAsciiArt.h"
static AsciiObjs objs;

void ShopScene::Enter()
{
	cout << "Shop";
	CHGAsciiInit(objs);
}

void ShopScene::Update()
{
    if (GetKeyDown(VK_SPACE) && !objs.rolling)
    {
        objs.startTime = GetTickCount64();
        objs.rolling = true;
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
