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
	bool IsHit;

	ULT();
	~ULT();
	void Init();
	void Update();
	void Exit();
	void Charge(bool flag);

	void ColorControl();
};

