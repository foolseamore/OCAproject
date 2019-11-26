#include "Time.h"
#include"GameManager.h"


TimeUI::TimeUI()
{
}


TimeUI::~TimeUI()
{
}
void TimeUI::Init()
{
	time_img = GameManager::Instance().GetTime();
	number_img = GameManager::Instance().GetNumber();

	for (int i = 2; i >= 0; i--)
	{
		g_time[i].cnt = 0;
		g_time[i].pos.x = 754 - 38 * i;
		g_time[i].pos.y = 100;
	}

	frame_cnt = 0;
	scale_rate = 1.0f;
	scale_speed = 0.01f;
	Game_time = GameManager::Instance().GetTimes();
}

void TimeUI::Update()
{
	
	Game_time = GameManager::Instance().GetTimes();
	Decimal_Count(g_time, 3, Game_time);
	ScaleControl(Game_time,scale_rate);
	scale_rate += scale_speed;
	time_img.scaled(scale_rate).drawAt(740, 60);


	for (int i = 0; i < 3; i++)
	{
		if (ColorF(Game_time))
		{
			number_img(38 * g_time[i].cnt, 0, 38, 38).draw(g_time[i].pos.x, g_time[i].pos.y, Palette::Red);
		}
		else
			number_img(38 * g_time[i].cnt, 0, 38, 38).draw(g_time[i].pos.x, g_time[i].pos.y);
	}

	frame_cnt++;

	if ((int)frame_cnt % 60 == 0)
	{
		GameManager::Instance().SetTime(Game_time - 1);
	}

}

void TimeUI::Exit()
{

}
bool TimeUI::ColorF(int gtime)
{
	if (gtime<30)
		return true;

	return false;
}
void TimeUI::ScaleControl(int gtime,double rate)
{
	if (gtime == 90)
	{
		scale_speed = 0.025f;
	}
	else if (gtime == 30)
	{
		scale_speed = 0.05f;
	}

	if (rate <= 0.8f || rate >= 1.5f)
	{
		
		scale_speed *= -1;
	}
	
}

