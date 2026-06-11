#pragma once
#include "GameState.h"
#include "UpgradeAsciiArt.h"

class UpgradeScene : public AbstractState
{
public:
    UpgradeScene(GameState& gameState) : AbstractState(gameState) {}
    void Enter() override;
    void Update() override;
    void Render() const override;
    void Exit() override;

private:
    void RenderResult() const;

private:
    PMSAsciiObjs  asciiObjs;
    UpgradeResult lastResult = UpgradeResult::SUCCESS;
    bool          hasResult = false;
    ULONGLONG     resultTime = 0;
};