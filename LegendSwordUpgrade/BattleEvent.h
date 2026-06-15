#pragma once

class BattleScene;

class BattleEvent
{
public:
	BattleScene& battleScene;
public:
	BattleEvent(BattleScene& scene) : battleScene(scene)
	{

	}
	virtual ~BattleEvent() = default;

public:
	virtual void Start() abstract;
};