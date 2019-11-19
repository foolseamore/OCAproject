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
	int energy;


public:

	
	

	ULT();
	~ULT();
	void Init();
	void Update();
	void Exit();
	
	void SetEnergy(int sete) { energy = sete; }
	int GetEnergy() { return energy; }

	void ColorControl();
};

