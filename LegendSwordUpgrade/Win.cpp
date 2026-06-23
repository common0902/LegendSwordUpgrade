#include "Win.h"

void WinScene::Enter()
{
	GotoXY(75, 25);
	SetColor();
	cout << "클리어!";
}

void WinScene::Update()
{
}

void WinScene::Render() const
{
}

void WinScene::Exit()
{
}
