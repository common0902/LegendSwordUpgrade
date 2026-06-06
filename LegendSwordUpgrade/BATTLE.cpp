#include "BATTLE.h"


void BattleScene::Enter()
{
	

	 

}

void BattleScene::Update()
{
	Vector2 vec2 = GetMoveDir();
	
	if (vec2 == Vector2{ 0,0 }) return;

	lastInput = GetTickCount64();

	state.LrwData.lastPlayerPos = state.LrwData.curPlayerPos;
	state.LrwData.curPlayerPos += vec2;


}

void BattleScene::Render() const
{


	GotoXY(state.LrwData.lastPlayerPos);
	cout << " ";


	GotoXY(state.LrwData.curPlayerPos);
	cout << "P";




}

void BattleScene::Exit()
{


	
}

Vector2 GetMoveDir()
{
	Vector2 vec2 = Vector2{ 0,0 };
	if (GetKey('W')) vec2.y -= 1;
	if (GetKey('S')) vec2.y += 1;
	if (GetKey('A')) vec2.x -= 1;
	if (GetKey('D')) vec2.x += 1;
	return vec2;
}

void GotoXY(Vector2 pos)
{
	GotoXY(pos.x, pos.y);
}

