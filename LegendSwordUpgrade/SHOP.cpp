#include "Console.h"
#include "SHOP.h"

void ShopScene::Enter()
{
	//state.ChgData
	cout << "Shop";
	srand((unsigned int)time(nullptr));
	SetConsoleGameTitle(L"SHOP");
	slotMachine.Init(state);
	//SetConsoleSize(85, 40);
}
void ShopScene::Update()
{
	if (GetKeyDown(VK_ESCAPE))
	{
		state.fsm.ChangeState((int)Scene::TITLE);
		return;
	}


	if (GetKeyDown(VK_SPACE) && slotMachine.CanRoll())
	{
		if (state.gold >= 15)
			state.gold -= 15;
		else return;

		int p = rand() % 100 + 1;
		bool success = (p >= state.ChgData.failPercent) &&
			(p < state.ChgData.failPercent + state.ChgData.successPercent);
		bool super = (p >= state.ChgData.failPercent + state.ChgData.successPercent);
		slotMachine.StartRoll(success, super);
		GotoXY(0, 40);
		wcout << std::setw(3) << p;
	}

	RollResult result = slotMachine.ConsumeResult();
	if (!result.item.empty())
	{
		int getTotem = result.superSuccess ? 5 : 1;
		state.gold += result.superSuccess ? 1000 : 250;

		state.ChgData.haveTotem[result.item].first += getTotem;
		if (result.item == L"7")
		{
			for (auto iter = state.ChgData.haveTotem.begin(); iter != state.ChgData.haveTotem.end(); iter++)
			{
				iter->second.first += getTotem;
			}
			state.gold += 1000;
		}
		else if (result.item == L"$")
		{
			state.gold += 500;
		}

	}

	state.player.ApplyTotem(state.ChgData);   // 토템 개수 → Player 스탯 실시간 반영
	slotMachine.Update();
}

void ShopScene::Render() const
{
	slotMachine.Render();
}

void ShopScene::Exit()
{

}

