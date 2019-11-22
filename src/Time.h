#pragma once
#include "define.h"
#include "BaseScene.h"
class TimeUI:public BaseScene
{
	

	bool ColorF(int gtime);
	void ScaleControl(int gtime, double rate);
	


	Texture number_img;
	Texture time_img;
	BaseData g_time[3];
	float frame_cnt;
	double scale_speed;
	double scale_rate;

	int Game_time;


public:
	TimeUI();
	~TimeUI();
	void Init();
	void Update();
	void Exit();
};

