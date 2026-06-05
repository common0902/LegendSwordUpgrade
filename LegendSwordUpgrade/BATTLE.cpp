#include "BATTLE.h"


Vector2 GetMoveDir();

void BattleScene::Enter()
{
	

	

}

void BattleScene::Update()
{
	Vector2 vec2 = GetMoveDir();
	
	if (vec2 == Vector2{ 0,0 }) return;





}

void BattleScene::Render() const
{



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
