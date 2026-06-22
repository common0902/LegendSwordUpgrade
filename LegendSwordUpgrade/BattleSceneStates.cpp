#include "BattleSceneStates.h"
#include "BATTLE.h"

#pragma region Const

Vector2 NumderStartPos = Vector2{ 10,20 };
constexpr int NumderSpaing = 30;

Vector2 CancelImagePos = Vector2{ 125, 35 };

constexpr int FadeDelayTime = 1000;

#pragma endregion

#pragma region BattleSceneStageState
void BattleSceneStageState::Init()
{
	OnMouseStaageButton = new bool[scene.maxStage];
}
void BattleSceneStageState::Enter()
{
	SkipBreak();
	GotoXY(70, 10);
	cout << "스테이지를 선택해 주세요.";
}

void BattleSceneStageState::Update()
{
	Vector2 pos = NumderStartPos;
	for (int i = 0;i < scene.maxStage;++i)
	{
		OnMouseStaageButton[i] = IsMouseUp(pos, NumderImage[i]);
		if (OnMouseStaageButton[i] && GetMouseDown(MouseButton::LEFT)) StageChange(i + 1);
		pos.x += NumderSpaing;
	}

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
		SetColor(OnMouseStaageButton[i] ? Color::GRAY : Color::WHITE);
		DrawImage(NumderImage[i], pos);
		pos.x += NumderSpaing;
	}

	SetColor(isMouseCancelButton ? Color::RED : Color::WHITE);
	DrawImage(CancelImage, CancelImagePos);

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
	GotoXY(75, 40);
	cout << scene.curStage;
}

void BattleSceneBattleState::Update()
{

}

void BattleSceneBattleState::Render() const

{


}

void BattleSceneBattleState::Exit()
{


}

#pragma endregion


void CircleFade(int delay)
{
	Vector2 pos;
	string text = " ";

	int fadeFrameDelay = duration / WIDTH;

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
		Sleep(fadeFrameDelay);
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
		Sleep(fadeFrameDelay);
	}

}
