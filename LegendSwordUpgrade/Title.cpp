#include "Title.h"
#include "Console.h"

Scene GetScene(int curMenu);

void TitleScene::Enter()
{
	system("cls");
	state.LrwData.curMenu = 1;
}

void TitleScene::Update()
{
	if (GetKeyDown(VK_UP)) state.LrwData.curMenu -= 1;
	if (GetKeyDown(VK_DOWN)) state.LrwData.curMenu += 1;

	if (state.LrwData.curMenu == 0) state.LrwData.curMenu = 3;
	if (state.LrwData.curMenu == 4) state.LrwData.curMenu = 1;


	if (GetKeyDown(VK_RETURN))
	{
		state.fsm.ChangeState((int)GetScene(state.LrwData.curMenu));
	}
}

void TitleScene::Render() const
{
	GotoXY(0, 0);
	cout << "테스용 Title";
	const string lables[] = { "SHOP", "UPGRADE", "BATTLE" };
	for (int i = 0;i < 3;++i)
	{
		GotoXY(5, 5 + i);
		cout << (i + 1 == state.LrwData.curMenu ? "> " : "  ") << lables[i];
	}
}

void TitleScene::Exit()
{
	system("cls");
}


Scene GetScene(int curMenu)
{
	Scene scene = Scene::NONE;
	if (curMenu == 1)
	{
		scene = Scene::SHOP;
	}
	else if (curMenu == 2)
	{
		scene = Scene::UPGRADE;
	}
	else if (curMenu == 3)
	{
		scene = Scene::BATTLE;
	}

	return scene;
}




