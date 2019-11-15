#include "ULT.h"
#include "GameManager.h"


ULT::ULT()
{
}


ULT::~ULT()
{
}

void ULT::Init()
{
	s_ = 1;
	v_ = 1;
	h_ = 275;
	ultwords_img = GameManager::Instance().GetUltWords();
	energybar_img = GameManager::Instance().GetEnergyBar();
	energy = 0;
	IsHit = false;
}
void ULT::Update()
{
	ColorControl();
	hsv = HSV(h_, s_, v_);
	ultwords_img.drawAt(650, 450, hsv);
	
	for (int i= 0; i < energy; i++)
	{
		Rect(710+18*i,434,16,32).draw(Palette::Blue);
	}
	energybar_img.drawAt(800, 450);
	Charge(IsHit);
	
}
void ULT::Exit()
{

}
void ULT::ColorControl()
{
	

	if (energy >= 10)
	{
		energy = 10;
		h_ += 10;
		s_ -= 0.02f;

		if (s_ <= 0) s_ = 1;
		if (h_ >= 360)h_ = 0;
	}
	else if (energy < 10)
	{
		s_ = 1;
		v_ = 1;
		h_ = 275;
	}
}
void ULT::Charge(bool flag)
{
	if (flag)
	{
		energy += 1;
		flag = false;
	}
}