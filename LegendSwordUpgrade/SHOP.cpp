#include "Console.h"
#include "SHOP.h"
#include "CHGAsciiArt.h"
static AsciiObjs objs;

void ShopScene::Enter()
{
	cout << "Shop";
}

void ShopScene::Update()
{
	AsciiInit(objs);
	//state.ChgData.haveTotem[]
}

void ShopScene::Render() const
{
	
}

void ShopScene::Exit()
{
	AsciiRender(objs);


}
