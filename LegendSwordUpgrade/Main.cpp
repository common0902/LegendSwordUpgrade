#include "Console.h"
#include "GameState.h"
#include "Game.h"

int main()
{
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