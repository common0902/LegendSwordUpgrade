#include "BATTLE.h"

#define NextLine cout << "\n";

Vector2 BaseUIPos = { 120,5 };
Vector2 swordImageMaxSize = { swordImageWidth ,swordImageHeigth };
Vector2 screenCenter = { WIDTH /2,HEIGHT/2};

#pragma region BattleSceneMethod

#pragma region BattleSceneFsm

void BattleScene::Init()
{
	fsm.AddState(BattleSceneEnum::Stage, new BattleSceneStageState(*this));
	fsm.AddState(BattleSceneEnum::Battle, new BattleSceneBattleState(*this));
}

void BattleScene::Enter()
{
	CLS();
	fsm.ChangeState(BattleSceneEnum::Stage);
}

void BattleScene::Update()
{
	SkipBreak();
	fsm.Update();
}

void BattleScene::Render() const
{
	fsm.Render();
}

void BattleScene::Exit()
{
	CLS();
}

#pragma endregion

#pragma region Setting

void BattleScene::StatSetting()
{
	curSwordImage = TestSwordImage;
	state.player.MaxHp = 10;
	curPlayerHp = state.player.MaxHp;
	curDamage = 10;
	swordName = "리우 짱짱 검";
}

#pragma endregion

#pragma region Draw

void BattleScene::DrawBaseUI() const
{
	DrawPlayerStat();
	DrawCurrentSword();
}

void BattleScene::DrawPlayerStat() const
{
	GotoXY(BaseUIPos + Vector2(2,2));
	cout << "체력 : " << GetIntString(curPlayerHp) << "/" << GetIntString(state.player.MaxHp) << "        ";
	
	GotoXY(BaseUIPos + Vector2(2,3));
	SetColor(GetHealthColor(curPlayerHp, state.player.MaxHp));
	cout << GetBarString(curPlayerHp, state.player.MaxHp, 10);
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

#pragma endregion

#pragma region Phase

int BattleScene::GetMaxPhase(int stage) const
{


	return stage * 5;
}

void BattleScene::ChangeScene(int scene)
{
	fsm.Exit();
	state.fsm.ChangeState(scene);
}

void BattleScene::ChangeState(BattleSceneEnum state)
{
	fsm.ChangeState(state);
}

#pragma endregion

#pragma endregion

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

bool IsGotoXY(Vector2 pos)
{
	return IsGotoXY(pos.x,pos.y);
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
	DrawImage(image, pos, Vector2(static_cast<int>(image[0].length()), static_cast<int>(image.size())));
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

void SkipBreak()
{
	while (_kbhit())
	{
		_getch();
	}
}

void CanSkipSleep(int delay)
{
	int count = delay / 10;
	for (int i = 0;i < count;++i) {
		if (_kbhit()) break;
		else Sleep(10);
	}
}

void Typing(string text, int delay,bool endl)
{
	int size = static_cast<int>(text.size());
	for (int i = 0;i < size;++i)
	{
		cout << text[i];
		CanSkipSleep(delay);
	}
	if (endl) cout << "\n";
}

void ScreenReset()
{
	DrawImage(ScreenResetText, Vector2{ 0, 0 });
	GotoXY(0, 0);
}

void WaitInput()
{
	SkipBreak();
	_getch();
	_kbhit();
}

int GetIntInput(int min, int max)
{
	int input;
	while (true)
	{
		cin >> input;
		if (cin.fail() || input < min || input > max)
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "잘못된 입력입니다.\n" << min << "~"
				<< max << "사이 숫자를 입력하세요.\n";
			continue;
		}
		else
			return input;
	}
}

bool InputYorN()
{
	string input;
	bool b;
	while (true)
	{
		cin >> input;
		if (input == "Y" || input == "y")
		{
			b = true;
			break;
		}
		else if (input == "N" || input == "n")
		{
			b = false;
			break;
		}
		else {
			cout << "잘못된 입력입니다.\n";
		}
	}
	SkipBreak();
	return b;
}

string ToString(int value)
{
	return std::to_string(value);
}

void CLS()
{
	system("cls");
}

bool IsNumder(const string text)
{
	if (text.empty()) return false;

	for (char t : text) {
		if (t < '0' || t > '9') return false;
	}

	return true;
}

int ToInt(const string text)
{
	return std::stoi(text);
}

Vector2 GetMousePos()
{
	POINT point = GetMouseCellPos();
	return Vector2{point.x,point.y};
}

Vector2 GetSize(vector<wstring> image)
{
	return Vector2(static_cast<int>(image[0].length()), static_cast<int>(image.size())) + Vector2(-1,-1);
}

bool IsMouseUp(Vector2 leftUpPos, Vector2 rightDownPos)
{
	Vector2 pos = GetMousePos();

	if (leftUpPos.x > pos.x || pos.x > rightDownPos.x) return false;
	if (leftUpPos.y > pos.y || pos.y > rightDownPos.y) return false;

	return true;
}

bool IsMouseUp(Vector2 leftUpPos, vector<wstring> image)
{
	return IsMouseUp(leftUpPos, leftUpPos + GetSize(image));
}

bool IsButtonClick(Vector2 leftUpPos, Vector2 rightDownPos)
{
	if (!GetMouseDown(MouseButton::LEFT)) return false;

	return IsMouseUp(leftUpPos, rightDownPos);
}

bool IsButtonClick(Vector2 leftUpPos, vector<wstring> image)
{
	return IsButtonClick(leftUpPos, leftUpPos + GetSize(image));
}

bool DelayButton(Vector2 leftPos, vector<wstring> image,
	int type , ULONGLONG delay)
{
	return IsButtonClick(leftPos,image) && Delay(type,delay);
}

void BoolReverse(bool& value)
{
	value = !value;
}


#pragma endregion



