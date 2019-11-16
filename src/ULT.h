#pragma once
#include "define.h"
class ULT
{
	Texture ultwords_img;
	Texture energybar_img;
	HSV hsv;
	double s_;
	double v_;
	int h_;
	


public:

	int energy;
	

	ULT();
	~ULT();
	void Init();
	void Update();
	void Exit();
	

	void ColorControl();
};

