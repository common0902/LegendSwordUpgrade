#include"NormalBattleMapState.h"
#include "BATTLE.h"

void NormalBattleState::Enter()
{
	


	
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

