#include "BATTLE.h"



void BattleScene::Enter()
{
	curPlayerHp = state.player.maxHp;

	vector<string> image = { "12345","67890","24680","13579","12345" };
	curEnemy = new MoveEnemy(image, 100, 10);
	 

}

void BattleScene::Update()
{



}

void BattleScene::Render() const
{
	GotoXY(2, 2);
	cout << "플레이어 채력 : " << curPlayerHp << " | 적 체력 : " << curEnemy->hp;

	DrawEnemyImage(curEnemy, 2, 4);


}

void BattleScene::Exit()
{


	
}

void DrawEnemyImage(MoveEnemy* enemy, int x, int y)
{
	if (enemy == nullptr) return;
	vector<string> vec = enemy->image;
	int size = vec.size();
	for (int i = 0;i < size;++i)
	{
		GotoXY(x, y + i);
		cout << vec[i];
	}
}


ULONGLONG GetDeltaTime(ULONGLONG lastTime)
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

int GetRandomRange(int min, int max)
{
	int d = max - min;
	return rand() % d + min;
}

bool Random(int probability)
{
	return GetRandomRange(0, 100) < probability;
}


