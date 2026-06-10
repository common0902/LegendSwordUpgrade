#include"NormalBattleMapState.h"
#include "BATTLE.h"


void NormalBattleMapState::Enter()
{
	


}

void NormalBattleMapState::Update()
{
	

	
}

void NormalBattleMapState::Render() const
{


}

void NormalBattleMapState::Exit()
{


}

Vector2 NormalBattleMapState::GetMoveDir()
{
	Vector2 vec2 = Vector2{ 0,0 };
	if (GetKey('W')) vec2.y -= 1;
	if (GetKey('S')) vec2.y += 1;
	if (GetKey('A')) vec2.x -= 1;
	if (GetKey('D')) vec2.x += 1;
	return vec2;
}
