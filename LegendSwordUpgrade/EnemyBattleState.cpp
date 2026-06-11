#include"EnemyBattleState.h"
#include "BATTLE.h"


void EnemyBattleState::Enter()
{
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
