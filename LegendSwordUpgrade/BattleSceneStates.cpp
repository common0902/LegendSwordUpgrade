#include"BattleSceneStates.h"
#include"BATTLE.h"

#pragma region Const

Vector2 NumderStartPos = Vector2{ 10,20 };
constexpr int NumderSpaing = 30;

Vector2 CancelImagePos = Vector2{ 125, 35 };

constexpr int FadeDurationTime = 2000;
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
	cout << "���������� ������ �ּ���.";
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
	CircleFade(FadeDurationTime,FadeDelayTime);
	CLS();
}

void BattleSceneStageState::StageChange(int stage)
{
	scene.curStage = stage;
	scene.ChangeState(BattleSceneEnum::Battle);
}

void BattleSceneStageState::CircleFade(int duration, int delay)
{
	Vector2 center = Vector2{ WIDTH, HEIGHT } / 2;

	int size = WIDTH / 2;

	if (size < HEIGHT / 2) size = HEIGHT / 2;

	int FadeFrameDelay = duration / size;

	Vector2 pos;
	string text = "&";



	Sleep(delay);


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

	cout << "123";
}

void BattleSceneBattleState::Render() const

{


}

void BattleSceneBattleState::Exit()
{


}

#pragma endregion


