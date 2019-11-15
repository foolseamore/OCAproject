#pragma once
#include "define.h"
class TimeUI
{
	

	bool ColorF(int t1, int t2);
	void Scale(double rate);
	void Calcu(int t1, int t2,int t3);


	Texture number_img;
	Texture time_img;
	BaseData g_time[4];
	float frame_cnt;
	double scale_speed;
	double scale_rate;


public:
	TimeUI();
	~TimeUI();
	void Init();
	void Update();
	void Exit();
};

