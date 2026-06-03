#include "Game.h"
#include "console.h"
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

	/*if (GetKeyDown(VK_ESCAPE))
		state.isRunning = false;*/
	/*switch (state.curScene)
	{
	case Scene::TITLE:
		if (sceneChanged)
			InitTitle(state);
		UpdateTitle(state);
		break;
	case Scene::INGAME:
		if (sceneChanged)
			InitInGame(state);
		UpdateInGame(state);

		break;
	case Scene::INFO:
		UpdateInfo(state);
		break;
	case Scene::GAMEOVER:
		break;
	}*/
}

void Renderer(const GameState& state)
{
	if (state.prevScene != state.curScene)
		system("cls");
	GotoXY(0, 0);

	/*switch (state.curScene)
	{
	case Scene::TITLE:
		RenderTitle(state);
		break;
	case Scene::INGAME:
		RenderInGame(state);
		break;
	case Scene::INFO:
		RenderInfo(state);
		break;
	case Scene::GAMEOVER:
		break;
	}*/
}
