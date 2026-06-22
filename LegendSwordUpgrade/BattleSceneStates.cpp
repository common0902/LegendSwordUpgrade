#include"BattleSceneStates.h"
#include"BATTLE.h"

#pragma region BattleSceneStageState

void BattleSceneStageState::Enter()
{
	SkipBreak();
	Typing("스테이지를 선택해 주세요.\n",10);

	for (int i = 1;i <= scene.maxStage;++i)
	{
		Typing(ToString(i) + " ", 10,false);
		if (i > scene.maxStage) SetColor(Color::RED);
		else SetColor();
	}
	SkipBreak();

}

void BattleSceneStageState::Update()
{

}

void BattleSceneStageState::Render() const
{


}

void BattleSceneStageState::Exit()
{


}

#pragma endregion

#pragma region BattleSceneBattleState

void BattleSceneBattleState::Enter()
{


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


