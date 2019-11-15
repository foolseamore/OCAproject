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

	for (int i = 1; i < 4; i++)
	{
		g_time[i].pos.x = 640 + 38 * i;
		g_time[i].pos.y = 100;
	}
	g_time[0].pos.x = 740;
	g_time[0].pos.y = 60;
	g_time[0].cnt = 1;
	g_time[1].cnt = 1;
	g_time[2].cnt = 8;
	g_time[3].cnt = 0;
	frame_cnt = 0;
	scale_rate = 1.0f;
	scale_speed = 0.01f;
}

void TimeUI::Update()
{
	
	Calcu(g_time[1].cnt, g_time[2].cnt, g_time[3].cnt);
	Scale(scale_rate);
	scale_rate += scale_speed;
	time_img.scaled(scale_rate).drawAt(g_time[0].pos.x, g_time[0].pos.y);

	


	for (int i = 1; i < 4; i++)
	{
		if (ColorF(g_time[1].cnt, g_time[2].cnt))
		{
			number_img(38 * g_time[i].cnt, 0, 38, 38).draw(g_time[i].pos.x, g_time[i].pos.y, Palette::Red);
		}
		else
			number_img(38 * g_time[i].cnt, 0, 38, 38).draw(g_time[i].pos.x, g_time[i].pos.y);
	}

	frame_cnt++;

	if ((int)frame_cnt % 10 == 0)
	{
		g_time[3].cnt--;
	}
	for (int i = 3; i > 1; i--)
	{
		if (g_time[i].cnt < 0)
		{
			g_time[i].cnt = 9;
			g_time[i - 1].cnt--;
		}
	}
}

void TimeUI::Exit()
{

}
bool TimeUI::ColorF(int t1, int t2)
{
	if (t1 == 0 && t2 <= 2)
		return true;

	return false;
}
void TimeUI::Scale(double rate)
{

	
	if (rate <= 0.8f || rate >= 1.5f)
	{
		
		scale_speed *= -1;
	}
	
}
void TimeUI::Calcu(int t1, int t2,int t3)
{
	if (t1 == 0 && t2 == 9  && t3 == 0)
	{
		scale_speed = 0.025f;
	}
	else if (t1 == 0 && t2 == 3 && t3 == 0)
	{
		scale_speed = 0.05f;
	}

}
