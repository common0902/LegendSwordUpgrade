#include "UPGRADE.h"
#include "Console.h"

constexpr int RESULT_DISPLAY_MS = 1500;

void UpgradeScene::Enter()
{
    hasResult = false;
    system("cls");
}

void UpgradeScene::Update()
{
    if (GetKeyDown(VK_ESCAPE))
    {
        state.fsm.ChangeState((int)Scene::TITLE);
        return;
    }

    bool showingResult = hasResult &&
        (GetTickCount64() - resultTime < RESULT_DISPLAY_MS);
    if (showingResult) return;

    if (GetKeyDown(VK_RETURN))
    {
        if (state.curSword.IsMaxTier()) return;
        if (state.gold < state.curSword.upgradeCost) return;

        state.gold -= state.curSword.upgradeCost;
        lastResult = state.curSword.TryUpgrade();
        hasResult = true;
        resultTime = GetTickCount64();

        if (lastResult == UpgradeResult::BREAK)
            ShakeConsoleWindow(8, 400, 30);
    }
}

void UpgradeScene::Render() const
{
    Sword& sw = state.curSword;

    SetColor(Color::LIGHT_YELLOW);
    GotoXY(2, 1);  cout << "[ 강화 ]";

    SetColor(Color::YELLOW);
    GotoXY(2, 3);  cout << "골드: " << state.gold << "     ";

    SetColor(Color::WHITE);
    GotoXY(2, 5);  cout << "현재 강화 단계 : +" << sw.tier << "   ";
    GotoXY(2, 6);  cout << "공격력         : " << sw.damage << "   ";
    GotoXY(2, 7);  cout << "강화 비용      : " << sw.upgradeCost << "   ";

    SetColor(Color::LIGHT_GREEN);
    GotoXY(2, 9);  cout << "성공: " << (int)sw.GetSuccessChance() << "%   ";
    SetColor(Color::LIGHT_YELLOW);
    GotoXY(2, 10); cout << "하락: " << (int)sw.GetDownChance() << "%   ";
    SetColor(Color::LIGHT_RED);
    GotoXY(2, 11); cout << "파괴: " << (int)sw.GetBreakChance() << "%   ";

    SetColor(Color::LIGHT_GRAY);
    GotoXY(2, 13);
    if (sw.IsMaxTier())
        cout << "최대 강화 단계입니다!          ";
    else if (state.gold < sw.upgradeCost)
        cout << "골드가 부족합니다.             ";
    else
        cout << "[ENTER] 강화   [ESC] 돌아가기 ";

    RenderResult();
}

void UpgradeScene::RenderResult() const
{
    if (!hasResult) return;

    bool showingResult = (GetTickCount64() - resultTime < RESULT_DISPLAY_MS);

    GotoXY(2, 15);
    if (!showingResult)
    {
        cout << "                    ";
        return;
    }

    switch (lastResult)
    {
    case UpgradeResult::SUCCESS:
        SetColor(Color::LIGHT_GREEN);
        cout << "★ 강화 성공! +" << state.curSword.tier << " ★";
        break;
    case UpgradeResult::DOWN:
        SetColor(Color::LIGHT_YELLOW);
        cout << "▼ 강화 실패 (단계 하락)";
        break;
    case UpgradeResult::BREAK:
        SetColor(Color::LIGHT_RED);
        cout << "✖ 검이 파괴되었습니다...";
        break;
    }
    SetColor();
}

void UpgradeScene::Exit()
{
    system("cls");
}