#pragma once
#include "GameState.h"
constexpr int WIDTH = 160;
constexpr int HEIGHT = 45;

void Init(GameState& state);
void Update(GameState& state);
void Renderer(const GameState& state);

