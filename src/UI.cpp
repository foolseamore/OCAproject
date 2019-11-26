#include "UI.h"

#include"GameManager.h"

struct BaseObj
{
	int cnt;
	Point pos;
	Texture img;
};



BaseObj background[3];






UI::UI()
{
}


UI::~UI()
{
}

void UI::Init()
{
	//”wŒi‚Æ’n‹…
	background[0].img = GameManager::Instance().GetEarth();
	background[1].img = GameManager::Instance().GetGinnga();
	background[2].img = GameManager::Instance().GetGinnga();

	background[0].pos.x = 0;
	background[0].pos.y = 550;
	background[1].pos.x = 0;
	background[1].pos.y = 0;
	background[2].pos.x = 0;
	background[2].pos.y = -1500;

	
	
	//ŽžŠÔ
	timeUI = new TimeUI;
	timeUI->Init();
	////score
	//score = new Score;
	//score->Init();

}
void UI::Update()
{
	//”wŒi‚Æ’n‹…
	background[1].img.draw(background[1].pos.x, background[1].pos.y);
	background[2].img.draw(background[2].pos.x, background[2].pos.y);

	background[1].pos.y >= 1500 ? background[1].pos.y = -1499 : background[1].pos.y++;
	background[2].pos.y >= 1500 ? background[2].pos.y = -1499 : background[2].pos.y++;

	background[0].img.draw(background[0].pos.x, background[0].pos.y);
	
	
	
	//time
	timeUI->Update();
	//score
	//score->Update();


}
void UI::Exit()
{
	
	delete timeUI;
	//delete score;
	
}