#pragma once
#include "GameState.h"
#include "SceneState.h"
#include "UpgradeAsciiArt.h"

enum class AnimState { NONE, SLIDE_DOWN, SLIDE_UP, EXPLODE };

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
    void RenderAnim()    const; 
    void StartAnim();       
    void RenderStored() const;

private:
    PMSAsciiObjs  asciiObjs;
    UpgradeResult lastResult = UpgradeResult::SUCCESS;
    bool          hasResult = false;

    bool          skipAnim = false;       
    AnimState     animState = AnimState::NONE;
    ULONGLONG     animStart = 0;
    int           prevTier = 0;           
};