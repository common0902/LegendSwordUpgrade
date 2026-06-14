#include"EnemyBattleState.h"
#include "BATTLE.h"


void EnemyBattleState::Enter()
{
	curStage = battleScene.curState;

	ScreenReset();
	Typing("적을 만났다!", 100);


	WaitInput();


}

void EnemyBattleState::Update()
{
	



}

void EnemyBattleState::Render() const
{


}

void EnemyBattleState::Exit()
{


}
