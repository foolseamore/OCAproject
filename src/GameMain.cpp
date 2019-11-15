#include "GameMain.h"
#include "GameManager.h"


GameMain::GameMain()
{
	
}


GameMain::~GameMain()
{
}

void GameMain::Init()
{
	srand((unsigned int)time(NULL));
	Window::Resize(WINDOW_W, WINDOW_H);
	Window::SetTitle(U"�W���s�^�[��Ɖۑ�FBoard Defense");

	GameManager::Instance().Init();

	

}

void GameMain::Update()
{
	GameManager::Instance().Update();
	Print << U"FPS : "<<Profiler::FPS() ;
}

void GameMain::Exit()
{
	GameManager::Instance().Exit();
}