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

Vector2 HealthBarPos = Vector2(30,5);
constexpr int PlayerHelathBarSize = 50;

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
		if (OnMouseStageButton[i] && GetMouseDown(MouseButton::LEFT)) StageChange(i + 1);
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

	playerCurHp = 20;
	playerMaxHp = 20;
}

void BattleSceneBattleState::Update()
{

}

void BattleSceneBattleState::Render() const
{
	string batText = GetBarString(playerCurHp, playerMaxHp, PlayerHelathBarSize);
	Color barColor = GetHealthColor(playerCurHp, playerMaxHp);

	GotoXY(HealthBarPos);
	SetColor(barColor);
	cout << batText;



}

void BattleSceneBattleState::Exit()
{
	CLS();

}

void BattleSceneBattleState::SetEnemyData()
{
	Enemy* a;

	vector<wstring> image = { L"123",L"13" };

	if (curStage == 1)
	{
		a = new Enemy(image, 100, 10);
	}
	else if (curStage == 2)
	{
		a = new Enemy(image, 200, 50);
	}
	else if (curStage == 3)
	{
		a = new Enemy(image, 300, 100);
	}
	else if (curStage == 4)
	{
		a = new Enemy(image, 500, 75);
	}
	else if (curStage == 5)
	{
		a = new Enemy(image, 1000, 200);
	}
	else a = new Enemy(image, 1, 1);
	
	delete enemy;

	enemy = a;
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
