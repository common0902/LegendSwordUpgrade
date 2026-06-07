#include "Console.h"
#include "SHOP.h"
#include "CHGAsciiArt.h"
static AsciiObjs objs;

void ShopScene::Enter()
{
	cout << "Shop";
	AsciiInit(objs);
}

void ShopScene::Update()
{
    if (GetKeyDown(VK_SPACE) && !objs.rolling)
    {
        objs.startTime = GetTickCount64();
        objs.rolling = true;
    }

	AsciiUpdate(objs);
	//state.ChgData.haveTotem[]
}

void ShopScene::Render() const
{
	AsciiRender(objs);
	
}

void ShopScene::Exit()
{

}
