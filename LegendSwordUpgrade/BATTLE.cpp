#include "BATTLE.h"
#include "NormalBattleMapState.h"
#include "EnemyBattleState.h"


Vector2 BaseUIPos = { 120,5 };
Vector2 swordImageMaxSize = { swordImageWidth ,swordImageHeigth };

void BattleScene::Enter()
{
	system("cls");

	state.player.maxHp = 1000000;

	curPlayerHp = state.player.maxHp;

	
	BattelSceneFsm.AddState((int)InBattleState::NormalBattleMap, new NormalBattleMapState(*this));
	BattelSceneFsm.AddState((int)InBattleState::EnemyBattle, new EnemyBattleState(*this));
	
	BattelSceneFsm.ChangeState((int)InBattleState::NormalBattleMap);


	DrawImage(BaseBattleUI, BaseUIPos);
}

void BattleScene::Update()
{

	BattelSceneFsm.Update();

	if (Delay(DelayType::TestType, 1000))
	{
		//curPlayerHp -= 1;
	}
}

void BattleScene::Render() const
{
	BaseUI();
	
	BattelSceneFsm.Render();




}

void BattleScene::Exit()
{
	system("cls");

	
}


void BattleScene::BaseUI() const
{
	
	DrawPlayerStat();
	DrawCurrentSword();
	
}

void BattleScene::DrawPlayerStat() const
{
	GotoXY(BaseUIPos + Vector2(2,2));
	cout << "체력 : " << GetIntString(curPlayerHp) << "/" << GetIntString(state.player.maxHp) << "        ";
	
	GotoXY(BaseUIPos + Vector2(2,3));
	SetColor(GetHealthColor(curPlayerHp, state.player.maxHp));
	cout << GetBarString(curPlayerHp, state.player.maxHp, 10);
	SetColor();

	GotoXY(BaseUIPos + Vector2(2,4));
	cout << "공격력 : " << curDamage;
}

void BattleScene::DrawCurrentSword() const
{
	//currentImage != nullptr ? currentImage->image : NullSwordImage;
	vector<wstring> image = NullSwordImage;
	DrawImage(image, BaseUIPos + Vector2{ 2,7 }, swordImageMaxSize);
	GotoXY(BaseUIPos + Vector2{ 1, 23 });
	string swordText = "현재 검 : 몰라";
	cout << CenterText(swordText, swordImageWidth);
	
	
}


#pragma region Method

ULONGLONG GetDeltaTime(ULONGLONG lastTime)
{
	return GetTickCount64() - lastTime;
}

bool Delay(int type,ULONGLONG delay)
{
	static std::map<int, ULONGLONG> lastTimeDict;
	if (lastTimeDict[type] == 0) lastTimeDict[type] = GetTickCount64();
	ULONGLONG delta = GetDeltaTime(lastTimeDict[type]);
	if (delta < delay) return false;
	lastTimeDict[type] = GetTickCount64();
	return true;
}

bool Delay(DelayType type, ULONGLONG time)
{
	return Delay((int)type,time);
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

void DrawImage(vector<wstring> image, int x, int y,int maxWIDTH,int maxHEIGHT)
{
	SetUnicodeMode();
	int size = (unsigned int)image.size();
	int minHEIGHT = size < maxHEIGHT ? size : maxHEIGHT;
	size = static_cast<int>(image[0].length());
	int minWIDTH = size < maxWIDTH ? size : maxWIDTH;;
	for (int i = 0;i < minHEIGHT;++i)
	{
		GotoXY(x, y + i);
		for (int j = 0;j < minWIDTH;++j)
		{
			wcout << image[i][j];
		}
	}
	SetDefaultMode();
}

void DrawImage(vector<wstring> image, Vector2 pos, Vector2 size){
	DrawImage(image, pos.x, pos.y, size.x, size.y);
}

void DrawImage(vector<wstring> image, Vector2 pos) {
	DrawImage(image, pos.x,pos.y, static_cast<int>(image[0].length()), static_cast<int>(image.size()));
}

Color GetHealthColor(int curHp,int maxHp)
{
	Color color;
	if (curHp > maxHp * 0.6f)
		color = Color::LIGHT_GREEN;
	else if (curHp > maxHp * 0.3f)
		color = Color::LIGHT_YELLOW;
	else
		color = Color::LIGHT_RED;

	return color;
}

string GetBarString(int value, int maxValue,
	int barWidth, const string& fillChar, const string& emptyChar)
{
	if (maxValue < 1) maxValue = 1;
	string text = "";
	int fillValue = barWidth * value / maxValue;
	for (int i = 0;i < barWidth;++i)
	{
		text += (i < fillValue ? fillChar : emptyChar);
	}
	return text;
}

string GetIntString(int value)
{
	int count = 0;
	while (value >= 10000)
	{
		value /= 1000;
		count += 1;
	}
	string text = std::to_string(value);
	if (count == 1) text += "K";
	else if (count == 2) text += "M";
	else if (count == 3) text += "B";
	return text;
}

string GetEmptyString(int size)
{
	return string(size, ' ');
}

string CenterText(string text, int size)
{
	int textSize = static_cast<int>(text.size());
	if (textSize > size) return text;
	int srartIndex = (size - textSize) / 2;
	string newText = GetEmptyString(size- textSize);
	newText.insert(srartIndex, text);
	return newText;
}

#pragma endregion