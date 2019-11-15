//#include <Siv3D.hpp>
#include "GameMain.h"
//test

void Main()
{
	GameMain* game;
	
	game = new GameMain();

	game->Init();


	while (System::Update())
	{
		ClearPrint();
		game->Update();
	}

	game->Exit();

	delete game;
	game = 0;


}