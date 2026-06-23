#pragma once
#include "GameState.h"
#include "console.h"
#include "Enums.h"
#include "SHOP.h"
#include "UPGRADE.h"
#include "BATTLE.h"
#include "Title.h"
#include "GameOver.h"
#include "Win.h"

void Init(GameState& state);
void Update(GameState& state);
void Renderer(const GameState& state);

