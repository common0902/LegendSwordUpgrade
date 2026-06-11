#include"NormalBattleMapState.h"
#include "BATTLE.h"

void NormalBattleState::Enter()
{
	ScreenReset();
	GotoXY(0, 0);
	string text1 = "현재 단계 : " + std::to_string(battleScene.stateLevel);
	Typing(text1, 100);

	Sleep(1000);

	Typing("적을 만났다!", 100);

	WaitInput();


	
	battleScene.BattelSceneFsm.ChangeState((int)InBattleState::EnemyBattle);


}

void NormalBattleState::Update()
{
	

	
}

void NormalBattleState::Render() const
{


}

void NormalBattleState::Exit()
{


}

