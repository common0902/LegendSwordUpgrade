#pragma once
#include "GameState.h"
#include "SceneState.h"
#include "UpgradeAsciiArt.h"

class UpgradeScene : public SceneState
{
public:
    UpgradeScene(GameState& gameState) : SceneState(gameState) {}
    void Enter()        override;
    void Update()       override;
    void Render() const override;
    void Exit()         override;

private:
    void RenderInfo()    const;
    void RenderControl() const;
    void RenderResult()  const;

private:
    PMSAsciiObjs  asciiObjs;
    UpgradeResult lastResult = UpgradeResult::SUCCESS;
    bool          hasResult = false;
    ULONGLONG     resultTime = 0;
};