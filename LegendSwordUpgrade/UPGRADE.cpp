#include "UPGRADE.h"
#include "Console.h"

constexpr int RESULT_DISPLAY_MS = 1500;

// 검 정보 박스 위치/크기
constexpr int INFO_BOX_X = 2;
constexpr int INFO_BOX_Y = 10;
constexpr int INFO_BOX_W = 24;
constexpr int INFO_BOX_H = 12;

// 조작 박스 위치/크기
constexpr int CTRL_BOX_X = WIDTH - 28;
constexpr int CTRL_BOX_Y = 10;
constexpr int CTRL_BOX_W = 26;
constexpr int CTRL_BOX_H = 7;

void FillWhiteBackground()
{
    SetColor(Color::BLACK, Color::WHITE);
    COORD res = GetConsoleResolution();
    for (int y = 0; y < res.Y; ++y)
    {
        GotoXY(0, y);
        for (int x = 0; x < res.X; ++x)
            cout << " ";
    }
}

void UpgradeScene::Enter()
{
    PMSAsciiInit(asciiObjs);
    hasResult = false;
    system("cls");
    FillWhiteBackground();
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
        if (state.curSword.IsMaxTier())              return;
        if (state.gold < state.curSword.upgradeCost) return;

        state.gold -= state.curSword.upgradeCost;
        lastResult = state.curSword.TryUpgrade();
        hasResult = true;
        resultTime = GetTickCount64();

        if (lastResult == UpgradeResult::BREAK)
            ShakeConsoleWindow(8, 400, 30);
    }

    if (GetKeyDown('S'))
    {
        state.gold += state.curSword.GetSellCost();
        state.curSword = Sword{};
        hasResult = false;
        FillWhiteBackground();
    }
}

void UpgradeScene::Render() const
{
    Sword& sw = state.curSword;

    SetColor(Color::BLACK, Color::WHITE);
    GotoXY(2, 1);
    cout << " _  _  _  _  _  _  _  _  _  _ ";
    GotoXY(2, 2);
    cout << "| |/ /  / _|| __|  / _|| || ||_|";
    GotoXY(2, 3);
    cout << "| / /  | |_ | _|  | |_ | __ | _ ";
    GotoXY(2, 4);
    cout << "|_|\\_\\  \\__||___|  \\__||_||_||_|";

    string name = "+" + std::to_string(sw.tier) + "  " + GetSwordName(sw.tier);
    int nameX = WIDTH / 2 - (int)name.size() / 2;
    SetColor(Color::BLACK, Color::WHITE);
    GotoXY(nameX, 2);
    cout << name << "     ";

    PMSAsciiRender(asciiObjs, sw.tier);

    SetColor(Color::BLACK, Color::WHITE);
    GotoXY(INFO_BOX_X, INFO_BOX_Y + INFO_BOX_H + 1);
    cout << "골드: " << state.gold << "G     ";

    RenderInfo();
    RenderControl();
    RenderResult();
}

void UpgradeScene::RenderInfo() const
{
    Sword& sw = state.curSword;

    SetColor(Color::BLACK, Color::WHITE);
    GotoXY(INFO_BOX_X + 1, INFO_BOX_Y - 1);
    cout << "검 정보";

    DrawBox(INFO_BOX_X, INFO_BOX_Y, INFO_BOX_W, INFO_BOX_H);

    int tx = INFO_BOX_X + 2;
    int ty = INFO_BOX_Y + 1;

    SetColor(Color::BLACK, Color::WHITE);
    GotoXY(tx, ty);
    cout << "공격력  : " << sw.damage << "      ";

    GotoXY(tx, ty + 2);
    cout << "강화비용: " << sw.upgradeCost << "   ";
    GotoXY(tx, ty + 3);
    cout << "판매비용: " << sw.GetSellCost() << "   ";

    SetColor(Color::LIGHT_GREEN, Color::WHITE);
    GotoXY(tx, ty + 5);
    cout << "성공확률: " << (int)sw.GetSuccessChance() << "%   ";
    SetColor(Color::LIGHT_YELLOW, Color::WHITE);
    GotoXY(tx, ty + 6);
    cout << "하락확률: " << (int)sw.GetDownChance() << "%   ";
    SetColor(Color::LIGHT_RED, Color::WHITE);
    GotoXY(tx, ty + 7);
    cout << "파괴확률: " << (int)sw.GetBreakChance() << "%   ";

    SetColor(Color::LIGHT_RED, Color::WHITE);
    GotoXY(tx, ty + 9);
    if (sw.IsMaxTier())
        cout << "최대 단계입니다!  ";
    else if (state.gold < sw.upgradeCost)
        cout << "골드가 부족합니다.";
    else
        cout << "                  ";
}

void UpgradeScene::RenderControl() const
{
    SetColor(Color::BLACK, Color::WHITE);
    GotoXY(CTRL_BOX_X + 1, CTRL_BOX_Y - 1);
    cout << "조작";

    DrawBox(CTRL_BOX_X, CTRL_BOX_Y, CTRL_BOX_W, CTRL_BOX_H);

    int tx = CTRL_BOX_X + 2;
    int ty = CTRL_BOX_Y + 1;

    SetColor(Color::BLACK, Color::WHITE);
    GotoXY(tx, ty);     cout << "[ENTER] 강화하기";
    GotoXY(tx, ty + 1); cout << "[S]     판매하기";
    GotoXY(tx, ty + 2); cout << "[ESC]   돌아가기";
}

void UpgradeScene::RenderResult() const
{
    if (!hasResult) return;

    bool showingResult = (GetTickCount64() - resultTime < RESULT_DISPLAY_MS);

    int rx = CTRL_BOX_X + 2;
    int ry = CTRL_BOX_Y + CTRL_BOX_H + 1;

    GotoXY(rx, ry);
    if (!showingResult)
    {
        SetColor(Color::BLACK, Color::WHITE);
        cout << "                        ";
        return;
    }

    switch (lastResult)
    {
    case UpgradeResult::SUCCESS:
        SetColor(Color::LIGHT_GREEN, Color::WHITE);
        cout << "★ 강화 성공! +" << state.curSword.tier << " ★";
        break;
    case UpgradeResult::DOWN:
        SetColor(Color::LIGHT_YELLOW, Color::WHITE);
        cout << "▼ 강화 실패 (단계 하락) ";
        break;
    case UpgradeResult::BREAK:
        SetColor(Color::LIGHT_RED, Color::WHITE);
        cout << "✖ 검이 파괴되었습니다...";
        break;
    }
    SetColor(Color::BLACK, Color::WHITE);
}

void UpgradeScene::Exit()
{
    SetColor(Color::WHITE, Color::BLACK);
    system("cls");
}