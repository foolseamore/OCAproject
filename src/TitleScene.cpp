#include "TitleScene.h"
#include "GameManager.h"


TitleScene::TitleScene()
{
}


TitleScene::~TitleScene()
{
}

void TitleScene::Init()
{
	title_img = GameManager::Instance().GetTitle();
	bg_img = GameManager::Instance().GetBg();
	start_img = GameManager::Instance().GetStart();
	exit_img = GameManager::Instance().GetExit();
	select_img = GameManager::Instance().GetEarthHp();
	
}

void TitleScene::Update()
{
	Print << U"TitleScene";
	bg_img.draw();
	start_img.drawAt(WINDOW_W / 2, 500);
	exit_img.drawAt(WINDOW_W / 2, 600);
	title_img.drawAt(WINDOW_W / 2, 300);
}
void TitleScene::Exit()
{

}