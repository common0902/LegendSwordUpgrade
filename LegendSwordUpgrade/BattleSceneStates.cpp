#include "BattleSceneStates.h"
#include "BATTLE.h"
#include <Map>

#pragma region Const

#pragma region Stage

Vector2 NumderStartPos = Vector2{ 10,20 };
constexpr int NumderSpaing = 30;

Vector2 CancelImagePos = Vector2{ 125, 35 };

constexpr int FadeDelayTime = 1000;

#pragma endregion

#pragma region Battle

Vector2 NumderCountDownPos = Vector2(65, 15);

constexpr int StartBattleDelay = 1000;
constexpr int OneSecond = 1000;

Vector2 EnemyHealthBarPos = Vector2(30,2);
constexpr int EnemyHelathBarSize = 50;

Vector2 DefaultEnemyPos = Vector2(50, 5);

ULONGLONG DefaultAttackDelay = 1000;

ULONGLONG HitAfterTime = 100;

Vector2 AttackDelayVatPos = Vector2(60,40);
int AttackDelayBarSize = 20;

int AttackShakeDelay = 50;
int AttackShakePower = 50;
#pragma endregion

#pragma region Clear

Vector2 ClearTextPos = Vector2(70,25);
Vector2 ClearButtonPos = Vector2(65, 30);

#pragma endregion


#pragma endregion

#pragma region BattleSceneStageState

void BattleSceneStageState::Init()
{
	prevOnMouseStageButton = new bool[scene.maxStage];
	OnMouseStageButton = new bool[scene.maxStage];
}

void BattleSceneStageState::Enter()
{
	for (int i = 0;i < scene.maxStage;++i) {
	
		prevOnMouseStageButton[i] = true;
		OnMouseStageButton[i] = false;
	}
	prevIsMouseCancelButton = true;
	isMouseCancelButton = false;

	SkipBreak();
	GotoXY(70, 10);
	cout << "스테이지를 선택해 주세요.";
}

void BattleSceneStageState::Update()
{
	Vector2 pos = NumderStartPos;
	for (int i = 0;i < scene.maxStage;++i)
	{
		prevOnMouseStageButton[i] = OnMouseStageButton[i];
		OnMouseStageButton[i] = IsMouseUp(pos, NumderImage[i]);
		if (OnMouseStageButton[i] && GetMouseDown(MouseButton::LEFT))
		{
			StageChange(i + 1);
			return;
		}
		pos.x += NumderSpaing;
	}

	prevIsMouseCancelButton = isMouseCancelButton;
	isMouseCancelButton = IsMouseUp(CancelImagePos, CancelImage);
	if (isMouseCancelButton && GetMouseDown(MouseButton::LEFT))
	{
		scene.ChangeScene((int)Scene::TITLE);
		return;
	}
}

void BattleSceneStageState::Render() const
{
	SetColor();
	Vector2 pos = NumderStartPos;
	for (int i = 0;i < scene.maxStage;++i)
	{
		if (prevOnMouseStageButton[i] == OnMouseStageButton[i])
		{
			pos.x += NumderSpaing;
			continue;
		}
		SetColor(OnMouseStageButton[i] ? Color::GRAY : Color::WHITE);
		DrawImage(NumderImage[i], pos);
		pos.x += NumderSpaing;
	}
	
	if (prevIsMouseCancelButton != isMouseCancelButton)
	{
		SetColor(isMouseCancelButton ? Color::RED : Color::WHITE);
		DrawImage(CancelImage, CancelImagePos);
	}

}                               

void BattleSceneStageState::Exit()
{
	SetColor();
	CircleFade(FadeDelayTime);
	CLS();

}

void BattleSceneStageState::StageChange(int stage)
{
	scene.curStage = stage;
	scene.ChangeState(BattleSceneEnum::Battle);
}

#pragma endregion

#pragma region BattleSceneBattleState

void BattleSceneBattleState::Enter()
{
	curStage = scene.curStage;

	SetEnemyData();

	Sleep(StartBattleDelay);

	for (int i = 2;i >= 0;--i)
	{
		DrawImage(NumderImage[i], NumderCountDownPos);
		Sleep(OneSecond);
	}
	CLS();

}

void BattleSceneBattleState::Update()
{
	if (DelayButton(curEnemyDrawPos, enemy->image, DelayType::PlayerAttackDelay, DefaultAttackDelay / playerAttackSpeed))
	{
		SetAfterValue(BattleAfterType::EnemyHit, HitAfterTime);
		bool exit = false;
		PlayerAttack(playerDamage + 1, exit);
		if (exit) return;
		Render();
		ConsoleShake(AttackShakePower, AttackShakeDelay);
	}
	

}

void BattleSceneBattleState::Render() const
{

#pragma region EnemyHealth

	string barText = GetBarString(enemy->curHp, enemy->maxHp, EnemyHelathBarSize);
	Color barColor = GetHealthColor(enemy->curHp, enemy->maxHp);

	GotoXY(EnemyHealthBarPos);
	SetColor(barColor);
	cout << barText;

#pragma endregion

#pragma region EnemyName

	SetColor();
	GotoXY(EnemyHealthBarPos + Vector2(0, -1));
	string enemyNameText = CenterText(enemy->name, EnemyHelathBarSize * 2);
	cout << enemyNameText;

#pragma endregion

#pragma region EnemyImage

	SetColor(GetAfterValue(BattleAfterType::EnemyHit) ? Color::RED : Color::WHITE);
	DrawImage(enemy->image, curEnemyDrawPos);

#pragma endregion

#pragma region AttackDelay

	int AttackDelayDelte = static_cast<int>(GetDelayDeltaTime(DelayType::PlayerAttackDelay));
	int AttackDelay = static_cast<int>(DefaultAttackDelay / playerAttackSpeed);

	if (AttackDelayDelte > AttackDelay) AttackDelayDelte = AttackDelay;

	std::string AttackDelayText = GetAttackDelayBarString(AttackDelayDelte, AttackDelay, AttackDelayBarSize);

	GotoXY(AttackDelayVatPos);
	SetColor(Color::LIGHT_YELLOW);
	cout << AttackDelayText;

#pragma endregion

}

void BattleSceneBattleState::Exit()
{
	CLS();
}

void BattleSceneBattleState::SetEnemyData()
{

	delete enemy;

	Enemy* a;

	vector<wstring> image = EnemyImage[curStage-1];

	curEnemyDrawPos = DefaultEnemyPos;

	if (curStage == 1)
	{
		a = new Enemy("고블린", image, 100, 10, 1);
		curEnemyDrawPos += Vector2(0, 0);
	}
	else if (curStage == 2)
	{
		a = new Enemy("오크", image, 200, 50, 1);
		curEnemyDrawPos += Vector2(0, 5);
	}
	else if (curStage == 3)
	{
		a = new Enemy("암흑 마법사", image, 300, 100, 1);
		curEnemyDrawPos += Vector2(0, 0);
	}
	else if (curStage == 4)
	{
		a = new Enemy("골렘", image, 500, 75, 1);
		curEnemyDrawPos += Vector2(0, 0);
	}
	else if (curStage == 5)
	{
		a = new Enemy("거미", image, 1000, 200, 1);
		curEnemyDrawPos += Vector2(0, 0);
	}
	else a = new Enemy("애러", image, 1, 1, 1);

	enemy = a;
}

void BattleSceneBattleState::PlayerAttack(int damage,bool& exit)
{
	enemy->curHp -= damage;
	exit = false;

	if (enemy->curHp <= 0)
	{
		exit = true;
		scene.ChangeState(BattleSceneEnum::Clear);
		return;
	}


}

std::string BattleSceneBattleState::GetAttackDelayBarString(int value, int maxValue, int barWidth, string fillChar, string emptyChar) const
{
	if (maxValue < 1) maxValue = 1;
	if (barWidth < 1) return "";

	if (value < 0) value = 0;
	if (value > maxValue) value = maxValue;

	int fillValue = barWidth * value / maxValue;
	int startFill = (barWidth - fillValue) / 2;

	string text = "";

	for (int i = 0; i < barWidth; ++i)
	{
		if (i >= startFill && i < startFill + fillValue)
			text += fillChar;
		else
			text += emptyChar;
	}

	return text;
}

#pragma endregion

#pragma region BattleSceneClearState


void BattleSceneClearState::Enter()
{
	CircleFade(FadeDelayTime);

	GotoXY(ClearTextPos);
	Typing("스테이지 클리어!", 10);
}

void BattleSceneClearState::Update()
{
	if (IsButtonClick(ClearButtonPos, ClearButtonImage))
	{
		scene.ChangeScene((int)Scene::TITLE);
		return;
	}
}

void BattleSceneClearState::Render() const
{
	DrawImage(ClearButtonImage, ClearButtonPos);
}

void BattleSceneClearState::Exit()
{
	CLS();
}

#pragma endregion

#pragma region Method

void CircleFade(int delay)
{
	Vector2 pos;
	string text = " ";
	
	bool left;
	SetColor(Color::WHITE, Color::WHITE);
	for (int i = 0;i < WIDTH;++i)
	{
		left = true;
		for (int j = 0;j < HEIGHT;++j)
		{
			if (left) pos = Vector2(i, j);
			else pos = Vector2(WIDTH - i - 1, j);
			BoolReverse(left);
			GotoXY(pos);
			cout << text;
		}
	}
	
	Sleep(delay);

	SetColor();
	for (int i = 0;i < WIDTH;++i)
	{
		left = true;
		for (int j = 0;j < HEIGHT;++j)
		{
			if (left) pos = Vector2(i, j);
			else pos = Vector2(WIDTH - i - 1, j);
			BoolReverse(left);
			GotoXY(pos);
			cout << text;
		}
	}

}

#pragma endregion


