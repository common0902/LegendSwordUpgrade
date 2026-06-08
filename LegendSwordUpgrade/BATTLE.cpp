#include "BATTLE.h"


void BattleScene::Enter()
{


	 

}

void BattleScene::Update()
{

	static int p = 0;
	if (Delay(DelayType::EnemyType, 700))
	{
		GotoXY(15, p++);
		cout << "123";
	}
	if (Delay(DelayType::PlayerType, 1300))
	{
		GotoXY(15, p++);
		cout << "456";
	}
	if (Delay(DelayType::TestType, 750))
	{
		GotoXY(15, p++);
		cout << "789";
	}


}

void BattleScene::Render() const
{
	GotoXY(2, 2);
	cout << "플레이어 채력 : " << 




}

void BattleScene::Exit()
{


	
}



ULONGLONG BattleScene::GetDeltaTime(ULONGLONG lastTime)
{
	return GetTickCount64() - lastTime;
}

bool BattleScene::Delay(int type,ULONGLONG delay)
{
	ULONGLONG delta = GetDeltaTime(lastTimeMap[type]);
	if (delta < delay) return false;
	lastTimeMap[type] = GetTickCount64();
	return true;
}

bool BattleScene::Delay(DelayType type, ULONGLONG time)
{
	return Delay((int)type,time);
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