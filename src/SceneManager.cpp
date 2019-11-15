#include "SceneManager.h"
#include"TitleScene.h"
#include"PlayScene.h"
#include "UI.h"
#include "EndScene.h"


SceneManager::SceneManager()
{
	for (int i = 0; i < Scene_MAX; i++)
	{
		scene[i] = 0;
	}

}


SceneManager::~SceneManager()
{
}

void SceneManager::Init()
{
	scene[g_Title] = new TitleScene;
	scene[g_Title]->Init();
	scene[g_Game] = new PlayScene;
	scene[g_Game]->Init();
	scene[g_UI] = new UI;
	scene[g_UI]->Init();
	scene[g_End] = new EndScene;
	scene[g_End]->Init();
}

void SceneManager::Update(int gameState)
{
	switch (gameState)
	{
	case Title: 
		scene[g_Title]->Update();
		break;
	case Play:
		scene[g_UI]->Update();
		scene[g_Game]->Update();
		
		break;
	case End:
		scene[g_End]->Update();
		break;

	default: break;
	}
	
	

}

void SceneManager::Exit()
{
	for (int i = 0; i < Scene_MAX; i++)
	{
		scene[i]->Exit();
		delete scene[i];
		scene[i] = 0;
	}
}

