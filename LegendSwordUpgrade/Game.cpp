#include "Game.h"
#include "console.h"
#include "Enums.h"
#include "SHOP.h"
#include "UPGRADE.h"
#include "BATTLE.h"
#include "Title.h"
#include "GameOver.h"

void Init(GameState& state)
{
	srand((unsigned int)time(nullptr));

	SetConsoleSize(WIDTH, HEIGHT);
	SetConsoleWindowStyle(true);

	state = GameState{};
}

void Update(GameState& state)
{
	bool sceneChanged =
		state.curScene != state.prevScene;
	state.prevScene = state.curScene;
	UpdateInput();

	switch (state.curScene)
	{
	case Scene::TITLE:
		if (sceneChanged)
			InitTitle(state);
		UpdateTitle(state);
		break;
	case Scene::SHOP:
		if (sceneChanged)
			InitShop(state);
		UpdateShop(state);
		break;
	case Scene::UPGRADE:
		if (sceneChanged)
			InitUpgrade(state);
		UpdateUpgrade(state);
		break;
	case Scene::BATTLE:
		if (sceneChanged)
			InitBattle(state);
		UpdateBattle(state);
		break;
	case Scene::GAMEOVER:
		if (sceneChanged)
			InitGameOver(state);
		UpdateGameOver(state);
		break;
	}
}

void Renderer(const GameState& state)
{
	SetColor();
	if (state.prevScene != state.curScene)
		system("cls");
	GotoXY(0, 0);

	switch (state.curScene)
	{
	case Scene::TITLE:
		RenderTitle(state);
		break;
	case Scene::SHOP:
		RenderShop(state);
		break;
	case Scene::UPGRADE:
		RenderUpgrade(state);
		break;
	case Scene::BATTLE:
		RenderBattle(state);
		break;
	case Scene::GAMEOVER:
		RenderGameOver(state);
		break;
	}
}
