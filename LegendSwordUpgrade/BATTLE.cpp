#include "BATTLE.h"
#include "NormalBattleMapState.h"
#include "EnemyBattleState.h"


Vector2 BaseUIPos = { 120,5 };
Vector2 swordImageMaxSize = { swordImageWidth ,swordImageHeigth };

void BattleScene::Enter()
{
	system("cls");

	StatSetting();
	
	DrawImage(BaseBattleUI, BaseUIPos);
	BaseUI();

	BattelSceneFsm.AddState((int)InBattleState::Normal, new NormalBattleState(*this));
	BattelSceneFsm.AddState((int)InBattleState::EnemyBattle, new EnemyBattleState(*this));
	
	BattelSceneFsm.ChangeState((int)InBattleState::Normal);
}

void BattleScene::StatSetting()
{
	curSwordImage = TestSwordImage;
	state.player.maxHp = 1000000;
	curPlayerHp = state.player.maxHp;
	curDamage = 10;
	swordName = "리우 짱짱 검";
}

void BattleScene::Update()
{
	BattelSceneFsm.Update();
	if (curPlayerHp <= 0)
	{
		state.fsm.ChangeState((int)Scene::GAMEOVER);
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
	cout << "공격력 : " << GetIntString(curDamage) << "    ";
}

void BattleScene::DrawCurrentSword() const
{
	DrawImage(curSwordImage, BaseUIPos + Vector2{ 2,7 }, swordImageMaxSize);

	GotoXY(BaseUIPos + Vector2{ 1, 23 });
	string swordText = "현재 검 : " + swordName;
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

string GetBarString(int value, int maxValue, int barWidth, const string& fillChar, const string& emptyChar)
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
	while (value >= 1000)
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

void Typing(string text, int delay,bool endl)
{
	int size = static_cast<int>(text.size());
	for (int i = 0;i < size;++i)
	{
		Sleep(delay);
		cout << text[i];
	}
	if (endl) cout << "\n";
}

void ScreenReset()
{
	DrawImage(ScreenResetText, Vector2{ 0, 1 });
}

void WaitInput()
{
	while (_kbhit())
	{
		_getch();
	}
	_getch();
}

int GetValidInput(int min, int max)
{
	int input;
	while (true)
	{
		cin >> input;
		if (cin.fail() || input < min || input > max)
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "잘못된 입력입니다. " << min << "~"
				<< max << "사이 숫자를 입력하세요. " << endl;
			continue;
		}
		else
			return input;
	}
}
#pragma endregion

