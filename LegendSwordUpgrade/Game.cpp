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
	SetCursorVisible(false);

	state = GameState{};

	state.fsm.AddState((int)Scene::TITLE,new TitleScene(state));
	state.fsm.AddState((int)Scene::UPGRADE, new UpgradeScene(state));
	state.fsm.AddState((int)Scene::SHOP, new ShopScene(state));
	state.fsm.AddState((int)Scene::BATTLE, new BattleScene(state));
	state.fsm.AddState((int)Scene::GAMEOVER, new GameOverScene(state));


	state.fsm.ChangeState((int)Scene::TITLE);
}

void Update(GameState& state)
{
	UpdateInput();
	state.fsm.Update();
}

void Renderer(const GameState& state)
{
	state.fsm.Render();

}
