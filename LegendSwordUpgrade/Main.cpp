#include "Console.h"
#include "Game.h"
#include"GameState.h"

int main()
{
	srand((unsigned int)time(nullptr));

	GameState state;
	Init(state);

	while (true)
	{
		state.curTime = GetTickCount64();
		Update(state);
		Renderer(state);
		FrameSync(60);
	}	
}