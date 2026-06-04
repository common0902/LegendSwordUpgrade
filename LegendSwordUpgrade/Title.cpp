#include "Title.h"
#include "Console.h"

Scene GetScene(int curMenu);

void InitTitle(GameState& state)
{
	state.LrwData.curMenu = 1;

}

void UpdateTitle(GameState& state)
{
	
	if (GetKeyDown(VK_UP)) state.LrwData.curMenu -= 1;
	if (GetKeyDown(VK_DOWN))state.LrwData.curMenu += 1;

	if (state.LrwData.curMenu == 0) state.LrwData.curMenu += 3;
	if (state.LrwData.curMenu == 4) state.LrwData.curMenu -= 3;
	

	if (GetKeyDown(VK_RETURN))
	{
		state.curScene = GetScene(state.LrwData.curMenu);
	}
}

Scene GetScene(int curMenu)
{
	Scene scene = Scene::NONE;
	if (curMenu == 1)
	{
		scene = Scene::UPGRADE;
	}
	else if (curMenu == 2)
	{
		scene = Scene::SHOP;
	}
	else if (curMenu == 2)
	{
		scene = Scene::BATTLE;
	}
	return scene;
}

void RenderTitle(const GameState& state)
{
	GotoXY(0,0);
	cout << "ев╫╨©К";

	for (int i = 0;i < 3;++i)
	{
		GotoXY(5, 5 + i);
		
	}


}
