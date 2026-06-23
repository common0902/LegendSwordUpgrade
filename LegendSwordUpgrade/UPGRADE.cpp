#include "UPGRADE.h"
#include "Console.h"

constexpr int INFO_BOX_X = 2;
constexpr int INFO_BOX_Y = 10;
constexpr int INFO_BOX_W = 24;
constexpr int INFO_BOX_H = 12;

constexpr int CTRL_BOX_X = WIDTH - 28;
constexpr int CTRL_BOX_Y = 10;
constexpr int CTRL_BOX_W = 26;
constexpr int CTRL_BOX_H = 9;

constexpr int SLIDE_DURATION_MS = 500; // 슬라이드 시간
constexpr int EXPLODE_DURATION_MS = 500; // 폭발 대기 시간 (화면 흔들림과 맞춤)

void UpgradeScene::Enter()
{
    PMSAsciiInit(asciiObjs);
    hasResult = false;
    animState = AnimState::NONE;
    system("cls");
}

void UpgradeScene::StartAnim()
{
    if (skipAnim)
    {
        animState = AnimState::NONE;
        return;
    }

    animStart = GetTickCount64();

    if (lastResult == UpgradeResult::SUCCESS)
        animState = AnimState::SLIDE_DOWN;
    else if (lastResult == UpgradeResult::DOWN)
        animState = AnimState::SLIDE_UP;
    else // BREAK
        animState = AnimState::EXPLODE;
}

void UpgradeScene::RenderStored() const
{
    int sx = WIDTH - 28;
    int sy = 1;

    SetColor(Color::WHITE);
    GotoXY(sx, sy);
    cout << "보관 중인 검";

    DrawBox(sx, sy + 1, 26, 4);

    int tx = sx + 2;
    int ty = sy + 2;

    if (state.PmsData.hasStored)
    {
        SetColor(Color::LIGHT_GREEN);
        GotoXY(tx, ty);
        cout << "+" << state.PmsData.storedTier << " "
            << GetSwordName(state.PmsData.storedTier);
        GotoXY(tx, ty + 1);
        cout << "공격력: " << state.PmsData.storedDamage << "   ";
    }
    else
    {
        SetColor(Color::GRAY);
        GotoXY(tx, ty);
        cout << "(비어 있음)        ";
        GotoXY(tx, ty + 1);
        cout << "                   ";
    }
    SetColor();
}

void UpgradeScene::Update()
{
    if (GetKeyDown('T'))
        skipAnim = !skipAnim;

    if (animState != AnimState::NONE)
    {
        ULONGLONG elapsed = GetTickCount64() - animStart;
        int duration = (animState == AnimState::EXPLODE)
            ? EXPLODE_DURATION_MS : SLIDE_DURATION_MS;

        if (GetKeyDown('T') || elapsed >= duration)
        {
            animState = AnimState::NONE;
            ClearSwordArea(); 
        }
        return; 
    }

    if (GetKeyDown(VK_ESCAPE))
    {
        state.fsm.ChangeState((int)Scene::TITLE);
        return;
    }

    if (GetKeyDown(VK_RETURN))
    {
        if (state.curSword.IsMaxTier())              return;
        if (state.gold < state.curSword.upgradeCost) return;

        prevTier = state.curSword.tier;
        state.gold -= state.curSword.upgradeCost;
        lastResult = state.curSword.TryUpgrade();
        hasResult = true;

        if (lastResult == UpgradeResult::BREAK)
            ShakeConsoleWindow(8, 400, 30);

        StartAnim();
    }

    if (GetKeyDown('S'))
    {
        state.gold += state.curSword.GetSellCost();
        state.curSword = Sword{};
        hasResult = false;
        system("cls");
    }

    if (GetKeyDown('B'))
    {
        state.PmsData.storedDamage = state.curSword.damage;
        state.PmsData.storedTier = state.curSword.tier;
        state.PmsData.hasStored = true;

        state.curSword = Sword{};
        system("cls");
    }
}

void UpgradeScene::Render() const
{
    Sword& sw = state.curSword;

    RenderTitle(2, 1);

    string name = "+" + std::to_string(sw.tier) + "  " + GetSwordName(sw.tier);
    int nameX = WIDTH / 2 - (int)name.size() / 2;
    SetColor(Color::WHITE);
    GotoXY(nameX, 2);
    cout << name << "     ";

    if (animState != AnimState::NONE)
        RenderAnim();
    else
        PMSAsciiRender(asciiObjs, sw.tier);

    SetColor(Color::YELLOW);
    GotoXY(INFO_BOX_X, INFO_BOX_Y + INFO_BOX_H + 1);
    cout << "골드: " << state.gold << "G     ";

    RenderInfo();
    RenderControl();
    RenderStored();
    RenderResult();
}

void UpgradeScene::RenderAnim() const
{
    ULONGLONG elapsed = GetTickCount64() - animStart;

    if (animState == AnimState::SLIDE_DOWN)
    {
        float t = (float)elapsed / SLIDE_DURATION_MS;
        if (t > 1.0f) t = 1.0f;
        int offsetY = (int)(SWORD_HEIGHT * t);
        PMSAsciiRenderTwoSlide(asciiObjs, prevTier, state.curSword.tier, offsetY, true);
    }
    else if (animState == AnimState::SLIDE_UP)
    {
        float t = (float)elapsed / SLIDE_DURATION_MS;
        if (t > 1.0f) t = 1.0f;
        int offsetY = (int)(SWORD_HEIGHT * t);
        PMSAsciiRenderTwoSlide(asciiObjs, prevTier, state.curSword.tier, offsetY, false);
    }
    else if (animState == AnimState::EXPLODE)
    {
        PMSAsciiRenderExplosion(asciiObjs);
    }

    RenderTitle(2, 1);
}

void UpgradeScene::RenderInfo() const
{
    Sword& sw = state.curSword;

    SetColor(Color::WHITE);
    GotoXY(INFO_BOX_X + 1, INFO_BOX_Y - 1);
    cout << "검 정보";

    DrawBox(INFO_BOX_X, INFO_BOX_Y, INFO_BOX_W, INFO_BOX_H);

    int tx = INFO_BOX_X + 2;
    int ty = INFO_BOX_Y + 1;

    SetColor(Color::WHITE);
    GotoXY(tx, ty);
    cout << "공격력  : " << sw.damage << "      ";

    GotoXY(tx, ty + 2);
    cout << "강화비용: " << sw.upgradeCost << "   ";
    GotoXY(tx, ty + 3);
    cout << "판매비용: " << sw.GetSellCost() << "   ";

    SetColor(Color::LIGHT_GREEN);
    GotoXY(tx, ty + 5);
    cout << "성공확률: " << (int)sw.GetSuccessChance() << "%   ";
    SetColor(Color::LIGHT_YELLOW);
    GotoXY(tx, ty + 6);
    cout << "하락확률: " << (int)sw.GetDownChance() << "%   ";
    SetColor(Color::LIGHT_RED);
    GotoXY(tx, ty + 7);
    cout << "파괴확률: " << (int)sw.GetBreakChance() << "%   ";

    SetColor(Color::LIGHT_RED);
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
    SetColor(Color::WHITE);
    GotoXY(CTRL_BOX_X + 1, CTRL_BOX_Y - 1);
    cout << "조작";

    DrawBox(CTRL_BOX_X, CTRL_BOX_Y, CTRL_BOX_W, CTRL_BOX_H);

    int tx = CTRL_BOX_X + 2;
    int ty = CTRL_BOX_Y + 1;

    SetColor(Color::WHITE);
    GotoXY(tx, ty);     cout << "[ENTER] 강화하기";
    GotoXY(tx, ty + 1); cout << "[S]     판매하기";
    GotoXY(tx, ty + 2); cout << "[B]     보관하기";
    GotoXY(tx, ty + 3); cout << "[ESC]   돌아가기";
    GotoXY(tx, ty + 4);
    if (skipAnim)
    {
        SetColor(Color::LIGHT_RED);
        cout << "[T]     스킵 ON ";
    }
    else
    {
        SetColor(Color::LIGHT_GREEN);
        cout << "[T]     스킵 OFF";
    }
}

void UpgradeScene::RenderResult() const
{
    if (!hasResult) return;

    int rx = CTRL_BOX_X + 2;
    int ry = CTRL_BOX_Y + CTRL_BOX_H + 1;

    GotoXY(rx, ry);
    switch (lastResult)
    {
    case UpgradeResult::SUCCESS:
        SetColor(Color::LIGHT_GREEN);
        cout << "★ 강화 성공! +" << state.curSword.tier << " ★      ";
        break;
    case UpgradeResult::DOWN:
        SetColor(Color::LIGHT_YELLOW);
        cout << "▼ 강화 실패 (단계 하락) ";
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