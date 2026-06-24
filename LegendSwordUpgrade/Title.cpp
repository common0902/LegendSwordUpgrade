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
	GotoXY(WIDTH / 2 - 50, 5);
		cout << "_______  _     _  _______  ______    ______     __   __  _______  _______  _______  _______  ______    "   ;   
	GotoXY(WIDTH / 2 - 50, 6);
		cout << "|       || | _ | ||       ||    _ |  |      |   |  |_|  ||   _   ||       ||       ||       ||    _ |  ";
	GotoXY(WIDTH / 2 - 50, 7);
		cout << "|  _____|| || || ||   _   ||   | ||  |  _    |  |       ||  |_|  ||  _____||_     _||    ___||   | ||  ";
	GotoXY(WIDTH / 2 - 50, 8);
		cout << "| |_____ |       ||  | |  ||   |_||_ | | |   |  |       ||       || |_____   |   |  |   |___ |   |_||_ ";
	GotoXY(WIDTH / 2 - 50, 9);
		cout << "|_____  ||       ||  |_|  ||    __  || |_|   |  |       ||       ||_____  |  |   |  |    ___||    __  |";
	GotoXY(WIDTH / 2 - 50, 10);
		cout << " _____| ||   _   ||       ||   |  | ||       |  | ||_|| ||   _   | _____| |  |   |  |   |___ |   |  | |";
	GotoXY(WIDTH / 2 - 50, 11);
		cout << "|_______||__| |__||_______||___|  |_||______|   |_|   |_||__| |__||_______|  |___|  |_______||___|  |_|";
	GotoXY(WIDTH / 2 - 50, 12);

	const string lables[] = { "SHOP", "UPGRADE", "BATTLE" };
	for (int i = 0;i < 3;++i)
	{
		GotoXY(WIDTH / 2 - 5, 30 + i);
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




