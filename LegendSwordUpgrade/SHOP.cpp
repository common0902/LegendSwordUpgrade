#include "Console.h"
#include "SHOP.h"
#include "CHGAsciiArt.h"
static AsciiObjs objs;

void InitShop(GameState& state)
{
	AsciiInit(objs);
	//state.ChgData.haveTotem[]
}

void UpdateShop(GameState& state)
{
	
}

void RenderShop(const GameState& state)
{
	AsciiRender(objs);


}
